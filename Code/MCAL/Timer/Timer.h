/*
 * Timer.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Mostafa Sayed
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"

/*		Macros			*/
/******************** Modes *****************************/
#define TIM0_NORMAL			0
#define TIM0_CTC			1
#define TIM0_PWM_PHASE		2
#define TIM0_FAST_PWM		3

/********************** Prescalar ***********************/
#define TIM0_NO_CLK			0
#define TIM0_CLK			1
#define TIM0_CLK_DIV_8		2
#define TIM0_CLK_DIV_64		3
#define TIM0_CLK_DIV_256	4
#define TIM0_CLK_DIV_1024	5
#define TIM0_EXT_FALL		6
#define TIM0_EXT_RISE		7

/********************* Interrupt Control *****************/

#define TIM0_INT_DISABLE	0
#define TIM0_INT_ENABLE		1

/********************* OC0 Pin Actions (Normal CTC) ******/

#define	TIM0_OC0_IN_OUT_PIN		0
#define	TIM0_OC0_TOG_PIN		1
#define	TIM0_OC0_CLEAR_PIN		2
#define	TIM0_OC0_SET_PIN		3

/*********************	CFG	*****************************/
#define TIM0_MODE			TIM0_FAST_PWM
/*	TIM0_NORMAL	TIM0_CTC TIM0_PWM_PHASE	TIM0_FAST_PWM	*/
/********************* OC0 Pin Actions (FAST PWM) ******/

#define TIM0_OC0_SET_CMP_CLR_OVF		1
#define TIM0_OC0_CLR_CMP_SET_OVF		2

/********************* OC0 Pin Actions (PHASE PWM) ******/

#define TIM0_OC0_SET_UPC_CLR_DWC		1
#define TIM0_OC0_CLR_UPC_SET_DWC		2

/********************************************************/

/********************************************************/

/*		APIs			*/

void TIM0_voidInit		 	(void);
void TIM0_voidSetPreValue	(u8 Copy_u8CounterStartVal);
void TIM0_voidTimerStart 	(u8 Copy_u8Prescaler);
void TIM0_voidOVFINTControl	(u8 Copy_u8InterruptConl);
void TIM0_voidCMPINTControl	(u8 Copy_u8InterruptConl);
void TIM0_voidSetCallBackOVF(ptr2fun_Iv_Ov Copy_voidptr2fun);
void TIM0_voidSetCallBackCTC(ptr2fun_Iv_Ov Copy_voidptr2fun);
void TIM0_voidSetCompareMat (u8 Copy_u8CmpMatVal,u8 Copy_u8HOC0PinAction);
void TIM0_voidPWMGenertaor	(u8 Copy_u8DutyCycle , u8 Copy_u8OC0PinAction);
void TIM0_voidSetCmpValue   (u8 Copy_u8CmpMatVal);
void TIM0_voidDelayPolling	(void);
void TIM0_voidTimerStop		(void);


#endif /* MCAL_TIMER_TIMER_H_ */
