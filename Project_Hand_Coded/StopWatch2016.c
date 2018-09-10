//------------------------------------------------------------------------------
// STOP WATCH 2016: Contains all the functions useful to manage the state
//					machine
//------------------------------------------------------------------------------

#include <string.h>
#include "StopWatch2016.h"

//------------------------------------------------------------------------------
// GLOBAL CONSTANTS
//------------------------------------------------------------------------------

// Possible states of the model
#define no_active_child 	(uint8_T)0
#define in_alarmmode     	(uint8_T)1
#define in_ringing       	(uint8_T)1
#define in_running       	(uint8_T)1
#define in_sethours      	(uint8_T)1
#define in_setminutes    	(uint8_T)2
#define in_silent        	(uint8_T)2
#define in_stopped       	(uint8_T)2
#define in_swatchmode    	(uint8_T)2
#define in_timemode      	(uint8_T)3
#define in_timesetmode   	(uint8_T)4

// Possible events
#define no_event			0
#define event_Bplus      	1
#define event_Bminus     	2
#define event_Btime      	3
#define event_Btimeset   	4
#define event_Balarm     	5
#define event_Bstop      	6
#define event_BalarmOnOff 	7

//------------------------------------------------------------------------------
// FUNCTIONS
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// RESET SWATCH: Reset the hour for the swatch mode
//------------------------------------------------------------------------------

void resetSwatch(local_variable* var){
	var->SWhours = 		(uint8_T)0;
	var->SWminutes = 	(uint8_T)0;
	var->SWseconds = 	(uint8_T)0;
	var->SWtenths = 	(uint8_T)0;
}

//------------------------------------------------------------------------------
// INCREMENT TENTHS: Increment the time
//------------------------------------------------------------------------------

void incrementTenths(uint8_T * hours, uint8_T * minutes, uint8_T * seconds, uint8_T * tenths){
	*tenths = (*tenths+1) % 10;

	if(*tenths == 0){
		*seconds = (*seconds+1)% 60;
		if(*seconds == 0){
			*minutes=(*minutes+1)% 60;
			if(*minutes == 0)
				*hours = (*hours+1)% 24;
		}
	}
}

//------------------------------------------------------------------------------
// CHOOSE EVENT EXTERNAL TIME MODE: Function useful to find the right event to
//									follow in order to understand which
//									transition we have to follow
//------------------------------------------------------------------------------

int choseEventExternalTimeMode(boolean_T timemode, boolean_T timesetmode, boolean_T alarmmode, boolean_T swatchmode)
{
	if(timemode == true)
		return event_Btime;
	if(timesetmode == true)
		return event_Btimeset;
	if(swatchmode == true)
		return event_Bstop;
	if(alarmmode == true)
		return event_Balarm;
	return no_event;
}

//------------------------------------------------------------------------------
// CHOOSE EVENT EXTERNAL ALARM MODE: 	Function useful to find the right event
//										to follow in order to understand which
//										transition we have to follow
//------------------------------------------------------------------------------

int choseEventExternalAlarmMode(boolean_T timemode, boolean_T timesetmode, boolean_T alarmonoff, boolean_T swatchmode)
{
	if(timemode == true)
		return event_Btime;
	if(timesetmode == true)
		return event_Btimeset;
	if(swatchmode == true)
		return event_Bstop;
	if(alarmonoff == true)
		return event_BalarmOnOff;
	return no_event;
}

//------------------------------------------------------------------------------
// CHOOSE EVENT EXTERNAL TIME SET MODE: Function useful to find the right event
//										to follow in order to understand which
//										transition we have to follow
//------------------------------------------------------------------------------

int choseEventExternalTimeSetMode(boolean_T timemode, boolean_T alarmmode, boolean_T swatchmode)
{
	if(timemode == true)
		return event_Btime;
	if(alarmmode == true)
		return event_Balarm;
	if(swatchmode == true)
		return event_Bstop;
	return no_event;
}

//------------------------------------------------------------------------------
// CHOOSE EVENT EXTERNAL SWATCH MODE: 	Function useful to find the right event
//										to follow in order to understand which
//										transition we have to follow
//------------------------------------------------------------------------------

