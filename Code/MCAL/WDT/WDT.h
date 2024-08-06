/*
 * WDT.h
 *
 *  Created on: Aug 26, 2023
 *      Author: Mostafa Sayed
 */

#ifndef MCAL_WDT_WDT_H_
#define MCAL_WDT_WDT_H_

#include "../../LIB/STD_Types.h"
#include "../../LIB/BIT_Math.h".h"
/******************************************* Waiting Time ***********************************************/

#define WDT_PRESCALER_16_3_ms				0
#define WDT_PRESCALER_32_5_ms				1
#define WDT_PRESCALER_65_ms					2
#define WDT_PRESCALER_130_ms				3
#define WDT_PRESCALER_260_ms				4
#define WDT_PRESCALER_520_ms				5
#define WDT_PRESCALER_1_s					6
#define WDT_PRESCALER_2_1_s					7

/********************************************* APIs ****************************************************/

void WDT_voidEnable (u8 Copy_u8WaitingTime);
void WDT_voidDisable(void);


#endif /* MCAL_WDT_WDT_H_ */
