/*
 * TWI.c
 *
 *  Created on: Aug 30, 2023
 *      Author: Mostafa Sayed
 */

#include "TWI.h"


void TWI_voidMasterInit		   (void)
{
		u8 Local_u8TWCR = 0;
		/* 	Set Prescaler Value		*/
		TWSR &= 0xFC;
		TWSR |= PRE_VALUE;

		/* Frequency ==> 200 KHZ >>> from the equation ==> 12 */
		TWBR = (((F_CPU)/(200000)) - 16)/2 ;

		/* Enable I2C & ACK */
		SET_BIT(Local_u8TWCR,TWEA);
		SET_BIT(Local_u8TWCR,TWEN);

		TWCR = Local_u8TWCR;

}
void TWI_voidSlaveInit 		   (u8 Copy_u8Address)
{
		u8 Local_u8TWCR = 0;
		/*     Write Address in Register Address       */
		TWAR = (Copy_u8Address << 1) | (GEN_CALL_SETTING);

		/* Enable I2C & ACK */
		SET_BIT(Local_u8TWCR,TWEA);
		SET_BIT(Local_u8TWCR,TWEN);

		TWCR = Local_u8TWCR;

}
void TWI_voidStartCondition    (void)
{
		u8 Local_u8TWCR = 0;

		/* 		Clear TWINT by Writing One and Write One in TWSTA */
		SET_BIT(Local_u8TWCR,TWINT);
		SET_BIT(Local_u8TWCR,TWSTA);
		SET_BIT(Local_u8TWCR,TWEN);

		TWCR = Local_u8TWCR;

		/*		Wait Flag				*/
		while(GET_BIT(TWCR,TWINT)  == 0);
}
void TWI_voidSlaveAddressWrite (u8 Copy_u8SlaveAddress)
{
		u8 Local_u8TWCR = TWCR;
		TWDR = Copy_u8SlaveAddress << 1 ;
		CLR_BIT(TWDR,0);

		CLR_BIT(Local_u8TWCR,TWSTA);
		SET_BIT(Local_u8TWCR,TWINT);
		SET_BIT(Local_u8TWCR,TWEN);

		TWCR = Local_u8TWCR;

		/*		Wait Flag				*/
		while(GET_BIT(TWCR,TWINT)  == 0);

}
void TWI_voidSlaveAddressReads (u8 Copy_u8SlaveAddress)
{
		u8 Local_u8TWCR = TWCR;
		TWDR = Copy_u8SlaveAddress << 1 ;
		SET_BIT(TWDR,0);

		CLR_BIT(Local_u8TWCR,TWSTA);
		SET_BIT(Local_u8TWCR,TWINT);
		SET_BIT(Local_u8TWCR,TWEN);

		TWCR = Local_u8TWCR;

		/*		Wait Flag				*/
		while(GET_BIT(TWCR,TWINT)  == 0);
}
void TWI_voidMasterSendData	   (u8 Copy_u8Data)
{
		u8 Local_u8TWCR = TWCR;
		TWDR = Copy_u8Data ;

		SET_BIT(Local_u8TWCR,TWINT);
		SET_BIT(Local_u8TWCR,TWEN);

		TWCR = Local_u8TWCR;

		/*		Wait Flag				*/
		while(GET_BIT(TWCR,TWINT)  == 0);
}
u8 	 TWI_u8MasterReceiveData   (void)
{
	u8 Local_u8TWDRTemp = 0;
	u8 Local_u8TWCR = TWCR;

	SET_BIT(Local_u8TWCR,TWINT);
	SET_BIT(Local_u8TWCR,TWEN);

	TWCR = Local_u8TWCR;

	while(GET_BIT(TWCR,TWINT)  == 0);

	Local_u8TWDRTemp = TWDR;

	return (u8) Local_u8TWDRTemp;
}
void TWI_voidSlaveSendData	   (u8 Copy_u8Data)
{

}
u8 	 TWI_voidSlaveReceiveData  (void)
{
	u8 Local_u8TWDRTemp = 0;
	u8 Local_u8TWCR = TWCR;

	while((TWSR & 0xF8) == 0x60);

	SET_BIT(Local_u8TWCR,TWINT);
	SET_BIT(Local_u8TWCR,TWEN);

	while(GET_BIT(TWCR,TWINT)  == 0);

	Local_u8TWDRTemp = TWDR;

	return (u8) Local_u8TWDRTemp;
}
void TWI_voidStopCondition 	   (void)
{
		u8 Local_u8TWCR = TWCR;

		/*	Enable Stop Condition		*/
		SET_BIT(Local_u8TWCR,TWSTO);
		SET_BIT(Local_u8TWCR,TWINT);

		TWCR = Local_u8TWCR;
}
