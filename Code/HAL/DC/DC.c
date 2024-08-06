/*
 * DC_Motor.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Mostafa Sayed
 */

#include "DC.h"

void DC_voidInit(void)
{
	DIO_voidSetPinDirection(DC_PORT,DC_DIR1,DIO_OUTPUT);
	DIO_voidSetPinDirection(DC_PORT,DC_DIR2,DIO_OUTPUT);
}
void DC_voidRotate( DC_direction Copy_direction, u8 Copy_u8Speed)
{
	if(Copy_direction == DC_CW)
	{
		DIO_voidSetPinValue(DC_PORT,DC_DIR1,DIO_HIGH);
		DIO_voidSetPinValue(DC_PORT,DC_DIR2,DIO_LOW);
	}
	else if (Copy_direction == DC_CCW)
	{
		DIO_voidSetPinValue(DC_PORT,DC_DIR1,DIO_LOW);
		DIO_voidSetPinValue(DC_PORT,DC_DIR2,DIO_HIGH);
	}
	else
	{
		DIO_voidSetPinValue(DC_PORT,DC_DIR1,DIO_LOW);
		DIO_voidSetPinValue(DC_PORT,DC_DIR2,DIO_LOW);
	}
}
