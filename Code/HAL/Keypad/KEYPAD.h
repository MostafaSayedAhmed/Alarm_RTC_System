/*
 * KEYPAD.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Mostafa Sayed
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_


#include "../../MCAL/DIO/DIO.h"
#include <util/delay.h>

/*			Configurations					*/


#define KEYPAD_PORT  	DIO_PORTD

#define KEYPAD_ROW0     DIO_PIN0
#define KEYPAD_ROW1     DIO_PIN1
#define KEYPAD_ROW2     DIO_PIN2
#define KEYPAD_ROW3     DIO_PIN3

#define KEYPAD_COL0     DIO_PIN4
#define KEYPAD_COL1     DIO_PIN5
#define KEYPAD_COL2     DIO_PIN6
#define KEYPAD_COL3     DIO_PIN7

#define KEYPAD_ROW_SIZE	4
#define KEYPAD_COL_SIZE	4

#define KEY_NO_PRESS	0xFF

/*			Keys Configuration				*/
#define KPD_KEYS  		{						  \
						{ '7' , '8' , '9' , 'A' },\
						{ '4' , '5' , '6' , 'B' },\
						{ '1' , '2' , '3' , 'C' },\
						{ 'X' , '0'  , '=' ,'D' } \
						}
/*			APIS							*/

void KPD_voidInit(void);
u8 	 KPD_u8GetPressedKey(void);



#endif /* HAL_KEYPAD_KEYPAD_H_ */
