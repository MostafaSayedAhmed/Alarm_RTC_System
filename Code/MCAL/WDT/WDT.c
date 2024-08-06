/*
 * WDT.c
 *
 *  Created on: Aug 26, 2023
 *      Author: Mostafa Sayed
 */

#include "WDT.h"
#include <avr/io.h>

void WDT_voidEnable (u8 Copy_u8WaitingTime)
{
	/* Enable Watch-dog */
	SET_BIT(WDTCR,WDE);

	/* Select Prescaler	*/
	WDTCR &= 0xF8;
	WDTCR |= Copy_u8WaitingTime;
}

void WDT_voidDisable(void)
{

	/*	Write Logical one to WDTOE and WDE	*/
	WDTCR |= (1<< WDE) | (1<< WDTOE);
	/*	Turn off WDT	*/
	WDTCR = 0x00;

}

