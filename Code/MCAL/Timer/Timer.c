/*
 * Timer.c
 *
 *  Created on: Aug 23, 2023
 *      Author: Mostafa Sayed
 */

#include "Timer.h"

static ptr2fun_Iv_Ov 	TIM0_OVF = NULL;
static ptr2fun_Iv_Ov	TIM0_CMP = NULL;

void TIM0_voidInit		 	(void)
{
	/*		Select Mode 	*/

	#if		TIM0_MODE == TIM0_NORMAL
			CLR_BIT(TCCR0,WGM00);
			CLR_BIT(TCCR0,WGM01);
	#elif	TIM0_MODE == TIM0_CTC
			CLR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
	#elif	TIM0_MODE == TIM0_PWM_PHASE
			CLR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
	#elif	TIM0_MODE == TIM0_FAST_PWM
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
	#endif

}

void TIM0_voidSetPreValue	(u8 Copy_u8CounterStartVal)
{
	/*	 Set Timer Start Value		*/
	TCNT0 = Copy_u8CounterStartVal;
}

void TIM0_voidTimerStart 	(u8 Copy_u8Prescaler)
{
	TCCR0 &= 0b11111000;
	TCCR0 |= Copy_u8Prescaler;
}

void TIM0_voidOVFINTControl	(u8 Copy_u8InterruptConl)
{
	if(Copy_u8InterruptConl == TIM0_INT_DISABLE)
	{
		CLR_BIT(SREG,7);
		CLR_BIT(TIMSK,TOIE0);
	}
	else
	{
		SET_BIT(SREG,7);
		SET_BIT(TIMSK,TOIE0);
	}
}

void TIM0_voidCMPINTControl	(u8 Copy_u8InterruptConl)
{
	if(Copy_u8InterruptConl == TIM0_INT_DISABLE)
	{
		CLR_BIT(SREG,7);
		CLR_BIT(TIMSK,OCIE0);
	}
	else
	{
		SET_BIT(SREG,7);
		SET_BIT(TIMSK,OCIE0);
	}
}

void TIM0_voidSetCallBackOVF(ptr2fun_Iv_Ov Copy_voidptr2fun)
{
	if(Copy_voidptr2fun != NULL) 	TIM0_OVF = Copy_voidptr2fun;
}

void TIM0_voidSetCallBackCTC(ptr2fun_Iv_Ov Copy_voidptr2fun)
{
	if(Copy_voidptr2fun != NULL) 	TIM0_CMP = Copy_voidptr2fun;

}

void TIM0_voidSetCompareMat (u8 Copy_u8CmpMatVal,u8 Copy_u8HOC0PinAction)
{
	switch(Copy_u8HOC0PinAction)
	{
		case TIM0_OC0_TOG_PIN:
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);
		break;

		case TIM0_OC0_CLEAR_PIN:
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		break;

		case TIM0_OC0_SET_PIN:
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);
		break;

		default :
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);

	}
	TIM0_voidSetCmpValue(Copy_u8CmpMatVal);
}

void TIM0_voidSetCmpValue   (u8 Copy_u8CmpMatVal)
{
	OCR0 =  Copy_u8CmpMatVal;
}

void TIM0_voidDelayPolling	(void)
{

}

void TIM0_voidTimerStop		(void)
{
	TCCR0 &= 0b11111000;
}

ISR(TIMER0_OVF_vect)
{
	TIM0_OVF();
}

ISR(TIMER0_COMP_vect)
{
	TIM0_CMP();
}

void TIM0_voidPWMGenertaor	(u8 Copy_u8DutyCycle , u8 Copy_u8OC0PinAction)
{

	#if 	TIM0_MODE	== TIM0_FAST_PWM
			SET_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			if( Copy_u8OC0PinAction == TIM0_OC0_SET_CMP_CLR_OVF)
			{
				SET_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);
				Copy_u8DutyCycle = 256 - (Copy_u8DutyCycle/100.0)*256;
			}
			else
			{
				CLR_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);
				Copy_u8DutyCycle = (Copy_u8DutyCycle/100.0)*256;

			}
			OCR0 = Copy_u8DutyCycle;
	#elif	TIM0_MODE 	== TIM0_PWM_PHASE
			CLR_BIT(TCCR0,WGM00);
			SET_BIT(TCCR0,WGM01);
			if( Copy_u8OC0PinAction == TIM0_OC0_SET_UPC_CLR_DWC)
			{
				SET_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);
				Copy_u8DutyCycle = 510 - (Copy_u8DutyCycle/100.0)*510;

			}
			else
			{
				CLR_BIT(TCCR0,COM00);
				SET_BIT(TCCR0,COM01);
				Copy_u8DutyCycle= (Copy_u8DutyCycle/100.0)*510;
			}
			OCR0 = Copy_u8DutyCycle;
	#endif

}

