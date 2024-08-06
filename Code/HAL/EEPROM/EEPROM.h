/*
 * EEPROM.h
 *
 *  Created on: Sep 14, 2023
 *      Author: Mostafa Sayed
 */

#ifndef HAL_EEPROM_EEPROM_H_
#define HAL_EEPROM_EEPROM_H_

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"
#include "../../MCAL/TWI/TWI.h"
#include <util/delay.h>

#define A2				0


void EEPROM_voidWrite(u16 Copy_u16ByteAddress, u8 Copy_u8Data);
u8	 EEPROM_u8Read	 (u16 Copy_u16ByteAddresss);

#endif /* HAL_EEPROM_EEPROM_H_ */