int choseEventExternalSwatchMode(boolean_T timemode, boolean_T timesetmode, boolean_T alarmmode)
{
	if(timemode == true)
		return event_Btime;
	if(timesetmode == true)
		return event_Btimeset;
	if(alarmmode == true)
		return event_Balarm;
	return no_event;
}

//------------------------------------------------------------------------------
// CHOOSE EVENT INTERNAL ALARM MODE: 	Function useful to find the right event
//										to follow in order to understand which
//										transition we have to follow
//------------------------------------------------------------------------------

int choseEventInternalAlarmMode(boolean_T plusbutton,	boolean_T minusbutton, 	boolean_T alarmmode)
{
	if(plusbutton == true)
		return event_Bplus;
	if(minusbutton == true)
		return event_Bminus;
	if(alarmmode == true)
		return event_Balarm;
	return no_event;
}

//------------------------------------------------------------------------------
// CHOOSE EVENT INTERNAL SWATCH MODE: 	Function useful to find the right event
//										to follow in order to understand which
//										transition we have to follow
//------------------------------------------------------------------------------

int choseEventInternalSwatchMode(boolean_T plusbutton,	boolean_T minusbutton, 	boolean_T swatchmode)
{
	if(swatchmode == true)
		return event_Bstop;
	if(minusbutton == true)
		return event_Bminus;
	if(plusbutton == true)
		return event_Bplus;
	return no_event;
}

//------------------------------------------------------------------------------
// CHOOSE EVENT INTERNAL TIME SET MODE: Function useful to find the right event
//										to follow in order to understand which
//										transition we have to follow
//------------------------------------------------------------------------------

int choseEventInternalTimeSetMode(boolean_T plusbutton,	boolean_T minusbutton, 	boolean_T timesetmode)
{
	if(plusbutton == true)
		return event_Bplus;
	if(minusbutton == true)
		return event_Bminus;
	if(timesetmode == true)
		return event_Btimeset;
	return no_event;
}

//------------------------------------------------------------------------------
// TRANSITION IN CONTROL: 	Execute a transition while we are checking events in
//							the control state
//------------------------------------------------------------------------------

uint8_T transitionInControl(uint8_T newmode, uint8_T * oldmode, states * work_mode){
	work_mode->is_Control = newmode;

	if(oldmode != 0)
		*oldmode = no_active_child;

	switch(newmode){
		case in_timesetmode:
			return (uint8_T)1;
			break;
		case in_alarmmode:
			return (uint8_T)2;
			break;
		case in_swatchmode:
			return (uint8_T)3;
			break;
	}
	return (uint8_T)0;
}

//------------------------------------------------------------------------------
// EXIT TIME SET ALARM MODE: Exit operation in time set mode and alarm mode
//------------------------------------------------------------------------------

void exitTimesetAlarmMode(boolean_T *hblink, boolean_T *mblink){
	*hblink = false;
	*mblink = false;
}

//------------------------------------------------------------------------------
// EXIT ALARM ON MODE: Exit operations when we pressed the button alarm on/off
//------------------------------------------------------------------------------

void exitAlarmOnMode(boolean_T *hblink, boolean_T *mblink, boolean_T *alarmOn, boolean_T *ringing){
	if(*alarmOn == 	false)
		*alarmOn = 	true;
	else{
		*alarmOn = 	false;
		*ringing = 	false;
	}
	exitTimesetAlarmMode(hblink, mblink);
}

//------------------------------------------------------------------------------
// SET MINUTES PLUS: Function useful to increment minuteS
//------------------------------------------------------------------------------

uint8_T setMinutesPlus(uint8_T *m, boolean_T *mblink){
	*m = 	(*m + 1)%60;
	*mblink = 	true;
	return *m ;
}

//------------------------------------------------------------------------------
// SET MINUTES MINUS: Function useful to decrement minutes
//------------------------------------------------------------------------------

uint8_T setMinutesMinus(uint8_T *m, boolean_T *mblink){
	if(*m == 0)
		*m = (uint8_T)59;
	else
		*m = *m - 1;
	*mblink = 	true;
	return *m;
}

