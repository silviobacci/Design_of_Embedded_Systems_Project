//------------------------------------------------------------------------------
// CODE: File that contains the main functions
//------------------------------------------------------------------------------

#include <stdio.h>
#include "debug.h"
#include "Event.h"
#include "ee.h"
#include "ee_irq.h"
#include "fonts.h"
#include "lcd_add.h"
#include "pictures.h"
#include "rtwtypes.h"
#include "stm32f4xx_conf.h"
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_lcd.h"
#include "stm32f4xx.h"
#include "STMPE811QTR.h"
#include "StopWatch2016.h"
#include "Touch.h"
#include "Widget.h"
#include "WidgetConfig.h"

//------------------------------------------------------------------------------
// GLOBAL CONSTANTS
//------------------------------------------------------------------------------

#define BLINK_TIME 5	// Time for which a text is visible/invisible (thents)

//------------------------------------------------------------------------------
// GLOBAL VARIABLES
//------------------------------------------------------------------------------

// Inputs, outputs and events of the model
boolean_T 	tick, button[7], hblink, mblink, alarmOn, ringing, alarmYellow,
			hour_visible, min_visible;
uint8_T 	hours, minutes, seconds, tenths, mode;

// Structures that represents the model
RT_MODEL_StopWatch2016_T 	SW_State;
PrevZCX_StopWatch2016_T 	prevZCSigState;
DW_StopWatch2016_T 			dwork;

//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// ISR2: 	Handler that counts the interrupts and wakes up the task that has
//			the counter equal to 0
//------------------------------------------------------------------------------

ISR2(systick_handler) {
	CounterTick(myCounter);
}

//------------------------------------------------------------------------------
// TASK LCD: 	Every 50 ms it checks if an event is arrived on the touchscreen.
// 				So if the user pressed a point of the screen this task
//				understands if a button was pressed. In that case the relative
//				event and the associated booelan are set to true.
//------------------------------------------------------------------------------

TASK(TaskLCD){
	static int i = 0;
	unsigned int px, py;
	TPoint p;

	if (GetTouch_SC_Async(&px, &py)) {
		p.x = px;
		p.y = py;
		OnTouch(MyWatchScr, &p);
	}
}

//------------------------------------------------------------------------------
// STR ENCODE 2 DIGIT: Converts the digit into into a string of 2 digits
//------------------------------------------------------------------------------

void strencode2digit(char *str, int digit){
	str[2] = 0;
	str[0] = digit / 10 + '0';
	str[1] = digit % 10 + '0';
}

//------------------------------------------------------------------------------
// STR ENCODE 1 DIGIT: Converts the digit into into a string of 1 digit
//------------------------------------------------------------------------------

void strencode1digit(char *str, int digit){
	str[1] = 0;
	str[0] = digit % 10 + '0';
}

//------------------------------------------------------------------------------
// UPDATE MODE: Updates the current mode and executes all the needed operations
//				when it changes the mode.
//------------------------------------------------------------------------------

void UpdateMode(unsigned char om, unsigned char m){
	char tstr[3];

	//--------------------------------------------------------------------------
	// We have to draw the "off" picture of the button of the previous mode.
	//--------------------------------------------------------------------------

	switch(om){
		case 0:
			DrawOff(&MyWatchScr[BTIME]);
			break;

		case 1:
			DrawOff(&MyWatchScr[BTIMESET]);

			//------------------------------------------------------------------
			// In time set mode hours and minutes blink and from now on hours
			// and the minutes will be visible.
			//------------------------------------------------------------------

			if(hour_visible == false){
				strencode2digit(tstr, hours);
				WPrint(&MyWatchScr[HRSSTR], tstr);
				hour_visible = true;
			}

			if(min_visible == false){
				strencode2digit(tstr, minutes);
				WPrint(&MyWatchScr[MINSTR], tstr);
				min_visible = true;
			}

			//------------------------------------------------------------------
			// If the new mode is time set mode we don't need to draw the second
			// separator otherwise we have to do it.
			//------------------------------------------------------------------

			if(mode != 2)
				WPrint(&MyWatchScr[SEP2STR], ":");

			break;

		case 2:
			DrawOff(&MyWatchScr[BALARM]);

			//------------------------------------------------------------------
			// In alarm mode hours and minutes blink and from now on hours
			// and the minutes will be visible.
			//------------------------------------------------------------------

			if(hour_visible == false){
				strencode2digit(tstr, hours);
				WPrint(&MyWatchScr[HRSSTR], tstr);
				hour_visible = true;
			}

			if(min_visible == false){
				strencode2digit(tstr, minutes);
				WPrint(&MyWatchScr[MINSTR], tstr);
				min_visible = true;
			}

			// We erase the button useful to switch ON/OFF the alarm.
			LCD_DrawPicture(135, 20, 50, 20, emptySpace);

			//------------------------------------------------------------------
			// If the new mode is alarm mode we don't need to draw the second
			// separator otherwise we have to do it.
			//------------------------------------------------------------------

			if(m != 1)
				WPrint(&MyWatchScr[SEP2STR], ":");

			break;

		case 3:
			DrawOff(&MyWatchScr[BSWATCH]);

			// We erase the tenths and the separator "."
			WClear(&MyWatchScr[SEP3STR]);
			WClear(&MyWatchScr[TTSSTR]);
			break;
	}

	//--------------------------------------------------------------------------
	// We have to draw the "on" picture of the button of the new mode.
	//--------------------------------------------------------------------------

	switch(m){
		case 0:
			DrawOn(&MyWatchScr[BTIME]);
			break;

		case 1:
			DrawOn(&MyWatchScr[BTIMESET]);

			//We erase the seconds and the second separator
			WClear(&MyWatchScr[SEP2STR]);
			WClear(&MyWatchScr[SECSTR]);
			break;

		case 2:
			DrawOn(&MyWatchScr[BALARM]);

			// We erase the seconds and the second separator
			WClear(&MyWatchScr[SEP2STR]);
			WClear(&MyWatchScr[SECSTR]);
			break;

		case 3:
			DrawOn(&MyWatchScr[BSWATCH]);

			//------------------------------------------------------------------
			// We draw seconds, tenths and all the separator we need if
			// they we are not drawn on the display
			//------------------------------------------------------------------

			if (om != 0){
				strencode2digit(tstr, seconds);
				WPrint(&MyWatchScr[SECSTR], tstr);
			}
			WPrint(&MyWatchScr[SEP3STR], ".");
			strencode1digit(tstr, tenths);
			WPrint(&MyWatchScr[TTSSTR], tstr);
			break;
	}
}

