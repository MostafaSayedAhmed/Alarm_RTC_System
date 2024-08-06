/*
 * SPI.c
 *
 *  Created on: Aug 29, 2023
 *      Author: Mostafa Sayed
 */

#include "SPI.h"

static ptr2fun_Iv_Ov SPI_INTFun = NULL;

void SPI_voidEnable	    (void)
{
	SET_BIT(SPCR,SPE);
}
void SPI_voidMasterInit (u8 Copy_u8SPIMode, u8 Copy_u8SPIPrescaler)
{
	u8 Local_u8SPCRTemp = 0;

	/*			Pins Direction				 */
	SET_BIT(DDRB,MOSI);
	CLR_BIT(DDRB,MISO);
	SET_BIT(DDRB,SCLK);
	SET_BIT(DDRB,SS);

	/* 		Enable/Disable Interrupt	  	*/
	#if SPI_INT == SPI_DISABLE
		CLR_BIT(Local_u8SPCRTemp,SPIE);
	#else
		SET_BIT(Local_u8SPCRTemp,SPIE);
		SET_BIT(SREG,7);
	#endif

	/* 		Data Order					  	*/
	#if SPI_DORD == SPI_MSB
		CLR_BIT(Local_u8SPCRTemp,DORD);
	#else
		SET_BIT(Local_u8SPCRTemp,DORD);
	#endif

	/*		Select Master					*/
	SET_BIT(Local_u8SPCRTemp,MSTR);

	/*		Select SPI Mode					*/
	Local_u8SPCRTemp &= 0xF3;
	Local_u8SPCRTemp |= (Copy_u8SPIMode)<<2 ;

	/*		Select Pre-scaler				*/
	Local_u8SPCRTemp &= 0xF3;
	Local_u8SPCRTemp |= (Copy_u8SPIPrescaler) ;

	/*		Select Double Speed Mode		*/
	if(GET_BIT(Copy_u8SPIPrescaler,2) == 0)
	{
		CLR_BIT(SPSR,SPI2X);
	}
	else
	{
		SET_BIT(SPSR,SPI2X);
	}

	/*		Assign Value to Register		*/
	SPCR = Local_u8SPCRTemp;


}
void SPI_voidSlaveInit  (u8 Copy_u8SPIMode, u8 Copy_u8SPIPrescaler)
{
	u8 Local_u8SPCRTemp = 0;

	/*			Pins Direction				 */
	CLR_BIT(DDRB,MOSI);
	SET_BIT(DDRB,MISO);
	CLR_BIT(DDRB,SCLK);
	CLR_BIT(DDRB,SS);

	/* 		Enable/Disable Interrupt	  	*/
	#if SPI_INT_SET == SPI_DISABLE
		CLR_BIT(Local_u8SPCRTemp,SPIE);
	#else
		SET_BIT(Local_u8SPCRTemp,SPIE);
		SET_BIT(SREG,7);
	#endif

	/* 		Data Order					  	*/
	#if SPI_DORD == SPI_MSB
		CLR_BIT(Local_u8SPCRTemp,DORD);
	#else
		SET_BIT(Local_u8SPCRTemp,DORD);
	#endif

	/*		Select Slave					*/
	CLR_BIT(Local_u8SPCRTemp,MSTR);

	/*		Select SPI Mode					*/
	Local_u8SPCRTemp &= 0xF3;
	Local_u8SPCRTemp |= (Copy_u8SPIMode)<<2 ;

	/*		Select Pre-scaler				*/
	Local_u8SPCRTemp &= 0xF3;
	Local_u8SPCRTemp |= (Copy_u8SPIPrescaler) ;

	/*		Select Double Speed Mode		*/
	if(GET_BIT(Copy_u8SPIPrescaler,2) == 0)
	{
		CLR_BIT(SPSR,SPI2X);
	}
	else
	{
		SET_BIT(SPSR,SPI2X);
	}

	/*		Assign Value to Register		*/
	SPCR = Local_u8SPCRTemp;


}
void SPI_voidSend	    (u8 Copy_u8Data)
{
	/* 	Writing Data and Start Transmission */
	SPDR = Copy_u8Data;

	/*		Wait Till Flag is Set			*/
	while(GET_BIT(SPSR,SPIF) == 0);

}

void SPI_voidDataWrite  (u8 Copy_u8Data)
{
	/* 	Writing Data  */
	SPDR = Copy_u8Data;
}

u8   SPI_u8Receive	    (void)
{
	/*		Wait Till Flag is Set			*/
	while(GET_BIT(SPSR,SPIF) == 0);

	/* 		Receive Data					*/
	return (u8) SPDR;
}
u8   SPI_u8Transceive   (u8 Copy_u8Data)
{
	/* 	Writing Data and Start Transmission */
	SPDR = Copy_u8Data;

	/*		Wait Till Flag is Set			*/
	while(GET_BIT(SPSR,SPIF) == 0);

	/* 		Receive Data					*/
	return (u8) SPDR;
}
void SPI_voidDisable    (void)
{
	CLR_BIT(SPCR,SPE);
}
void SPI_voidSetCallBack(ptr2fun_Iv_Ov ptr2fun)
{
	if(ptr2fun != NULL)			SPI_INTFun = ptr2fun;
}

ISR(SPI_INT)
{
	if(SPI_INTFun != NULL)		SPI_INTFun();
}