//------------------------------------------------------------------------------
// SET HOURS PLUS: Function useful to increment hours
//------------------------------------------------------------------------------

uint8_T setHoursPlus(uint8_T *h, uint8_T *m, uint8_T * minutes, boolean_T *hblink){
	*h = 	(*h + 1)%24;
	*minutes = 		*m;
	*hblink = 	true;
	return *h ;
}

//------------------------------------------------------------------------------
// SET HOURS MINUS: Function useful to decrement hours
//------------------------------------------------------------------------------

uint8_T setHoursMinus(uint8_T *h, uint8_T *m, uint8_T * minutes, boolean_T *hblink){
	if(*h == 0)
		*h = (uint8_T)23;
	else
		*h = *h - 1;
	*minutes = 		*m;
	*hblink = 	true;
	return *h;
}

//------------------------------------------------------------------------------
// ENTRY SET HOURS: Entry operations for set hours
//------------------------------------------------------------------------------

uint8_T entrySetHours(uint8_T h, uint8_T m, uint8_T * currentMode, uint8_T * minutes, boolean_T *hblink, boolean_T *mblink){
	*currentMode = in_sethours;
	*minutes = 	m;
	*hblink =	true;
	*mblink = 	false;
	return h;
}

//------------------------------------------------------------------------------
// ENTRY SET MINUTES: Entry operations for set minutes
//------------------------------------------------------------------------------

uint8_T entrySetMinutes(uint8_T m, uint8_T * currentMode, boolean_T *hblink, boolean_T *mblink){
	*currentMode = in_setminutes;
	*hblink =	false;
	*mblink = 	true;
	return m;
}

//------------------------------------------------------------------------------
// DISPLAY HOUR: Save the variables we want to display
//------------------------------------------------------------------------------

void displayHour(uint8_T *hours, uint8_T *min, uint8_T *sec, uint8_T *ten, uint8_T h, uint8_T m, uint8_T s, uint8_T t){
	*hours = h;
	*min = m;
	*sec = s;
	*ten = t;
}

//------------------------------------------------------------------------------
// MANAGE CONTROL: We check if we have to follow a transition in control state
//------------------------------------------------------------------------------

void manageControl(	states * work_mode, 	boolean_T timemode,		boolean_T timesetmode,
					boolean_T alarmmode,	boolean_T swatchmode,	boolean_T alarmonoff,
					uint8_T *mode ,			boolean_T * alarmOn,	boolean_T * ringing,
					uint8_T *hours,			uint8_T *minutes,		uint8_T *seconds,
					uint8_T *tenths, 		boolean_T *hblink,		boolean_T *mblink)
{
	int event = no_event;
	switch(work_mode->is_Control){
		case in_timemode:
			event = choseEventExternalTimeMode(timemode, timesetmode, alarmmode, swatchmode);
			switch(event){
				case event_Btimeset:
					*mode = transitionInControl(in_timesetmode, 0, work_mode);
					break;
				case event_Balarm:
					*mode = transitionInControl(in_alarmmode, 0, work_mode);
					break;
				case event_Bstop:
					*mode = transitionInControl(in_swatchmode, 0, work_mode);
					break;
			}
			break;
		case in_timesetmode:
			event = choseEventExternalTimeSetMode(timemode, alarmmode, swatchmode);
			switch(event){
				case event_Btime:
					*mode = transitionInControl(in_timemode, &work_mode->is_timesetmode, work_mode);
					exitTimesetAlarmMode(hblink, mblink);
					break;
				case event_Balarm:
					*mode = transitionInControl(in_alarmmode, &work_mode->is_timesetmode, work_mode);
					exitTimesetAlarmMode(hblink, mblink);
					break;
				case event_Bstop:
					*mode = transitionInControl(in_swatchmode, &work_mode->is_timesetmode, work_mode);
					exitTimesetAlarmMode(hblink, mblink);
					break;
			}
			break;
		case in_alarmmode:
			event = choseEventExternalAlarmMode(timemode, timesetmode, alarmonoff, swatchmode);
			switch(event){
				case event_Btime:
					*mode = transitionInControl(in_timemode, &work_mode->is_alarmmode, work_mode);
					exitTimesetAlarmMode(hblink, mblink);
					break;
				case event_Btimeset:
					*mode = transitionInControl(in_timesetmode, &work_mode->is_alarmmode, work_mode);
					exitTimesetAlarmMode(hblink, mblink);
					break;
				case event_BalarmOnOff:
					*mode = transitionInControl(in_alarmmode, &work_mode->is_alarmmode, work_mode);
					exitAlarmOnMode(hblink, mblink, alarmOn, ringing);
					break;
				case event_Bstop:
					*mode = transitionInControl(in_swatchmode, &work_mode->is_alarmmode, work_mode);
					exitTimesetAlarmMode(hblink, mblink);
					break;
			}
			break;
		case in_swatchmode:
			event = choseEventExternalSwatchMode(timemode, timesetmode, alarmmode);
			switch(event){
				case event_Btime:
					*mode = transitionInControl(in_timemode, &work_mode->is_swatchmode, work_mode);
					break;
				case event_Btimeset:
					*mode = transitionInControl(in_timesetmode, &work_mode->is_swatchmode, work_mode);
					break;
				case event_Balarm:
					*mode = transitionInControl(in_alarmmode, &work_mode->is_swatchmode, work_mode);
					break;
			}
			break;
	}
}

