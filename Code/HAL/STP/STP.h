/*
 * STP.h
 *
 *  Created on: Aug 20, 2023
 *      Author: Mostafa Sayed
 */

#ifndef HAL_STP_STP_H_
#define HAL_STP_STP_H_

#include "../../MCAL/DIO/DIO.h"

#define STP_PORT		DIO_PORTC
#define STP_BLUE		DIO_PIN2
#define STP_PINK		DIO_PIN3
#define STP_YELLOW		DIO_PIN4
#define STP_ORANGE		DIO_PIN5

#define STP_STEP_ANGLE	45

typedef enum{
	STP_CW,
	STP_CCW,
	STP_STOP
}STP_direction;

void STP_voidInit(void);
void STP_voidRotate(STP_direction Copy_direction);
void STP_voidSetAngle(u16 Copy_u16Angle);

#endif /* HAL_STP_STP_H_ */
