/*
 * WidgetConfig.c
 *
 *  Created on: 21/ott/2015
 *      Author: admim
 */

#include "Widget.h"
#include "WidgetConfig.h"
#include "pictures.h"
#include <stdio.h>
#include "stm32f4_discovery_lcd.h"
#include "fonts.h"

ButtonIcon buttontime = 	{icontime_on, 		icontime_off, 		TIMEMODE};

ButtonIcon buttontimeset = 	{icontimeset_on, 	icontimeset_off, 	TIMESETMODE};

ButtonIcon buttonalarm = 	{iconalarm_on, 		iconalarm_off, 		ALARMMODE};

ButtonIcon buttonswatch = 	{iconswatch_on, 	iconswatch_off, 	SWATCHMODE};

ButtonIcon buttonplus = 	{0, 				0, 					PLUS};

ButtonIcon buttonminus = 	{0, 				0, 					MINUS};

ButtonIcon buttonOnOff = 	{alarmON, 			alarmOFF, 			ALARMONOFF};


Text hoursTxt = 	{&Font16x24, White, Black, IMG, hoursBground};

Text minutesTxt = 	{&Font16x24, White, Black, IMG, minutesBground};

Text secondsTxt = 	{&Font16x24, White, Black, IMG, secondsBground};

Text tenthsTxt =	{&Font16x24, White, Black, IMG, tenthsBground};

Text sep1Txt = 		{&Font16x24, White, Black, IMG, sep1Bground};

Text sep2Txt = 		{&Font16x24, White, Black, IMG, sep2Bground};

Text sep3Txt = 		{&Font16x24, White, Black, IMG, sep3Bground};


Image backg = 		{ImageBuffer};

const Widget MyWatchScr[NUMWIDGETS] = {
		{0, 	0, 		320, 	240, 	BACKGROUND, (void *)&backg},
		{30, 	186, 	42, 	43,	 	BUTTONICON, (void *)&buttontime},
		{98, 	186, 	42, 	43, 	BUTTONICON, (void *)&buttontimeset},
		{169, 	186, 	42, 	43, 	BUTTONICON, (void *)&buttonalarm},
		{244, 	186, 	42, 	43, 	BUTTONICON, (void *)&buttonswatch},
		{250, 	58, 	40, 	40, 	BUTTONICON, (void *)&buttonplus},
		{250, 	110, 	40, 	40, 	BUTTONICON, (void *)&buttonminus},
		{32, 	78, 	38, 	52, 	TEXT, 		(void *)&hoursTxt},
		{90, 	78, 	38, 	52, 	TEXT, 		(void *)&minutesTxt},
		{148, 	78, 	38, 	52, 	TEXT, 		(void *)&secondsTxt},
		{206, 	78, 	20, 	52, 	TEXT, 		(void *)&tenthsTxt},
		{70, 	78, 	20, 	52, 	TEXT, 		(void *)&sep1Txt}, //sep
		{128, 	78, 	20, 	52, 	TEXT, 		(void *)&sep2Txt}, //sep
		{186, 	78, 	20, 	52, 	TEXT, 		(void *)&sep3Txt}, //sep
		{135, 	20, 	50, 	20, 	BUTTONICON, (void *)&buttonOnOff}
};