//------------------------------------------------------------------------------
// MANAGE TIME SET MODE: 	We check if we have to follow a transition in the
//							time set mode state
//------------------------------------------------------------------------------

void manageTimeSetMode(	states * work_mode, 		local_variable * var, 			boolean_T minusbutton,
						boolean_T plusbutton, 		boolean_T timesetmode,			boolean_T * hblink,
						boolean_T * mblink,			uint8_T *hours, 				uint8_T *minutes)
{
	int event = no_event;
	switch(work_mode->is_timesetmode){
		case in_sethours:
			event = choseEventInternalTimeSetMode(plusbutton, minusbutton, timesetmode);
			switch(event){
				case event_Bplus:
					*hours = setHoursPlus(&var->hours, &var->minutes, minutes, hblink);
					break;
				case event_Bminus:
					*hours = setHoursMinus(&var->hours, &var->minutes, minutes, hblink);
					break;
				case event_Btimeset:
					*minutes = entrySetMinutes(var->minutes, &work_mode->is_timesetmode, hblink, mblink);
					break;
			}
			break;
		case in_setminutes:
			event = choseEventInternalTimeSetMode(plusbutton, minusbutton, timesetmode);
			switch(event){
				case event_Bplus:
					*minutes = setMinutesPlus(&var->minutes, mblink);
					break;
				case event_Bminus:
					*minutes = setMinutesMinus(&var->minutes, mblink);
					break;
				case event_Btimeset:
					*hours = entrySetHours(var->hours, var->minutes, &work_mode->is_timesetmode, minutes, hblink, mblink);
					break;
			}
			break;
		case no_active_child:
			*hours = entrySetHours(var->hours, var->minutes, &work_mode->is_timesetmode, minutes, hblink, mblink);
			break;
	}
}

//------------------------------------------------------------------------------
// MANAGE ALARM MODE: 	We check if we have to follow a transition in the alarm
//						mode state
//------------------------------------------------------------------------------

void manageAlarmMode(	states * work_mode, 		local_variable * var, 			boolean_T minusbutton,
						boolean_T plusbutton, 		boolean_T alarmmode,			boolean_T * hblink,
						boolean_T * mblink,			uint8_T *hours,					uint8_T *minutes)
{
	switch(work_mode->is_alarmmode){
	int event = no_event;
		case in_sethours:
			event = choseEventInternalAlarmMode(plusbutton, minusbutton, alarmmode);
			switch(event){
				case event_Bplus:
					*hours = setHoursPlus(&var->Ahours, &var->Aminutes, minutes, hblink);
					break;
				case event_Bminus:
					*hours = setHoursMinus(&var->Ahours, &var->Aminutes, minutes, hblink);
					break;
				case event_Balarm:
					*minutes = entrySetMinutes(var->Aminutes, &work_mode->is_alarmmode, hblink, mblink);
					break;
			}
			break;
		case in_setminutes:
			event = choseEventInternalAlarmMode(plusbutton, minusbutton, alarmmode);
			switch(event){
				case event_Bplus:
					*minutes = setMinutesPlus(&var->Aminutes, mblink);
					break;
				case event_Bminus:
					*minutes = setMinutesMinus(&var->Aminutes, mblink);
					break;
				case event_Balarm:
					*hours = entrySetHours(var->Ahours, var->Aminutes, &work_mode->is_alarmmode, minutes, hblink, mblink);
					break;
			}
			break;
		case no_active_child:
			*hours = entrySetHours(var->Ahours, var->Aminutes, &work_mode->is_alarmmode, minutes, hblink, mblink);
			break;
	}
}

