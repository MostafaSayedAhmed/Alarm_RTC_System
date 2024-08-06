/*
 * main.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Mostafa Sayed
 */

#include "HAL/LCD/LCD.h"
#include "HAL/RTC/RTC.h"
#include "HAL/Keypad/KEYPAD.h"
#include "HAL/EEPROM/EEPROM.h"

#include "MCAL/Timer/Timer.h"
#include "MCAL/DIO/DIO.h"

#define BCD2DEC(VAL)			VAL = (VAL >> 4)*10 + (VAL & 0x0F)

#define EEPROM_ALARM_SECONDS	0x00
#define EEPROM_ALARM_MINUTES	0x04
#define EEPROM_ALARM_HOURS		0x08

void OVF_Fun (void);
void TIM_Display (void);

void Menu		   (void);
void Alarm_Function(void);
void Timer_Function(void);

void SecondInput(void);
void MinuteInput(void);
void HourInput  (void);

u8 Global_u8Seconds = 0;
u8 Global_u8SecFlag = 1;

u8 Global_u8Minutes = 0;
u8 Global_u8MinFlag = 1;

u8 Global_u8Hours = 0;
u8 Global_u8HrFlag = 1;

u8 Global_u8AlarmFlag = 0;


u8 mode = 0;

void (*ptr2Fun[3])(void) = {Menu,Alarm_Function,Timer_Function};

int main(void)
{
	RTC_voidInit();
	LCD_voidInit();
	KPD_voidInit();

	TIM0_voidInit();
	TIM0_voidSetPreValue(64);
	TIM0_voidOVFINTControl(TIM0_INT_ENABLE);
	TIM0_voidSetCallBackOVF(OVF_Fun);
	TIM0_voidTimerStart(TIM0_CLK_DIV_8);

	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN7,DIO_OUTPUT);

	u8 Local_u8Key = KEY_NO_PRESS;


	Global_u8Hours   = EEPROM_u8Read(EEPROM_ALARM_HOURS);
	Global_u8Minutes = EEPROM_u8Read(EEPROM_ALARM_MINUTES);
	Global_u8Seconds = EEPROM_u8Read(EEPROM_ALARM_SECONDS);


	while(1)
	{
		while(Local_u8Key == KEY_NO_PRESS)
		{
			Local_u8Key = KPD_u8GetPressedKey();
		}
		switch(Local_u8Key)
		{
			case 'A':
				mode = 1;
				Global_u8SecFlag = 1;
				Global_u8MinFlag = 1;
				Global_u8HrFlag  = 1;

				Global_u8Seconds = 0;
				Global_u8Minutes = 0;
				Global_u8Hours = 0;

				while(Global_u8SecFlag)	SecondInput();
				while(Global_u8MinFlag)	MinuteInput();
				while(Global_u8HrFlag)	HourInput  ();


				break;
			case 'B':
				mode = 2;
				Global_u8SecFlag = 1;
				Global_u8MinFlag = 1;
				Global_u8HrFlag  = 1;

				Global_u8Seconds = 0;
				Global_u8Minutes = 0;
				Global_u8Hours   = 0;

				while(Global_u8SecFlag)	SecondInput();
				while(Global_u8MinFlag)	MinuteInput();
				while(Global_u8HrFlag)	HourInput  ();

				break;
			default:
				mode = 0;
				Local_u8Key = KEY_NO_PRESS;
		}
		Local_u8Key = KEY_NO_PRESS;

	}
}

void OVF_Fun (void)
{
	static u16 counter = 0 ;
	counter++;
	if(counter == 3906)
	{
		TIM_Display();
		DIO_voidTogglePinValue(DIO_PORTB,DIO_PIN3);
		counter = 0;
		TIM0_voidSetPreValue(64);
		if(Global_u8AlarmFlag >= 1)
		{
			DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_HIGH);
			Global_u8AlarmFlag++;
			if(Global_u8AlarmFlag == 5)
			{
				Global_u8AlarmFlag = 0;
				DIO_voidSetPinValue(DIO_PORTC,DIO_PIN7,DIO_LOW);
			}
		}

	}

}

void TIM_Display (void)
{
	u8 Local_u8Copy = 0;

	u8 Local_u8Seconds = 0;
	u8 Local_u8Minutes = 0;
	u8 Local_u8Hours   = 0;


	LCD_voidClear();
	LCD_voidSendString("Time = ");

	Local_u8Hours = RTC_u8ReadHours();
	BCD2DEC(Local_u8Hours);
	LCD_voidSendNumber(Local_u8Hours);
	LCD_voidSendChar(':');

	Local_u8Minutes = RTC_u8ReadMinutes();
	BCD2DEC(Local_u8Minutes);
	LCD_voidSendNumber(Local_u8Minutes);
	LCD_voidSendChar(':');

	Local_u8Seconds = RTC_u8ReadSeconds();
	BCD2DEC(Local_u8Seconds);
	LCD_voidSendNumber(Local_u8Seconds);

	LCD_voidSetLocation(LCD_LINE2,0);
	LCD_voidSendString("Date = ");

	Local_u8Copy = RTC_u8ReadYears();
	BCD2DEC(Local_u8Copy);
	LCD_voidSendNumber(Local_u8Copy);
	LCD_voidSendChar('-');

	Local_u8Copy = RTC_u8ReadMonths();
	BCD2DEC(Local_u8Copy);
	LCD_voidSendNumber(Local_u8Copy);
	LCD_voidSendChar('-');

	Local_u8Copy = RTC_u8ReadDays();
	BCD2DEC(Local_u8Copy);
	LCD_voidSendNumber(Local_u8Copy);
	LCD_voidSendChar(' ');


	if( (Local_u8Hours == Global_u8Hours) &&
		(Local_u8Minutes == Global_u8Minutes) &&
		(Local_u8Seconds == Global_u8Seconds))
	{
		Global_u8AlarmFlag = 1;
	}
	if( (!Global_u8SecFlag) && (!Global_u8MinFlag) && (!Global_u8HrFlag) && (2 == mode))
	{
		Global_u8Seconds += Local_u8Seconds;
		Global_u8Minutes += Local_u8Minutes;
		Global_u8Hours   += Local_u8Hours;
	}

	ptr2Fun[mode]();
}

