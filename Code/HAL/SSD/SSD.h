/*
 * SSD.h
 *
 *  Created on: Aug 17, 2023
 *      Author: Mostafa Sayed
 */

#ifndef HAL_SSD_SSD_H_
#define HAL_SSD_SSD_H_

#include "../../MCAL/DIO/DIO.h"

// SSD
#define ZERO  		0b00111111
#define ONE   		0b00000110
#define TWO   		0b01011011
#define THREE 		0b01001111
#define FOUR  		0b01100110
#define FIVE  		0b01101101
#define SIX   		0b01111101
#define SEVEN 		0b00000111
#define EIGHT 		0b01111111
#define NINE 	 	0b01101111

#define SEGMENT_ARRAY {ZERO, ONE, TWO, THREE,FOUR, FIVE, SIX, SEVEN, EIGHT, NINE}

/*		APIs			*/
void SSD_voidInit(u8 Copy_u8Port);
void SSD_voidSend(u8 Copy_u8Port,u8 Copy_u8Num);


#endif /* HAL_SSD_SSD_H_ */
