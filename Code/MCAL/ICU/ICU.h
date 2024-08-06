/*
 * ICU.h
 *
 *  Created on: Aug 26, 2023
 *      Author: Mostafa Sayed
 */

#ifndef MCAL_ICU_ICU_H_
#define MCAL_ICU_ICU_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"

/***********************************************************************************/
/***********************************************************************************/
#define ICU_FALLING_EDGE 	0
#define ICU_RISING_EDGE 	1

/******************************************* APIs **********************************************************/

void ICU_voidInit			 (void);
void ICU_voidChangeTrigger	 (u8 Copy_u8Trigger);
void ICU_voidSetCallback  	 (void (*Copy_pf)(void));
u16  ICU_u16ReadICU		  	 (void);
void ICU_voidDisableInterrupt(void);
void ICU_voidEnableInterrupt (void);


#endif /* MCAL_ICU_ICU_H_ */
