/*!	\file	Watch.h
 	\author Daniel Casini
 	\date	10/03/2014
	\brief	Watch implementation for STM32F4Discovery, using LCD_Touch_Lib for SSD2119 (LCD) and STMPE811QTR (Touch)
*/

#ifndef WATCH_H_
#define WATCH_H_

#include "stm32f4xx.h"
#include "stm32f4_discovery_lcd.h"
#include <math.h>

/*! \def	HOUR_HAND_LEN
    \brief	Lenght of the hours hand
*/
#define HOUR_HAND_LEN		43

/*! \def	MINUTE_HAND_LEN
    \brief	Lenght of the minute hand
*/
#define MINUTE_HAND_LEN		50

/*! \def	SECOND_HAND_LEN
    \brief	Lenght of the seconds hand
*/
#define SECOND_HAND_LEN		54

/*! \def	CENTER_Y
    \brief	Center of the watch, y coordinate
*/
#define CENTER_RADIUS		6

/*! \def	CENTER_X
    \brief	Center of the watch, x coordinate
*/
#define CENTER_X			162

/*! \def	CENTER_Y
    \brief	Center of the watch, y coordinate
*/
#define CENTER_Y			104

/*! 	\struct
		\brief Represents the time
 */
typedef struct TimeStructType_
{
	unsigned char hours;	/*!< Hours variable */
	unsigned char minutes;	/*!< Minutes variable */
	unsigned char seconds;	/*!< Seconds variable */
	unsigned char tenths;	/*!< Tenths variable */
} TimeStructType;

/*! \fn		void drawSeconds(uint8_t seconds, uint16_t color)
    \brief  Draws the seconds hand on the screen
	\param  seconds	seconds
	\param	color	color of the hand
*/
void drawSeconds(uint8_t seconds, uint16_t color);

/*! \fn		void drawMinutes(uint8_t minutes, uint16_t color)
    \brief  Draws the minutes hand on the screen
	\param  minutes	minutes
	\param	color	color of the hand
*/
void drawMinutes(uint8_t minutes, uint16_t color);

/*! \fn		void drawHours(uint8_t hours, uint8_t minutes, uint16_t color)
    \brief  Draws the hours hand on the screen
	\param  hours	hours
	\param	minutes	minutes, to draw the hours hand in the correct position among two hours
	\param	color	color of the hand
*/
void drawHours(uint8_t hours, uint8_t minutes, uint16_t color);

/*! \fn		void drawTime(uint8_t hours, uint8_t minutes, uint8_t seconds, uint16_t color)
    \brief  Draws the time on the screen
	\param  hours	hours
	\param	minutes	minutes
	\param	seconds	seconds
	\param	color	color of the hand
*/
void drawTime(uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t tenths, uint16_t color, uint8_t tmode);

/*! \fn
    \brief  Draws the filled circle in the center of the watch
*/
void drawCenter();

/*! \fn		void setTime(TimeStructType *watch, uint8_t hours, uint8_t minutes, uint8_t seconds)
    \brief  Sets the time in the specified watch and draws it on the screen
    \param	watch	watch
	\param  hours	hours
	\param	minutes	minutes
	\param	seconds	seconds
*/
void setTime(TimeStructType *watch, uint8_t hours, uint8_t minutes, uint8_t seconds, uint8_t tenths);

/*! \fn		void initTime(TimeStructType *watch)
    \brief  Initializes time to 00:00:00
    \param	watch	watch
*/
void initTime(TimeStructType *watch);

/*! \fn		void copyTime(TimeStructType *watch)
    \brief  Copies the time of src into dst
    \param	src	source watch
    \param	dst	destination watch
*/
void copyTime(TimeStructType *dst, TimeStructType *src);

/*! \fn		void tickSeconds(TimeStructType *watch)
    \brief  Handles the time increasing in the specified watch
    \param	watch	watch
*/
void tickSeconds(TimeStructType *watch);

/*! \fn		void updateClock(TimeStructType *watch)
    \brief  Handles the time increasing in the specified watch and update the hands on the screen
    \param	watch	watch
*/
void updateClock(TimeStructType *watch, uint8_t mode);


#endif /* WATCH_H_ */
