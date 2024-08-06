// Program file
// 	Implementation of API
/*
 * Dio.c
 *
 *  Created on: Aug 15, 2023
 *      Author: Mostafa Sayed
 */

#include "DIO.h"

void DIO_voidSetPinDirection(u8 Copy_u8Port , u8 Copy_u8Pin, u8 Copy_u8Direction )	// DDR
{
	if(Copy_u8Pin < 8 && Copy_u8Pin >= 0)
	{
		if(Copy_u8Direction == DIO_INPUT)
		{
			switch(Copy_u8Port){
			case DIO_PORTA:
				CLR_BIT(DDRA,Copy_u8Pin);
				CLR_BIT(PORTA,Copy_u8Pin);
			break;

			case DIO_PORTB:
				CLR_BIT(DDRB,Copy_u8Pin);
				CLR_BIT(PORTB,Copy_u8Pin);
			break;

			case DIO_PORTC:
				CLR_BIT(DDRC,Copy_u8Pin);
				CLR_BIT(PORTC,Copy_u8Pin);
			break;

			case DIO_PORTD:
				CLR_BIT(DDRD,Copy_u8Pin);
				CLR_BIT(PORTD,Copy_u8Pin);
			break;

			default:
			/* Do Nothing */
			break;
			}
		}
		else if(Copy_u8Direction == DIO_INPUT_PULLUP)
		{
			switch(Copy_u8Port){
				case DIO_PORTA:
					CLR_BIT(DDRA,Copy_u8Pin);
					SET_BIT(PORTA,Copy_u8Pin);
				break;

				case DIO_PORTB:
					CLR_BIT(DDRB,Copy_u8Pin);
					SET_BIT(PORTB,Copy_u8Pin);
				break;

				case DIO_PORTC:
					CLR_BIT(DDRC,Copy_u8Pin);
					SET_BIT(PORTC,Copy_u8Pin);
				break;

				case DIO_PORTD:
					CLR_BIT(DDRD,Copy_u8Pin);
					SET_BIT(PORTD,Copy_u8Pin);
				break;

				default:
				/* Do Nothing */
				break;
				}
		}
		else if(Copy_u8Direction == DIO_OUTPUT)
		{
			switch(Copy_u8Port)
			{
				case DIO_PORTA: SET_BIT(DDRA,Copy_u8Pin); break;
				case DIO_PORTB: SET_BIT(DDRB,Copy_u8Pin); break;
				case DIO_PORTC: SET_BIT(DDRC,Copy_u8Pin); break;
				case DIO_PORTD: SET_BIT(DDRD,Copy_u8Pin); break;
				default       : /* Do Nothing */        ; break;
			}
		}
	}
	else
	{
		/* Do Nothing */
	}

}
void DIO_voidSetPinValue	(u8 Copy_u8Port , u8 Copy_u8Pin, u8 Copy_u8Value ) // PORT
{

	if(Copy_u8Pin < 8 && Copy_u8Pin >= 0)
		{
			if(Copy_u8Value == DIO_LOW)
			{
				switch(Copy_u8Port){
				case DIO_PORTA: CLR_BIT(PORTA,Copy_u8Pin); break;

				case DIO_PORTB: CLR_BIT(PORTB,Copy_u8Pin); break;

				case DIO_PORTC: CLR_BIT(PORTC,Copy_u8Pin); break;

				case DIO_PORTD: CLR_BIT(PORTD,Copy_u8Pin); break;

				default: /* Do Nothing */ break;
				}
			}
			else if(Copy_u8Value == DIO_HIGH)
			{
				switch(Copy_u8Port){
				case DIO_PORTA: SET_BIT(PORTA,Copy_u8Pin); break;

				case DIO_PORTB: SET_BIT(PORTB,Copy_u8Pin); break;

				case DIO_PORTC: SET_BIT(PORTC,Copy_u8Pin); break;

				case DIO_PORTD: SET_BIT(PORTD,Copy_u8Pin); break;

				default: /* Do Nothing */ break;
					}
			}
		}
		else
		{
			/* Do Nothing */
		}
}
u8   DIO_u8GetPinValue		(u8 Copy_u8Port , u8 Copy_u8Pin)						// PIN
{
	u8 temp = 0xFF;
	if(Copy_u8Pin < 8 && Copy_u8Pin >= 0)
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA: temp = GET_BIT(PINA,Copy_u8Pin); break;

			case DIO_PORTB: temp = GET_BIT(PINB,Copy_u8Pin); break;

			case DIO_PORTC: temp = GET_BIT(PINC,Copy_u8Pin); break;

			case DIO_PORTD: temp = GET_BIT(PIND,Copy_u8Pin); break;

			default: /* Do Nothing */ break;
		}
	}
	else
	{
		/* Do Nothing */
	}
	return temp;
}

void DIO_voidTogglePinValue (u8 Copy_u8Port , u8 Copy_u8Pin)
{
	if(Copy_u8Pin < 8 && Copy_u8Pin >= 0)
	{
		switch(Copy_u8Port)
		{
			case DIO_PORTA:  TOG_BIT(PORTA,Copy_u8Pin); break;

			case DIO_PORTB:  TOG_BIT(PORTB,Copy_u8Pin); break;

			case DIO_PORTC:  TOG_BIT(PORTC,Copy_u8Pin); break;

			case DIO_PORTD:  TOG_BIT(PORTD,Copy_u8Pin); break;

			default: /* Do Nothing */ break;
		}
	}
	else
	{
		/* Do Nothing */
	}
}

/////////////////////////////////////Port///////////////////////////////////

void DIO_voidSetPortDirection(u8 Copy_u8Port , u8 Copy_u8Direction )
{
	switch(Copy_u8Port)
	{
		case DIO_PORTA:  DDRA = Copy_u8Direction  ; break;

		case DIO_PORTB:  DDRB = Copy_u8Direction ; break;

		case DIO_PORTC:  DDRC = Copy_u8Direction ; break;

		case DIO_PORTD:  DDRD = Copy_u8Direction ; break;

		default: /* Do Nothing */ break;
	}
}
void DIO_voidSetPortValue	 (u8 Copy_u8Port , u8 Copy_u8Value )
{
	switch(Copy_u8Port)
	{
		case DIO_PORTA:  PORTA = Copy_u8Value  ; break;

		case DIO_PORTB:  PORTD = Copy_u8Value ; break;

		case DIO_PORTC:  PORTC = Copy_u8Value ; break;

		case DIO_PORTD:  PORTD = Copy_u8Value ; break;

		default: /* Do Nothing */ break;
	}
}

void DIO_voidTogPortValue	 (u8 Copy_u8Port  )
{
	u8 Local_u8Temp = Copy_u8Port;
	switch(Copy_u8Port)
	{
		case DIO_PORTA:  PORTA = ~Local_u8Temp  ; break;

		case DIO_PORTB:  PORTD = ~Local_u8Temp ; break;

		case DIO_PORTC:  PORTC = ~Local_u8Temp ; break;

		case DIO_PORTD:  PORTD = ~Local_u8Temp ; break;

		default: /* Do Nothing */ break;
	}
}

u8   DIO_u8GetPortValue		 (u8 Copy_u8Port )
{
	u8 temp = 0xFF;
	switch(Copy_u8Port)
	{
		case DIO_PORTA:  temp = PINA  ; break;

		case DIO_PORTB:  temp = PINB ; break;

		case DIO_PORTC:  temp = PINC ; break;

		case DIO_PORTD:  temp = PIND ; break;

		default: /* Do Nothing */ break;
	}

	return temp;
}


