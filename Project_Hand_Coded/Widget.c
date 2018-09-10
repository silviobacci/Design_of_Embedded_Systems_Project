/*
 * Widget.c
 *
 *  Created on: 21/ott/2015
 *      Author: admim
 */

#include "Widget.h"
#include "WidgetConfig.h"
#include "stm32f4_discovery_lcd.h"
#include "Event.h"
#include "debug.h"

unsigned char contains(const Widget *w, TPoint *point){
	if	((point->x >= w->xl) && (point->x <= w->xl + w->xw) &&
		 (point->y >= w->yt) && (point->y <= w->yt + w->yh)) {
/*		debuginfo(5, point->x, point->y, 0);
		debuginfo(6, w->xl, w->yt, 0); */
		return 1;
	}
	else
		return 0;
}

unsigned char OnTouch(const Widget ws[], TPoint *press){
	unsigned char i, res;

	res = 0;
	for(i=0; i<NUMWIDGETS; i++) {
		if (ws[i].wt == BUTTONICON) {
			if(contains(&ws[i], press)) {
				SetEvent(biconinfo(&ws[i])->onpress);
 			    res = 1;
 			}
		}
	}
	return res;
}

unsigned char DrawInit(const Widget ws[])
{
	unsigned char i;
	// We don't want  to draw the alarm ON/OFF button at the beginning because at the beginning we are in time mode.
	for(i=0; i<NUMWIDGETS-1; i++) {
		DrawOff(&ws[i]);
	}
	return 1;
}

unsigned char DrawOn(const Widget *w)
{
	const char *imgptr = 0;

	switch (w->wt) {
	case BUTTONICON:
		imgptr = biconinfo(w)->iconp;
		break;
	case BACKGROUND:
	case IMAGE:
		imgptr = imginfo(w)->image;
		break;
	}
	if (imgptr != 0) {
		LCD_DrawPicture(w->xl, w->yt, w->xw, w->yh, imgptr);
		return 1;
	} else
		return 0;
}

unsigned char DrawOff(const Widget *w)
{
	const char *imgptr = 0;

	switch (w->wt) {
	case BUTTONICON:
		imgptr = biconinfo(w)->iconr;
		break;
	case BACKGROUND:
	case IMAGE:
		imgptr = imginfo(w)->image;
		break;
	}
	if (imgptr != 0) {
		LCD_DrawPicture(w->xl, w->yt, w->xw, w->yh, imgptr);
		return 1;
	}
		return 0;
}

unsigned char WPrint(const Widget *w, char *s)
{
	// If we want to rewrite a text we have to redraw the background and then we have to write again the text.
	if (w->wt == TEXT) {
		if(txtinfo(w)->bmode == IMG)
			LCD_DrawPicture(w->xl, w->yt, w->xw, w->yh, txtinfo(w)->bimage);
		LCD_SetTextColor(txtinfo(w)->color);
		LCD_SetFont(txtinfo(w)->font);
		// In order to centre the text in the display we have to put 18 pixel under the top of the box
		// in which the text is contained.
		LCD_DisplayStringXY(w->xl, w->yt+18, s);
		return 1;
	} else
		return 0;
}

unsigned char WClear(const Widget *w)
{
	// If we want to erase a text we have to redraw the background.
	if (w->wt == TEXT) {
		if(txtinfo(w)->bmode == IMG)
			LCD_DrawPicture(w->xl, w->yt, w->xw, w->yh, txtinfo(w)->bimage);
		return 1;
	} else
		return 0;
}




