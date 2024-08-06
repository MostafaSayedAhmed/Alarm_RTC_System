/*
 * SPI.h
 *
 *  Created on: Aug 29, 2023
 *      Author: Mostafa Sayed
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"


/***************************************** SPI Register Macros *************************************************/

#define SREG			(*(volatile u8*)(0x3F + 0x20))

#define DDRB			(*(volatile u8*)(0x17 + 0x20))
#define MOSI			5
#define MISO			6
#define SCLK			7
#define SS				4

#define SPCR			(*(volatile u8*)(0x0D + 0x20))
#define SPIE			7
#define SPE				6
#define DORD			5
#define MSTR			4
#define CPOL			3
#define CPHA			2
#define SPR1			1
#define SPR0			0

#define SPSR			(*(volatile u8*)(0x0E + 0x20))
#define SPIF			7
#define WCOL			6
#define SPI2X			0

#define SPDR			(*(volatile u8*)(0x0F + 0x20))

#define SPI_INT			VECT(12)

#define VECT(N)			__vector_ ## N

#define ISR(vector)    													\
						void vector (void) __attribute__((signal,used));\
						void vector(void)

/***************************************** Configuration Macros *************************************************/

#define SPI_DISABLE		0
#define SPI_ENABLE		1

#define SPI_INT_SET		SPI_DISABLE

#define SPI_LSB			0
#define SPI_MSB			1

#define SPI_DORD		SPI_LSB

#define SPI_SLA			0
#define SPI_MST			1

#define SPI_MODE_0		0
#define SPI_MODE_1		1
#define SPI_MODE_2		2
#define SPI_MODE_3		3

#define SPI_PRE_4		0
#define SPI_PRE_16		1
#define SPI_PRE_64		2
#define SPI_PRE_128		3

#define SPI_PRE_2		4
#define SPI_PRE_8		5
#define SPI_PRE_32		6

/*********************************************** APIs *************************************************************/
void SPI_voidEnable	    (void);
void SPI_voidMasterInit (u8 Copy_u8SPIMode, u8 Copy_u8SPIPrescaler);
void SPI_voidSlaveInit  (u8 Copy_u8SPIMode, u8 Copy_u8SPIPrescaler);

/* 			Master	Mode		*/
void SPI_voidSend	    (u8 Copy_u8Data);
u8   SPI_u8Transceive   (u8 Copy_u8Data);

/*			Slave Mode			*/
void SPI_voidDataWrite  (u8 Copy_u8Data);
u8   SPI_u8Receive	    (void);
void SPI_voidDisable    (void);

void SPI_voidSetCallBack(ptr2fun_Iv_Ov ptr2fun);


#endif /* MCAL_SPI_SPI_H_ */
