/*
 * STP.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Mostafa Sayed
 */

#include "STP.h"
#include <util/delay.h>

static void step1(void)
{
	DIO_voidSetPinValue(STP_PORT,STP_BLUE,DIO_HIGH);
	DIO_voidSetPinValue(STP_PORT,STP_PINK,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_YELLOW,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_ORANGE,DIO_LOW);
}
static void step1_5(void)
{
	DIO_voidSetPinValue(STP_PORT,STP_BLUE,DIO_HIGH);
	DIO_voidSetPinValue(STP_PORT,STP_PINK,DIO_HIGH);
	DIO_voidSetPinValue(STP_PORT,STP_YELLOW,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_ORANGE,DIO_LOW);
}
static void step2(void)
{
	DIO_voidSetPinValue(STP_PORT,STP_BLUE,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_PINK,DIO_HIGH);
	DIO_voidSetPinValue(STP_PORT,STP_YELLOW,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_ORANGE,DIO_LOW);
}
static void step2_5(void)
{
	DIO_voidSetPinValue(STP_PORT,STP_BLUE,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_PINK,DIO_HIGH);
	DIO_voidSetPinValue(STP_PORT,STP_YELLOW,DIO_HIGH);
	DIO_voidSetPinValue(STP_PORT,STP_ORANGE,DIO_LOW);
}

static void step3(void)
{
	DIO_voidSetPinValue(STP_PORT,STP_BLUE,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_PINK,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_YELLOW,DIO_HIGH);
	DIO_voidSetPinValue(STP_PORT,STP_ORANGE,DIO_LOW);
}
static void step3_5(void)
{
	DIO_voidSetPinValue(STP_PORT,STP_BLUE,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_PINK,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_YELLOW,DIO_HIGH);
	DIO_voidSetPinValue(STP_PORT,STP_ORANGE,DIO_HIGH);
}
static void step4(void)
{
	DIO_voidSetPinValue(STP_PORT,STP_BLUE,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_PINK,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_YELLOW,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_ORANGE,DIO_HIGH);
}
static void step4_5(void)
{
	DIO_voidSetPinValue(STP_PORT,STP_BLUE,DIO_HIGH);
	DIO_voidSetPinValue(STP_PORT,STP_PINK,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_YELLOW,DIO_LOW);
	DIO_voidSetPinValue(STP_PORT,STP_ORANGE,DIO_HIGH);
}

void (*ptrfun[8])(void) = {step1,step1_5,step2,step2_5,step3,step3_5,step4,step4_5};

void STP_voidInit(void)
{
	DIO_voidSetPinDirection(STP_PORT,STP_BLUE,DIO_OUTPUT);
	DIO_voidSetPinDirection(STP_PORT,STP_PINK,DIO_OUTPUT);
	DIO_voidSetPinDirection(STP_PORT,STP_YELLOW,DIO_OUTPUT);
	DIO_voidSetPinDirection(STP_PORT,STP_ORANGE,DIO_OUTPUT);
}

void STP_voidRotate(STP_direction Copy_direction)
{
	u8 counter = 0;
	if(Copy_direction == STP_CW)
	{
		for(counter = 0 ; counter < 8 ;counter++)
		{
			ptrfun[counter]();
			_delay_ms(10);
		}
	}
	else if(Copy_direction == STP_CCW)
	{
		for(counter = 0 ; counter < 8 ;counter++)
		{
			ptrfun[7 - counter]();
			_delay_ms(10);
		}
	}
	else
	{

	}
}

void STP_voidSetAngle(u16 Copy_u16Angle)
{
	u32 maxCount = Copy_u16Angle / STP_STEP_ANGLE;
	u32 counter = 0;
	for(counter = 0; counter <= maxCount + 1 ; counter++)
	{
		ptrfun[counter%8]();
		_delay_ms(10);
	}

}

