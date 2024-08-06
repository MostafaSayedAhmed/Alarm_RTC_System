/*
 * Interrupt.h
 *
 *  Created on: Aug 21, 2023
 *      Author: Mostafa Sayed
 */

#ifndef MCAL_INTERRUPT_INT_H_
#define MCAL_INTERRUPT_INT_H_

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include "../DIO/DIO.h"

#define ISR(vector,...)   \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)

#define EXTI0			__vector_ ## 1
#define EXTI1			__vector_ ## 2
#define EXTI2			__vector_ ## 18

#define SREG			(*(volatile u8*) (0x3F + 0x20))
#define I				7

#define MCUCR			(*(volatile u8*) (0x35 + 0x20))
#define ISC11			3
#define ISC10			2
#define ISC01			1
#define ISC00			0

#define MCUCSR			(*(volatile u8*) (0x34 + 0x20))
#define ISC2			6

#define GICR			(*(volatile u8*) (0x3B + 0x20))
#define INT1			7
#define INT0			6
#define INT2			5

#define GIFR			(*(volatile u8*) (0x3A + 0x20))
#define INTF1			7
#define INTF0			6
#define INTF2			5


#define INT_INT0		0
#define INT_INT1		1
#define INT_INT2		2

/*	 	Sense		*/
#define INT_LOW			0
#define INT_CHANGE		1
#define INT_FALL		2
#define INT_RISE		3


#define NULL	((void *) 0LL)

/*   	APIs		   */

void INT_voidInitINIT0(u8 Copy_u8Sense);
void INT_voidInitINIT1(u8 Copy_u8Sense);
void INT_voidInitINIT2(u8 Copy_u8Sense);

void INT_voidSetCallBackFunctionINT0(void (*ptr2Fun) (void));
void INT_voidSetCallBackFunctionINT1(void (*ptr2Fun) (void));
void INT_voidSetCallBackFunctionINT2(void (*ptr2Fun) (void));

void INT_voidDisableINT0(void);
void INT_voidDisableINT1(void);
void INT_voidDisableINT2(void);


#endif /* MCAL_INTERRUPT_INT_H_ */