void Menu		   (void)
{
	LCD_voidSetLocation(LCD_LINE3,0);
	LCD_voidSendString("A. Alarm");
	LCD_voidSetLocation(LCD_LINE4,0);
	LCD_voidSendString("B. Timer");
}

void SecondInput(void)
{
	u8 Local_u8Key = KEY_NO_PRESS;

	while(Local_u8Key == KEY_NO_PRESS)
	{
		Local_u8Key = KPD_u8GetPressedKey();
	}
	switch(Local_u8Key)
	{
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
			Global_u8Seconds = Global_u8Seconds * 10 +  (Local_u8Key - '0');
			if(Global_u8Seconds > 60)
				{
					Global_u8Seconds = Global_u8Seconds / 10;
					Global_u8SecFlag = 0;
				}
				break;
		case '=':
			Global_u8SecFlag = 0;
			break;
	}
}
void MinuteInput(void)
{
	u8 Local_u8Key = KEY_NO_PRESS;

	while(Local_u8Key == KEY_NO_PRESS)
	{
		Local_u8Key = KPD_u8GetPressedKey();
	}
	switch(Local_u8Key)
	{
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
			Global_u8Minutes = Global_u8Minutes * 10 +  (Local_u8Key - '0');
			if(Global_u8Minutes > 60)
				{
				Global_u8Minutes = Global_u8Minutes / 10;
				Global_u8MinFlag = 0;
				}
				break;
		case '=':
			Global_u8MinFlag = 0;
			break;
	}
}
void HourInput(void)
{
	u8 Local_u8Key = KEY_NO_PRESS;

	while(Local_u8Key == KEY_NO_PRESS)
	{
		Local_u8Key = KPD_u8GetPressedKey();
	}
	switch(Local_u8Key)
	{
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
			Global_u8Hours = Global_u8Hours * 10 +  (Local_u8Key - '0');
			if(Global_u8Hours > 24)
				{
				Global_u8Hours = Global_u8Hours / 10;
				Global_u8HrFlag = 0;
				}
				break;
		case '=':
			Global_u8HrFlag = 0;
			break;
	}
}

void Timer_Function(void)
{

	if(Global_u8SecFlag)
	{
		LCD_voidSetLocation(LCD_LINE3,0);
		LCD_voidSendString("Seconds :");
		LCD_voidSetLocation(LCD_LINE4,0);
		LCD_voidSendNumber(Global_u8Seconds);
	}
	else if(Global_u8MinFlag)
	{
		LCD_voidSetLocation(LCD_LINE3,0);
		LCD_voidSendString("Minutes :");
		LCD_voidSetLocation(LCD_LINE4,0);
		LCD_voidSendNumber(Global_u8Minutes);
	}
	else if(Global_u8HrFlag)
	{
		LCD_voidSetLocation(LCD_LINE3,0);
		LCD_voidSendString("Hours :");
		LCD_voidSetLocation(LCD_LINE4,0);
		LCD_voidSendNumber(Global_u8Hours);
	}
	else
	{
		mode = 0;
	}
	LCD_voidSetLocation(LCD_LINE3,8);
	LCD_voidSendString("Timer");
}

void Alarm_Function(void)
{
	if(Global_u8SecFlag)
	{
		LCD_voidSetLocation(LCD_LINE3,0);
		LCD_voidSendString("Seconds :");
		LCD_voidSetLocation(LCD_LINE4,0);
		LCD_voidSendNumber(Global_u8Seconds);
	}
	else if(Global_u8MinFlag)
	{
		LCD_voidSetLocation(LCD_LINE3,0);
		LCD_voidSendString("Minutes :");
		LCD_voidSetLocation(LCD_LINE4,0);
		LCD_voidSendNumber(Global_u8Minutes);
	}
	else if(Global_u8HrFlag)
	{
		LCD_voidSetLocation(LCD_LINE3,0);
		LCD_voidSendString("Hours :");
		LCD_voidSetLocation(LCD_LINE4,0);
		LCD_voidSendNumber(Global_u8Hours);
	}
	else
	{

		TIM0_voidTimerStop();

		EEPROM_voidWrite(EEPROM_ALARM_SECONDS,Global_u8Seconds);
		EEPROM_voidWrite(EEPROM_ALARM_MINUTES,Global_u8Minutes);
		EEPROM_voidWrite(EEPROM_ALARM_HOURS  ,Global_u8Hours);

		TIM0_voidTimerStart(TIM0_CLK_DIV_8);
		mode = 0;
	}
	LCD_voidSetLocation(LCD_LINE3,8);
	LCD_voidSendString("Alarm");
}