//------------------------------------------------------------------------------
// MANAGE SWATCH MODE: 	We check if we have to follow a transition in the swatch
//						mode state
//------------------------------------------------------------------------------

void manageSwatchMode(	states * work_mode, 		local_variable * var, 		boolean_T minusbutton,
						boolean_T plusbutton,		boolean_T swatchmode,		uint8_T *hours,
						uint8_T *minutes,			uint8_T *seconds,			uint8_T *tenths)
{
	int event = no_event;
	switch(work_mode->is_swatchmode){
		case in_stopped:
			event = choseEventInternalSwatchMode(plusbutton, minusbutton, swatchmode);
			switch(event){
				case event_Bplus:
					var->lapmode = false;
					work_mode->is_swatchmode = 	in_running;
					break;
				case event_Bstop:
					work_mode->is_swatchmode = 	in_stopped;
					resetSwatch(var);
					displayHour(hours, minutes, seconds, tenths, var->SWhours, var->SWminutes, var->SWseconds, var->SWtenths);
					break;
			}
			break;
		case in_running:
			incrementTenths(&var->SWhours, &var->SWminutes, &var->SWseconds, &var->SWtenths);
			event = choseEventInternalSwatchMode(plusbutton, minusbutton, swatchmode);
			switch(event){
				case event_Bplus:
					if(var->lapmode == true)
						var->lapmode = false;
					else{
						var->lapmode = true;
						work_mode->is_swatchmode = 	in_stopped;
						displayHour(hours, minutes, seconds, tenths, var->SWhours, var->SWminutes, var->SWseconds, var->SWtenths);
					}
					break;
				case event_Bminus:
					if(var->lapmode == true)
						var->lapmode = false;
					else
						var->lapmode = true;
					break;
				case event_Bstop:
					work_mode->is_swatchmode = in_stopped;
					resetSwatch(var);
					displayHour(hours, minutes, seconds, tenths, var->SWhours, var->SWminutes, var->SWseconds, var->SWtenths);
					break;
			}
			if(var->lapmode == false)
				displayHour(hours, minutes, seconds, tenths, var->SWhours, var->SWminutes, var->SWseconds, var->SWtenths);
			break;
		case no_active_child:
			work_mode->is_swatchmode = in_stopped;
			resetSwatch(var);
			displayHour(hours, minutes, seconds, tenths, var->SWhours, var->SWminutes, var->SWseconds, var->SWtenths);
			break;
	}
}

//------------------------------------------------------------------------------
// MANAGE ALARM MANAGER: 	We check if we have to follow a transition in the
//							alarm manager state
//------------------------------------------------------------------------------

void manageAlarmManager(states * work_mode, local_variable * var, boolean_T * alarmOn, boolean_T * ringing){
	switch(work_mode->is_AlarmMng){
		case in_ringing:
			if(*ringing == false || var->hours != var->Ahours || var->minutes != var->Aminutes){
				work_mode->is_AlarmMng = in_silent;
				*ringing = false;
			}
			break;
		case in_silent:
			if(*alarmOn == true && var->hours == var->Ahours && var->minutes == var->Aminutes){
				work_mode->is_AlarmMng = in_ringing;
				*ringing = true;
			}
			break;
	}
}

//------------------------------------------------------------------------------
// STOP WATCH 2016 STEP: 	Step function called to update the output and the
//							state of the machine
//------------------------------------------------------------------------------

