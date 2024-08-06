/*
 * LCD.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Mostafa Sayed
 */

#include "LCD.h"

void LCD_voidInit		(void)
{
	_delay_ms(35);	/* Power On Delay */
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RS,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_E,DIO_OUTPUT);
	DIO_voidSetPinDirection(LCD_CONTROL_PORT,LCD_RW,DIO_OUTPUT);
	#if (MODE == BIT_4)
		DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_D4,DIO_OUTPUT);
		DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_D5,DIO_OUTPUT);
		DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_D6,DIO_OUTPUT);
		DIO_voidSetPinDirection(LCD_DATA_PORT,LCD_D7,DIO_OUTPUT);;
		LCD_voidSendCommand(BIT_4_LINE_2_FORMAT_5X8);
		_delay_us(50);


	#else
		DIO_voidSetPortDirection(LCD_DATA_PORT,0xFF);

		LCD_voidSendCommand(BIT_8_LINE_2_FORMAT_5X8);
		_delay_us(50);

	#endif

	LCD_voidSendCommand(DIS_ON_CUR_ON_BLINK_OFF);
	_delay_us(50);

	LCD_voidSendCommand(CLR_DISPLAY);
	_delay_ms(2);

	LCD_voidSendCommand(ENTRY_CUR_RIGHT_SCR_RIGHT);
	_delay_us(50);

	LCD_voidSendCommand(RETURN_HOME);
	_delay_ms(2);

}

void LCD_voidSendCommand(u8 Copy_u8Command)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_LOW);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);

	#if (MODE == BIT_4)

		DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D4,(GET_BIT(Copy_u8Command,4)));
		DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D5,(GET_BIT(Copy_u8Command,5)));
		DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D6,(GET_BIT(Copy_u8Command,6)));
		DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D7,(GET_BIT(Copy_u8Command,7)));

		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_LOW);
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_HIGH);
		_delay_us(1);
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_LOW);

		DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D4,(GET_BIT(Copy_u8Command,0)));
		DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D5,(GET_BIT(Copy_u8Command,1)));
		DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D6,(GET_BIT(Copy_u8Command,2)));
		DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D7,(GET_BIT(Copy_u8Command,3)));

		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_LOW);
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_HIGH);
		_delay_us(1);
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_LOW);

	#else

		DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Command);

		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_LOW);
		_delay_us(2);
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_HIGH);
		_delay_us(2);
		DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_LOW);

	#endif

	_delay_us(50);
}

void LCD_voidSendChar	(u8 Copy_u8Char)
{
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RS,DIO_HIGH);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_RW,DIO_LOW);

		#if (MODE == BIT_4)

			DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D4,(GET_BIT(Copy_u8Char,4)));
			DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D5,(GET_BIT(Copy_u8Char,5)));
			DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D6,(GET_BIT(Copy_u8Char,6)));
			DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D7,(GET_BIT(Copy_u8Char,7)));

			DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_HIGH);
			_delay_us(2);
			DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_LOW);
			_delay_us(20);

			DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D4,(GET_BIT(Copy_u8Char,0)));
			DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D5,(GET_BIT(Copy_u8Char,1)));
			DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D6,(GET_BIT(Copy_u8Char,2)));
			DIO_voidSetPinValue(LCD_DATA_PORT,LCD_D7,(GET_BIT(Copy_u8Char,3)));

			DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_HIGH);
			_delay_us(2);
			DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_LOW);
			_delay_us(20);

		#else

			DIO_voidSetPortValue(LCD_DATA_PORT,Copy_u8Char);

			DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_LOW);
			_delay_us(2);
			DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_HIGH);
			_delay_us(2);
			DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,DIO_LOW);

		#endif

	_delay_us(50);
}

void LCD_voidSetLocation(u8 Copy_u8LineNum, u8 Copy_u8CharacterNumber)
{

	if(Copy_u8LineNum == LCD_LINE1)
	{
		Copy_u8CharacterNumber = (Copy_u8CharacterNumber ) + 0x80;
	}
	else if(Copy_u8LineNum == LCD_LINE2)
	{
		Copy_u8CharacterNumber = (Copy_u8CharacterNumber ) + 0xC0;
	}
	else if(Copy_u8LineNum == LCD_LINE3)
	{
		Copy_u8CharacterNumber = (Copy_u8CharacterNumber ) + 0x90;
	}
	else if(Copy_u8LineNum == LCD_LINE4)
	{
		Copy_u8CharacterNumber = (Copy_u8CharacterNumber ) + 0xD0;
	}
	LCD_voidSendCommand(Copy_u8CharacterNumber);

}

void LCD_voidSendString(u8* Copy_u8String)
{
	u8 counter = 0;
	while(Copy_u8String[counter] != '\0')
	{
		LCD_voidSendChar(Copy_u8String[counter]);
		counter++;
	}
}

void LCD_voidSendNumber(u32 Copy_u32Number)
{
	u8 str[15] ;
	u32 temp = 0;
	u8 len = 0 , counter = 0;
	temp = Copy_u32Number;
	while(temp > 0)
	{
		str[counter] = temp%10 + '0';
		temp = temp / 10;
		counter++;
		len++;
	}
	for(counter = 0 ;counter < len/2 ; counter++)
	{
		temp 		 	 = str[counter];
		str[counter]	 = str[len - counter - 1];
		str[len - counter - 1] = temp;
	}
	str[len] = '\0';
	LCD_voidSendString(str);
	if(Copy_u32Number == 0)		LCD_voidSendChar('0');
}

void LCD_voidClear(void){
	LCD_voidSendCommand(CLR_DISPLAY);
	_delay_ms(2);
}

void LCD_voidDrawSpecialChar(u8 Copy_u8CharIndex,u8* Copy_u8SpecialChar)
{
	u8 LCD_u8Counter = 0;

	LCD_voidSendCommand(0x80 + Copy_u8CharIndex*8);
	_delay_us(40);
	for(LCD_u8Counter = 0 ; LCD_u8Counter < 8 ; LCD_u8Counter++)
	{
		LCD_voidSendChar(Copy_u8SpecialChar[LCD_u8Counter]);
	}
}

void LCD_voidSendSpecialChar(u8 Copy_u8CharIndex)
{
	LCD_voidSendChar(Copy_u8CharIndex);
}
