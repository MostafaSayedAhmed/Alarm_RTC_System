/*
 * INT.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Mostafa Sayed
 */

#include "INT.h"

static void (*INT0_Fun)(void) = NULL;
static void (*INT1_Fun)(void) = NULL;
static void (*INT2_Fun)(void) = NULL;

void INT_voidInitINIT0(u8 Copy_u8Sense)
{
	SET_BIT(SREG,I);
	SET_BIT(GICR,INT0);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT_PULLUP);

	switch(Copy_u8Sense)
	{
		case	INT_LOW:
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
		break;

		case	INT_CHANGE:
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
		break;

		case	INT_FALL:
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		break;

		case	INT_RISE:
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
		break;
	}
}
void INT_voidInitINIT1(u8 Copy_u8Sense)
{
	SET_BIT(SREG,I);
	SET_BIT(GICR,INT1);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT_PULLUP);


	switch(Copy_u8Sense)
	{
		case	INT_LOW:
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
		break;

		case	INT_CHANGE:
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
		break;

		case	INT_FALL:
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		break;

		case	INT_RISE:
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
		break;
	}
}
void INT_voidInitINIT2(u8 Copy_u8Sense)
{
	SET_BIT(SREG,I);
	SET_BIT(GICR,INT2);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_INPUT_PULLUP);


	switch(Copy_u8Sense)
	{
		case	INT_FALL:
			CLR_BIT(MCUCSR,ISC2);
		break;

		case	INT_RISE:
			SET_BIT(MCUCSR,ISC2);
		break;
	}
}

void INT_voidSetCallBackFunctionINT0(void (*ptr2Fun) (void))
{
	if(ptr2Fun != NULL)
	{
		INT0_Fun = ptr2Fun;
	}
}
void INT_voidSetCallBackFunctionINT1(void (*ptr2Fun) (void))
{
	if(ptr2Fun != NULL)
	{
		INT1_Fun = ptr2Fun;
	}
}
void INT_voidSetCallBackFunctionINT2(void (*ptr2Fun) (void))
{
	if(ptr2Fun != NULL)
	{
		INT2_Fun = ptr2Fun;
	}
}

void INT_voidDisableINT0(void)
{
	CLR_BIT(GICR,INT0);
}

void INT_voidDisableINT1(void)
{
	CLR_BIT(GICR,INT1);
}

void INT_voidDisableINT2(void)
{
	CLR_BIT(GICR,INT2);
}

ISR(EXTI0)
{
	if(INT0_Fun != NULL)	INT0_Fun();
}

ISR(EXTI1)
{
	if(INT1_Fun != NULL)	INT1_Fun();
}

ISR(EXTI2)
{
	if(INT2_Fun != NULL)	INT2_Fun();
}