//------------------------------------------------------------------------------
// BLINK ALARM: Blinks alarm icon when the alarm stars ringing
//------------------------------------------------------------------------------

void blinkAlarm(unsigned char *count, boolean_T *now_visible){
	char tstr[3];

	// Every 2 BLINK_TIME we reset the counter
	if((*count) == 2*BLINK_TIME)
		(*count) = 0;

	if((*count >= BLINK_TIME) && (*now_visible) == true) {
		// We have to switch off the text and then we have to wait a BLINK_TIME
		DrawOff(&MyWatchScr[BALARM]);
		(*now_visible) = false;
	}
	else if((*count)%BLINK_TIME == 0 && (*now_visible) == false) {
		// We have to switch on the text and then we have to wait a BLINK_TIME
		DrawOn(&MyWatchScr[BALARM]);
		(*now_visible) = true;
	}

	(*count)++;
}

//------------------------------------------------------------------------------
// BLINK HOURS MINUTES: Blinks hours or minutes while in time set or alarm mode
//------------------------------------------------------------------------------

void blinkHoursMinutes(	unsigned char *count, boolean_T *now_visible,
						boolean_T *pre_visible, unsigned char pre_time,
						unsigned char now_time, int now_widg, int pre_widg) {
	char tstr[3];

	// If the previous blinking text is not visible now we have to draw it
	if((*pre_visible) == false){
		strencode2digit(tstr, pre_time);
		WPrint(&MyWatchScr[pre_widg], tstr);
		(*pre_visible) = true;
	}

	//--------------------------------------------------------------------------
	// This code is the same of the BLINK ALARM function. What changes is the
	// widget that we want to draw and the functions we have to call in order to
	// do it.
	//--------------------------------------------------------------------------

	if((*count) == 2*BLINK_TIME)
		(*count) = 0;

	if((*count >= BLINK_TIME) && (*now_visible) == true) {
		WClear(&MyWatchScr[now_widg]);
		(*now_visible) = false;
	}
	else if((*count)%BLINK_TIME == 0 && (*now_visible) == false){
		strencode2digit(tstr, now_time);
		WPrint(&MyWatchScr[now_widg], tstr);
		(*now_visible) = true;
	}

	(*count)++;
}

