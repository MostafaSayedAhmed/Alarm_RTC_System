/*
 * KEYPAD.c
 *
 *  Created on: Aug 17, 2023
 *      Author: Mostafa Sayed
 */
#include "KEYPAD.h"

static u8 Array[KEYPAD_ROW_SIZE][KEYPAD_COL_SIZE] =	 KPD_KEYS;

static u8 KPD_Au8RowPins[4] = { KEYPAD_ROW0 , KEYPAD_ROW1 , KEYPAD_ROW2 , KEYPAD_ROW3 };
static u8 KPD_Au8ColPins[4] = { KEYPAD_COL0 , KEYPAD_COL1 , KEYPAD_COL2 , KEYPAD_COL3 };

void KPD_voidInit(void)
{
	u8 rowCounter = 0 , columnCounter = 0;
	// Row Configuration
	for(rowCounter = 0; rowCounter < KEYPAD_ROW_SIZE; rowCounter++ )
	{
		DIO_voidSetPinDirection(KEYPAD_PORT,KPD_Au8RowPins[rowCounter],DIO_INPUT_PULLUP);
	}

	// Column Configuration
	for(columnCounter = 0; columnCounter < KEYPAD_COL_SIZE; columnCounter++ )
	{
		DIO_voidSetPinDirection(KEYPAD_PORT,KPD_Au8ColPins[columnCounter],DIO_OUTPUT);
		DIO_voidSetPinValue(KEYPAD_PORT,KPD_Au8ColPins[columnCounter] ,DIO_HIGH);
	}

}

u8 KPD_u8GetPressedKey(void)
{
	u8 flag = 1 , output = KEY_NO_PRESS;
	u8 rowCounter = 0 , columnCounter = 0;

	for(rowCounter = 0 ; rowCounter < KEYPAD_ROW_SIZE ; rowCounter++)
	{
		for(columnCounter = 0 ; columnCounter < KEYPAD_COL_SIZE ; columnCounter++)
		{
			DIO_voidSetPinValue(KEYPAD_PORT,KPD_Au8ColPins[columnCounter],DIO_LOW);
			while(DIO_u8GetPinValue(KEYPAD_PORT , KPD_Au8RowPins[rowCounter]) == 0)
					{
						_delay_ms(25);
						if(DIO_u8GetPinValue(KEYPAD_PORT , KPD_Au8RowPins[rowCounter]) == 0)
						{
							output = Array[rowCounter][columnCounter];
							flag = 0;
							}
						else
						{
							break;
						}
					}
			if(flag == 0)
			{
				break;
			}
			DIO_voidSetPinValue(KEYPAD_PORT,KPD_Au8ColPins[columnCounter],DIO_HIGH);
		}
		if(flag == 0)
		{
			break;
		}
	}
	return (u8) output;
}