void StopWatch2016_step(		RT_MODEL_StopWatch2016_T * StopWatch2016_M, 			boolean_T plusbutton,
		boolean_T minusbutton, 	boolean_T timemode,			boolean_T timesetmode, 		boolean_T alarmmode,
		boolean_T swatchmode, 	boolean_T alarmonoff,		uint8_T *hours, 			uint8_T *minutes,
		uint8_T *seconds, 		uint8_T *tenths, 			uint8_T *mode, 				boolean_T *hblink,
		boolean_T *mblink, 		boolean_T *alarmOn, 		boolean_T *ringing)
{
	states *work_mode = ((states *)StopWatch2016_M->work_mode);
	local_variable *var = ((local_variable *)StopWatch2016_M->var);

	//Time Count State
	incrementTenths(&var->hours, &var->minutes, &var->seconds, &var->tenths);

	// Control States
	manageControl(	work_mode, 			timemode, 		timesetmode, 	alarmmode,
					swatchmode, 		alarmonoff, 	mode, 			alarmOn,
					ringing,			hours, 			minutes,		seconds,
					tenths, 			hblink,			mblink);

	// Control Substates
	switch(work_mode->is_Control){
		case in_timemode:
			displayHour(hours, minutes, seconds, tenths, var->hours, var->minutes, var->seconds, var->tenths);
			break;
		case in_timesetmode:
			manageTimeSetMode(work_mode, var, minusbutton, plusbutton, timesetmode, hblink, mblink, hours, minutes);
			break;
		case in_alarmmode:
			manageAlarmMode(work_mode, var, minusbutton, plusbutton, alarmmode,	hblink, mblink, hours, minutes);
			break;
		case in_swatchmode:
			manageSwatchMode(work_mode, var, minusbutton, plusbutton, swatchmode, hours, minutes, seconds, tenths);
			break;
	}

	// Alarm Manager State
	manageAlarmManager(work_mode, var, alarmOn, ringing);
}

//------------------------------------------------------------------------------
// STOP WATCH 2016 INITIALIZE: 	Initialize function called to initialize  the
//								state machine
//------------------------------------------------------------------------------

void StopWatch2016_initialize(		RT_MODEL_StopWatch2016_T * StopWatch2016_M, 			boolean_T *plusbutton,
			boolean_T *minusbutton, boolean_T *timemode,		boolean_T *timesetmode, 	boolean_T *alarmmode,
			boolean_T *swatchmode, 	boolean_T *alarmonoff,		uint8_T *hours, 			uint8_T *minutes,
			uint8_T *seconds, 		uint8_T *tenths, 			uint8_T *mode, 				boolean_T *hblink,
			boolean_T *mblink, 		boolean_T *alarmOn, 		boolean_T *ringing)
{
	// Allocation of the structure of the model
	states *work_mode = ((states *)StopWatch2016_M->work_mode);
	local_variable *var = ((local_variable *)StopWatch2016_M->var);

	(void) memset((void *)work_mode, 0, sizeof(states));
	(void) memset((void *)var, 0, sizeof(local_variable));

	// Initialization of the events
	plusbutton = 	false;
	minusbutton = 	false;
	timemode = 		false;
	timesetmode = 	false;
	alarmmode = 	false;
	swatchmode = 	false;
	alarmonoff = 	false;

	// Initialization of the variables
	*hours = 		(uint8_T)0;
	*minutes = 		(uint8_T)0;
	*seconds = 		(uint8_T)0;
	*tenths = 		(uint8_T)0;
	*mode = 		(uint8_T)0;
	*hblink = 		false;
	*mblink = 		false;
	*alarmOn = 		false;
	*ringing = 		false;

	// Initialization of the states
	work_mode->is_alarmmode = 	no_active_child;
	work_mode->is_swatchmode = 	no_active_child;
	work_mode->is_timesetmode = no_active_child;
	work_mode->is_Control = 	in_timemode;
	work_mode->is_AlarmMng = 	in_silent;

	// Initialization of the local variables
	var->hours = 	(uint8_T)0;
	var->minutes = 	(uint8_T)0;
	var->seconds = 	(uint8_T)0;
	var->tenths = 	(uint8_T)0;
	var->Ahours = 	(uint8_T)0;
	var->Aminutes = (uint8_T)0;
}