TASK(TaskClock) {
	static unsigned char 	oh = 99, om = 99, os = 99, ot = 99, oldmode = 8,
							countblinks = 0, countAlarmBlinks = 0;
	char 				 	tstr[3];
	unsigned char 		 	i;

	//--------------------------------------------------------------------------
	// If the LCDTask discovered an event we have to set to true the value of
	// the boolean associated to that event.
	//--------------------------------------------------------------------------

	if(IsEvent(PLUS)) 		{button[0] = true; countblinks = 0;}
	if(IsEvent(MINUS)) 		{button[1] = true; countblinks = 0;}
	if(IsEvent(TIMEMODE)) 	{button[2] = true; countblinks = 0;}
	if(IsEvent(TIMESETMODE)){button[3] = true; countblinks = 0;}
	if(IsEvent(ALARMMODE)) 	{button[4] = true; countblinks = 0;}
	if(IsEvent(SWATCHMODE)) {button[5] = true; countblinks = 0;}
	if(IsEvent(ALARMONOFF)) {button[6] = true; countblinks = 0;}

	if(tick == false)
		tick = true;
	else
		tick = false;

	// We call the step function in order to understand how the model evolves
	StopWatch2016_step(	&SW_State, 	tick, 		button[0], 		button[1],
						button[2],	button[3], 	button[4], 		button[5],
						button[6],	&hours,		&minutes, 		&seconds,
						&tenths,	&mode, 		&hblink, 		&mblink,
						&alarmOn,	&ringing);

	// Once we compute the step function we can clear events and booleans
	ClearEvents();
	for ( i = 0; i < 7; i++) button[i] = 0;

	// In mode 2 we have to draw the button useful to switch ON/OFF the alarm
	if(mode == 2){
		if(alarmOn == false)
			DrawOff(&MyWatchScr[BONOFF]);
		else
			DrawOn(&MyWatchScr[BONOFF]);
	}

	//--------------------------------------------------------------------------
	// If ringing is true this means that we have to blink the alarm icon,
	// otherwise we have to switch off the alarm. The alarm is simply a blinking
	// icon so we have to choose the color of the icon: yellow if we are in
	// mode 2 and white otherwise.
	//--------------------------------------------------------------------------

	if(ringing == true)
		blinkAlarm(&countAlarmBlinks, &alarmYellow);
	else{
		if(mode == 2 && alarmYellow == false)
			DrawOn(&MyWatchScr[BALARM]);

		if(mode != 2 && alarmYellow == true)
			DrawOff(&MyWatchScr[BALARM]);

		alarmYellow = false;
	}

	//--------------------------------------------------------------------------
	// We have to update if only if the time is changed otherwise we can observe
	// a disturbance on the display.
	//--------------------------------------------------------------------------

	if (hours != oh) {
		strencode2digit(tstr, hours);
		WPrint(&MyWatchScr[HRSSTR], tstr);
		hour_visible = true;
		oh = hours;
	}

	if (minutes != om) {
		strencode2digit(tstr, minutes);
		WPrint(&MyWatchScr[MINSTR], tstr);
		min_visible = true;
		om = minutes;
	}

	// The seconds should not be visible in alarm and in set time mode
	if (seconds != os && mode != 1 && mode != 2) {
		strencode2digit(tstr, seconds);
		WPrint(&MyWatchScr[SECSTR], tstr);
		os = seconds;
	}

	// The tenths should be visible only in swatch mode
	if (tenths != ot && mode == 3) {
		strencode1digit(tstr, tenths);
		WPrint(&MyWatchScr[TTSSTR], tstr);
		ot = tenths;
	}

	// Here we have to test if we have to blink the hours or the minutes
	if(hblink == true)
		blinkHoursMinutes(&countblinks, &hour_visible, &min_visible, minutes, hours, HRSSTR, MINSTR);

	if(mblink == true)
		blinkHoursMinutes(&countblinks, &min_visible, &hour_visible, hours, minutes, MINSTR, HRSSTR);

	if (mode != oldmode) {
		UpdateMode(oldmode, mode);
		oldmode = mode;
	}
}

int main(void) {
	int i = 0;
	alarmOn = alarmYellow = false;
	hour_visible = min_visible = true;
	hours = minutes = seconds = tenths = mode = 0;

	// Initializes System and Erika related stuffs
	SystemInit();
	EE_system_init();

	// Initiliaze the member of the structure used by the state machine
	SW_State.prevZCSigState = &prevZCSigState;
	SW_State.dwork = &dwork;

	// Initialize the state machine
	StopWatch2016_initialize(	&SW_State,	&tick,		button, 	button+1,
								button+2, 	button+3,	button+4, 	button+5,
								button+6, 	&hours,		&minutes, 	&seconds,
								&tenths,	&mode, 		&hblink, 	&mblink,
								&alarmOn,	&ringing);

	// Initialize systick
	EE_systick_set_period(MILLISECONDS_TO_TICKS(1, SystemCoreClock));
	EE_systick_enable_int();
	EE_systick_start();

	// Initializes LCD and touchscreen
	IOE_Config();

	// Initialize the LCD
	STM32f4_Discovery_LCD_Init();

	//--------------------------------------------------------------------------
	// Initialization of the touchscreen. If the touchscreen does not behave as
	// we want we have to change these values
	//--------------------------------------------------------------------------

	InitTouch(-0.09, 0.0656, -353, 10);

	// We draw the background and the widget we need
	DrawInit(MyWatchScr);
	WPrint(&MyWatchScr[SEP1STR], ":");
	WPrint(&MyWatchScr[SEP2STR], ":");

	//--------------------------------------------------------------------------
	// Here we program cyclic alarms which will fire after an initial offset
	// (10 in this case), and after that periodically. A task is associated to
	// each alarm and it is executed periodically.
	//--------------------------------------------------------------------------

	SetRelAlarm(AlarmTaskLCD, 10, 50);
	SetRelAlarm(AlarmTaskClock, 10, 100);

	// Forever loop: background activities (if any) should go here
	for (;;) {}
}
