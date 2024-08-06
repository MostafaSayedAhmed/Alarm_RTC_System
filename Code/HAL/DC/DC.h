/*
 * DC_Motor.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mostafa Sayed
 */

#ifndef HAL_DC_DC_H_
#define HAL_DC_DC_H_

#include "../../MCAL/DIO/DIO.h"

#define DC_PORT		DIO_PORTC
#define DC_DIR1		DIO_PIN0
#define DC_DIR2		DIO_PIN1

#define HIGH_SPEED	255

typedef enum{
	DC_CW,
	DC_CCW,
	DC_STOP
}DC_direction;


void DC_voidInit(void);
void DC_voidRotate(DC_direction Copy_direction, u8 Copy_u8Speed);


#endif /* HAL_DC_DC_H_ */
