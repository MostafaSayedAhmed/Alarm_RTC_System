/*
 * ICU.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Mostafa Sayed
 */
#include "ICU.h"

static void (*ICU_pf)(void);

void ICU_voidInit			 (void)
{

	/*  Select Timer 1 Normal Mode	*/
	CLR_BIT(TCCR1A,WGM10);
	CLR_BIT(TCCR1A,WGM11);
	CLR_BIT(TCCR1B,WGM12);
	CLR_BIT(TCCR1B,WGM13);

	/* Pre-Scaler()	*/
	TCCR1B &= 0xF8;
	TCCR1B |= 0x02;

	SET_BIT(TIMSK,TICIE1);

	SET_BIT(TCCR1B,ICES1);

}

void ICU_voidChangeTrigger	 (u8 Copy_u8Trigger)
{
	switch(Copy_u8Trigger)
	{
		case ICU_FALLING_EDGE : CLR_BIT(TCCR1B,ICES1); break;
		case ICU_RISING_EDGE  : SET_BIT(TCCR1B,ICES1); break;
	}
}

void ICU_voidSetCallback  	 (void (*Copy_pf)(void))
{
	ICU_pf = Copy_pf;
}

u16  ICU_u16ReadICU		  	 (void)
{
	return ICR1;
}

void ICU_voidDisableInterrupt(void)
{
	CLR_BIT(TIMSK,TICIE1);
}

ISR(TIMER1_CAPT_vect)
{
	ICU_pf();
}

void ICU_voidEnableInterrupt (void)
{
	SET_BIT(TIMSK,TICIE1);
}
