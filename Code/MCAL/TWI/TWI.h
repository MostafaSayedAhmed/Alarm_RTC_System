/*
 * TWI.h
 *
 *  Created on: Aug 30, 2023
 *      Author: Mostafa Sayed
 */

#ifndef MCAL_TWI_TWI_H_
#define MCAL_TWI_TWI_H_

#include "../../LIB/BIT_Math.h"
#include "../../LIB/STD_Types.h"

/***************** Registers *************************************/

#define TWCR							(*(volatile u8 *)(0x36 + 0x20))
#define TWINT							7
#define TWEA							6
#define TWSTA							5
#define TWSTO							4
#define TWWC							3
#define TWEN							2
#define TWIE							0

#define TWDR							(*(volatile u8 *)(0x03 + 0x20))

#define TWAR							(*(volatile u8 *)(0x02 + 0x20))
#define TWGCE							0

#define TWSR							(*(volatile u8 *)(0x01 + 0x20))
#define TWPS1							1
#define TWPS0							0

#define TWBR							(*(volatile u8 *)(0x00 + 0x20))

/******************* Status Macros ************************************/

/*		Master Transmitter		*/

#define	MSTR_START_TX					0x08
#define	MSTR_REP_START_TX				0x10
#define	MSTR_SLA_W_TX_ACK_RX			0x18
#define	MSTR_SLA_W_TX_NACK_RX			0x20
#define	MSTR_DATA_TX_ACK_RX				0x28
#define	MSTR_DATA_TX_NACK_RX			0x30
#define	MSTR_ABR_DATA_SLA_LOSS			0x38

/*		Master Receiver		*/

#define	MSTR_SLA_R_TX_ACK_RX			0x40
#define	MSTR_SLA_R_TX_NACK_RX			0x48
#define	MSTR_DATA_RX_ACK_RX				0x50
#define	MSTR_DATA_RX_NACK_RX			0x58

/*		Slave Transmitter		*/

#define	SLA_SLA_R_RX_ACK_TX				0xA8
#define	SLA_ABR_LOST_SLA_R_ACK_TX		0xB0
#define	SLA_DATA_TX_ACK_RX				0xB8
#define	SLA_DATA_TX_NACK_RX				0xC0
#define	SLA_LAST_DATA_TX_ACK_RX			0xC8

/*		Slave Receiver		*/

#define	SLA_SLA_W_RX_ACK_TX				0x60
#define	SLA_ABR_LOST_SLA_W_ACK_TX		0x68
#define	SLA_GEN_CALL_ACK_TX				0x70
#define	SLA_ABR_LOST_GEN_CALL_ACK_TX	0x78
#define	SLA_SLA_W_RX_DATA_RX_ACK_TX		0x80
#define	SLA_SLA_W_RX_DATA_RX_NACK_TX	0x88
#define	SLA_GEN_CALL_ATA_RX_ACK_TX		0x90
#define	SLA_GEN_CALL_ATA_RX_NACK_TX		0x98
#define	SLA_STOP_COND					0xA0

/*	  Miscellaneous States	*/
#define NO_STATUS						0xF8
#define ILLEGAL_START_STOP				0x00

/******************** Macros **********************************/
#define GEN_CALL_ADR					0x00
#define SLA_ADR							0xA0
#define PRE_VALUE						1

#define TWI_DISABLE						0
#define TWI_ENABLE						1
#define GEN_CALL_SETTING				TWI_ENABLE

/******************** APIs ***********************************/

void TWI_voidMasterInit		   (void);
void TWI_voidSlaveInit 		   (u8 Copy_u8Address);
void TWI_voidStartCondition    (void);
void TWI_voidSlaveAddressWrite (u8 Copy_u8SlaveAddress);
void TWI_voidSlaveAddressReads (u8 Copy_u8SlaveAddress);
void TWI_voidMasterSendData	   (u8 Copy_u8Data);
u8 	 TWI_u8MasterReceiveData   (void);
void TWI_voidSlaveSendData	   (u8 Copy_u8Data);
u8 	 TWI_voidSlaveReceiveData  (void);
void TWI_voidStopCondition 	   (void);





#endif /* MCAL_TWI_TWI_H_ */
