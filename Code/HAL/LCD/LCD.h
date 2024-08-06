/*
 * LCD.h
 *
 *  Created on: Aug 16, 2023
 *      Author: Mostafa Sayed
 */

#ifndef HAL_LCD_LCD_H_
#define HAL_LCD_LCD_H_

#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>


/****************** Macros *********************/

/*		Commands					*/
#define CLR_DISPLAY 	 			0x01

#define RETURN_HOME		 			0x02

/*		Entry Mode Set				*/

#define ENTRY_CUR_LEFT_SCR_LEFT		0x05
#define ENTRY_CUR_RIGHT_SCR_LEFT 	0x07
#define	ENTRY_CUR_LEFT_SCR_RIGHT	0x04
#define	ENTRY_CUR_RIGHT_SCR_RIGHT	0x06

/*		Cursor Display and Shift	*/

#define DIS_CUR_LEFT_SCR_LEFT		0x10
#define DIS_CUR_LEFT_SCR_RIGHT		0x14
#define DIS_CUR_RIGHT_SCR_LEFT		0x18
#define DIS_CUR_RIGHT_SCR_RIGHT		0x1C

/*		 Display Control			*/

#define DIS_OFF_CUR_OFF_BLINK_OFF	0x08
#define DIS_OFF_CUR_OFF_BLINK_ON	0x09
#define DIS_OFF_CUR_ON_BLINK_OFF	0x0A
#define DIS_OFF_CUR_ON_BLINK_ON		0x0B

#define DIS_ON_CUR_OFF_BLINK_OFF	0x0C
#define DIS_ON_CUR_OFF_BLINK_ON		0x0D
#define DIS_ON_CUR_ON_BLINK_OFF		0x0E
#define DIS_ON_CUR_ON_BLINK_ON		0x0F

/*		 Function Set				*/

#define BIT_4_LINE_1_FORMAT_5X8		0x20
#define BIT_4_LINE_1_FORMAT_5X11	0x24
#define BIT_4_LINE_2_FORMAT_5X8		0x28
#define BIT_4_LINE_2_FORMAT_5X11	0x2C

#define BIT_8_LINE_1_FORMAT_5X8		0x30
#define BIT_8_LINE_1_FORMAT_5X11	0x34
#define BIT_8_LINE_2_FORMAT_5X8		0x38
#define BIT_8_LINE_2_FORMAT_5X11	0x3C

/*		 Pin Configuration			*/
#define LCD_CONTROL_PORT			DIO_PORTB
#define LCD_RW						DIO_PIN0
#define LCD_RS						DIO_PIN1
#define LCD_E						DIO_PIN2

#define LCD_DATA_PORT      			DIO_PORTA
#define LCD_D4						DIO_PIN4
#define LCD_D5						DIO_PIN5
#define LCD_D6						DIO_PIN6
#define LCD_D7						DIO_PIN7

/*        Dimension of LCD            */
#define DOT_ROWS					11
#define DOT_COLUMNS					5

/* 			LCD Mode		*/
#define BIT_4     					0
#define BIT_8     					1

#define MODE	  					BIT_8

/* 			Line Number		*/

#define LCD_LINE1			1
#define LCD_LINE2			2
#define LCD_LINE3			3
#define LCD_LINE4			4

/**********************************************/

/********************** APIs ******************/

/*		Main Functions			*/
void LCD_voidInit(void);
void LCD_voidSendCommand(u8 Copy_u8Command);
void LCD_voidSendChar(u8 Copy_u8Char);

/*		Additional Functions	*/
void LCD_voidSendString(u8* Copy_u8String);
void LCD_voidSetLocation(u8 Copy_u8LineNum, u8 Copy_u8CharacterNumber);
void LCD_voidSendNumber(u32 Copy_u32Number);

void LCD_voidClear(void);
void LCD_voidDrawSpecialChar(u8 Copy_u8CharIndex,u8* Copy_u8SpecialChar);
void LCD_voidSendSpecialChar(u8 Copy_u8CharIndex);
/**********************************************/


/**
 * Session Notes:
 *
 * Configuration types:
 * 	Pre-build/Pre-Compiled configuration
 * 	Post-build Configuration
 * 	Link Time Configuration
 *
 * 	1- Pre-build/Pre-Compiled:
 * 		Using Macros : e.g #define LED_PORT DIO_PORTA // Should be written in config.h
 * 		DIO_voidPortDirection(LED_PORT,DIO_OUTPUT)  // More Readable
 * 	2- Post-Build Configuration:
 * 		During Runtime, using structure data type and allow function to receive pointer to structure
 *	3- Link Time Configuration:
 *		Give Customer Config.o only which he links with other objects files for security reasons
 *	Notes : MISRA when develop code will maintain safety
 *	e.g: using else in any if statements
 *
 *	Types of Display:
 *		1- LED display		:
 *		2- Segment display	:
 *		3- Dot Matrix 		: consist of many LEDs
 *				LED Display	  Disadvantage : 1- High Power Consumption , 2- Consume a lot of Pins
 *				LED Display   Advantages   : 1- Attractive , 2- View angle is Good , 3- Small Size
 *
 *	1- Light Polarization:
 *		Light is electromagnetic wave
 *		unpolarized light is normal light that moves in all direction
 *		Light + Polarizer = Light polarization (Vibrate in one place)
 *		Polarizer can be vertical (pass only vertical light) or horizontal (pass only horizontal light)
 *
 *	2- Liquid Crystals	 :
 *		At normal condition (same as liquid)
 *		Change its internal structure with voltage effect
 *		Without current  it twist light by 90' so light pass
 *		if current is applied, liquid crystal will solidify so light pass without twist but doesn't pass through polarizer
 *
 *	These are Concepts of LCD :
 *		Light Polarization: Two Polarizer (one Vertical and another one is Horizontal)
 *		Liquid Crystal	  : Applying Current -> No Light will pass through Horizontal Polarizer
 *
 *	LCD consists of many pixels. Each pixel depend on concepts
 *	LCD also have Backlight which is source of light that will be twisted or not depending on application of current
 *
 *	LCD types:
 *		1- Segment LCD 						: Many Seven Segment Display but works with concept of Light Polarization and Liquid Crystal
 *		2- Alphanumeric LCD (Character LCD)	: LCD with some blocks such that each block is group of pixels that have Microcontroller that works with each pixel
 *		LCD contain character : English Alphabets and Numbers , some special Characters
 *		to display a character you communicate with LCD's Micro-Controller
 *		3- Graphical LCD					: you have Control on All Pixels , types : Monochrome has one LED Source , Colored LCD has RGB LED
 *
 *	LCD Module :
 *		Consist of LED Source + Liquid Crystal + Polarizers + Panel + Micro-Controller
 *		Communication between ATMEGA32 and LCD Micro-Controller is done by parallel communication : 8-Lines Parallel Communication Byte by Byte
 *
 *	LCD Pins:
 *		VSS  Connected to GND
 *		VDD  Connected to VCC (Power Supply)
 *		Vo   Control Contrast by Potentiometer (Variable Resistor) using concept of Voltage Dividers
 *		RS   0 -> Sending Command , 1 -> Sending Data
 *		R/W  0 -> Write to LCD    , 1 -> Read from LCD (Busy Flag or Display Data)
 *		E    Enable LCD required at each data transfer (falling edge)
 *		D0-7 Parallel Communication with ATMEGA32
 *		A    Anode of Back-Light
 *		K    Cathode of Back-Light
 *
 */


#endif /* HAL_LCD_LCD_H_ */
