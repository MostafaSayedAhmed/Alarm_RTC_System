/*
 * SSD.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Mostafa Sayed
 */


#include "SSD.h"

static u8 seg7[] = SEGMENT_ARRAY;

void SSD_voidInit(u8 Copy_u8Port)
{
	DIO_voidSetPortDirection(Copy_u8Port,0XFF);
}

void SSD_voidSend(u8 Copy_u8Port,u8 Copy_u8Num)
{
	DIO_voidSetPortValue(Copy_u8Port,seg7[Copy_u8Num]);
}

