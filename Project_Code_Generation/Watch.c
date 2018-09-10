/*
 * Watch.c
 *
 *  Created on: 09/mar/2014
 *      Author: Daniel
 */

#include "Watch.h"

static TimeStructType oldwatch;

void drawTenths(uint8_t tenths, uint16_t color){
	float angle = (2 * M_PI / 12) * tenths;
	uint8_t x = SECOND_HAND_LEN * cos(- M_PI/2 + angle) + CENTER_X;
	uint8_t y = SECOND_HAND_LEN * sin(- M_PI/2 + angle) + CENTER_Y;
	LCD_SetTextColor(color);
	LCD_DrawUniLine(   	CENTER_X,
						CENTER_Y,
						x,
						y);
}

void drawSeconds(uint8_t seconds, uint16_t color){
	float angle = (2 * M_PI / 60) * seconds;
	uint8_t x = SECOND_HAND_LEN * cos(- M_PI/2 + angle) + CENTER_X;
	uint8_t y = SECOND_HAND_LEN * sin(- M_PI/2 + angle) + CENTER_Y;
	LCD_SetTextColor(color);
	LCD_DrawUniLine(   	CENTER_X,
						CENTER_Y,
						x,
						y);
}

void drawMinutes(uint8_t minutes, uint16_t color){
	float angle = (2 * M_PI / 60) * minutes;
	uint8_t x = MINUTE_HAND_LEN * cos(- M_PI/2 + angle) + CENTER_X;
	uint8_t y = MINUTE_HAND_LEN * sin(- M_PI/2 + angle) + CENTER_Y;
	LCD_SetTextColor(color);
	LCD_DrawUniLine(   	CENTER_X,
						CENTER_Y,
						x,
						y);
	LCD_DrawUniLine(   	CENTER_X+1,
						CENTER_Y+1,
						x + 1,
						y + 1);
}

void drawHours(uint8_t hours, uint8_t minutes, uint16_t color){
	float angle = (2 * M_PI / 12) * hours + (2 * M_PI / (12*60)) * minutes;
	uint8_t x = HOUR_HAND_LEN * cos(- M_PI/2 + angle) + CENTER_X;
	uint8_t y = HOUR_HAND_LEN * sin(- M_PI/2 + angle) + CENTER_Y;
	LCD_SetTextColor(color);
	LCD_DrawUniLine(   	CENTER_X-1,
						CENTER_Y-1,
						x - 1,
						y - 1);
	LCD_DrawUniLine(   	CENTER_X,
						CENTER_Y,
						x,
						y);
	LCD_DrawUniLine(   	CENTER_X+1,
						CENTER_Y+1,
						x + 1,
						y + 1);
}

void drawTime(uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t tenths, uint16_t color, uint8_t tenthsmode){
	if (tenthsmode == 1) drawTenths(tenths, color);
	drawSeconds(seconds, color);
	drawMinutes(minutes, color);
	drawHours(hours, minutes, color);
}

void drawCenter(){
	LCD_SetTextColor(White);
	uint16_t radius = CENTER_RADIUS;
	while(radius != 0)
		LCD_DrawCircle(CENTER_X, CENTER_Y, radius--);
}

void setTime(TimeStructType *watch, uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t tenths){
	/* Deleting the hands related to the old time */
	watch->hours = hours;
	watch->minutes = minutes;
	watch->seconds = seconds;
	watch->tenths = tenths;
	/* Draw the new hands */
}

void initTime(TimeStructType *watch){
	watch->hours = 0;
	watch->minutes = 0;
	watch->seconds = 0;
	watch->tenths = 0;
}

void copyTime(TimeStructType *dst, TimeStructType *src){
	dst->hours = src->hours;
	dst->minutes = src->minutes;
	dst->seconds = src->seconds;
	dst->tenths = src->tenths;
}

void tickSeconds(TimeStructType *watch){
	watch->seconds = (watch->seconds+1)%60;
	if (0 == watch->seconds)
		watch->minutes = (watch->minutes+1)%60;
	else return;
	if (0 == watch->minutes)
		watch->hours = (watch->hours+1)%24;
	else return;
}

void updateClock(TimeStructType *watch, uint8_t mode){
	uint16_t col;
	uint8_t tmode=0;
	/* Deleting the hands related to the old time */
	drawTime(oldwatch.hours, oldwatch.minutes, oldwatch.seconds, oldwatch.tenths, Black, 1);
/*	tickSeconds(watch); */
	/* Draw the new hands */
	switch (mode) {
	case 1:
		col = White;
		break;
	case 2:
		col = Red;
		break;
	case 3:
		col = Green;
		break;
	case 4:
		col = Blue;
		tmode=1;
	}
	drawTime(watch->hours, watch->minutes, watch->seconds, watch->tenths, col, tmode);
	drawCenter();
	copyTime(&oldwatch, watch);
}
