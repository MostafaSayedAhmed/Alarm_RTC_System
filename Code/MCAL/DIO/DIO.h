// Interface file
// 	Macros for user
// 	Prototypes
/*
 * Dio.h
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Sayed
 */

#ifndef DIO_DIO_H_
#define DIO_DIO_H_

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"


/*****************************Registers****************************/
// PORT Register
	#define PORTA (*(volatile u8* ) (0x1B + 0x20))
	#define PORTB (*(volatile u8* ) (0x18 + 0x20))
	#define PORTC (*(volatile u8* ) (0x15 + 0x20))
	#define PORTD (*(volatile u8* ) (0x12 + 0x20))

// DDR Register
	#define DDRA  (*(volatile u8* ) (0x1A + 0x20))
	#define DDRB  (*(volatile u8* ) (0x17 + 0x20))
	#define DDRC  (*(volatile u8* ) (0x14 + 0x20))
	#define DDRD  (*(volatile u8* ) (0x11 + 0x20))

// PIN Register
	#define PINA  (*(volatile u8* ) (0x19 + 0x20))
	#define PINB  (*(volatile u8* ) (0x16 + 0x20))
	#define PINC  (*(volatile u8* ) (0x13 + 0x20))
	#define PIND  (*(volatile u8* ) (0x10 + 0x20))


/*********************************Macros**************************/

// Direction
	#define DIO_INPUT_PULLUP 2
	#define DIO_OUTPUT       1
	#define DIO_INPUT        0

// Pin Numbers
	#define DIO_PIN0         0
	#define DIO_PIN1         1
	#define DIO_PIN2         2
	#define DIO_PIN3         3
	#define DIO_PIN4         4
	#define DIO_PIN5         5
	#define DIO_PIN6         6
	#define DIO_PIN7         7

// Port Numbers
	#define DIO_PORTA   	 0
	#define DIO_PORTB   	 1
	#define DIO_PORTC   	 2
	#define DIO_PORTD   	 3

// Value
	#define DIO_LOW     	 0
	#define DIO_HIGH    	 1


/********************************   APIs  ************************/

// Pin Functions
	void DIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin, u8 Copy_u8Direction ); // DDR
	void DIO_voidSetPinValue	(u8 Copy_u8Port , u8 Copy_u8Pin, u8 Copy_u8Value );     // PORT
	u8   DIO_u8GetPinValue		(u8 Copy_u8Port , u8 Copy_u8Pin);						// PIN
	void DIO_voidTogglePinValue (u8 Copy_u8Port , u8 Copy_u8Pin);

// Port Functions
	void DIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction ); // DDR
	void DIO_voidSetPortValue	 (u8 Copy_u8Port , u8 Copy_u8Value );     // PORT
	void DIO_voidTogPortValue	 (u8 Copy_u8Port  );
	u8   DIO_u8GetPortValue		 (u8 Copy_u8Port );						  // PIN



/*****************************************************************/


#endif /* DIO_DIO_H_ */
