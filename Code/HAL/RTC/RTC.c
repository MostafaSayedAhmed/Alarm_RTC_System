/*
 * RTC.c
 *
 *  Created on: Sep 6, 2023
 *      Author: Mostafa Sayed
 */

#include "RTC.h"

void RTC_voidInit(void)
{
	TWI_voidMasterInit();

}
u8 RTC_u8ReadSeconds(void)
{
	u8 Local_u8Seconds = 0;

	/* 	Send Start Condition		*/
	TWI_voidStartCondition();

	/* 	Send RTC Address			*/
	TWI_voidSlaveAddressWrite(RTC_ADR);

	/* 	Send RTC Second Register	*/
	TWI_voidMasterSendData(SECONDS);

	/* Sending Second Start         */
	TWI_voidStartCondition();

	/* 	Send RTC Address Again		*/
	TWI_voidSlaveAddressReads(RTC_ADR);

	/*  Receiving Seconds			*/
	Local_u8Seconds = TWI_u8MasterReceiveData();

	/* Stop Condition  				*/
	TWI_voidStopCondition();

	return Local_u8Seconds;

}
u8 RTC_u8ReadMinutes(void)
{
	u8 Local_u8Minutes = 0;

	/* 	Send Start Condition		*/
	TWI_voidStartCondition();

	/* 	Send RTC Address			*/
	TWI_voidSlaveAddressWrite(RTC_ADR);

	/* 	Send RTC Second Register	*/
	TWI_voidMasterSendData(MINUTES);

	/* Sending Second Start         */
	TWI_voidStartCondition();

	/* 	Send RTC Address Again		*/
	TWI_voidSlaveAddressReads(RTC_ADR);

	/*  Receiving Seconds			*/
	Local_u8Minutes = TWI_u8MasterReceiveData();

	/* Stop Condition  				*/
	TWI_voidStopCondition();

	/* Return Data					*/
	return Local_u8Minutes;
}
u8 RTC_u8ReadHours(void)
{
	u8 Local_u8Hours = 0;

	/* 	Send Start Condition		*/
	TWI_voidStartCondition();

	/* 	Send RTC Address			*/
	TWI_voidSlaveAddressWrite(RTC_ADR);

	/* 	Send RTC Second Register	*/
	TWI_voidMasterSendData(HOURS);

	/* Sending Second Start         */
	TWI_voidStartCondition();

	/* 	Send RTC Address Again		*/
	TWI_voidSlaveAddressReads(RTC_ADR);

	/*  Receiving Seconds			*/
	Local_u8Hours = TWI_u8MasterReceiveData();

	/* Stop Condition  				*/
	TWI_voidStopCondition();

	/* Return Data					*/
	return Local_u8Hours;
}

u8 RTC_u8ReadDays(void)
{
	u8 Local_u8Days = 0;

	/* 	Send Start Condition		*/
	TWI_voidStartCondition();

	/* 	Send RTC Address			*/
	TWI_voidSlaveAddressWrite(RTC_ADR);

	/* 	Send RTC Second Register	*/
	TWI_voidMasterSendData(DAYS);

	/* Sending Second Start         */
	TWI_voidStartCondition();

	/* 	Send RTC Address Again		*/
	TWI_voidSlaveAddressReads(RTC_ADR);

	/*  Receiving Seconds			*/
	Local_u8Days = TWI_u8MasterReceiveData();

	/* Stop Condition  				*/
	TWI_voidStopCondition();

	/* Return Data					*/
	return Local_u8Days;
}

u8 RTC_u8ReadMonths(void)
{
	u8 Local_u8Months = 0;

	/* 	Send Start Condition		*/
	TWI_voidStartCondition();

	/* 	Send RTC Address			*/
	TWI_voidSlaveAddressWrite(RTC_ADR);

	/* 	Send RTC Second Register	*/
	TWI_voidMasterSendData(MONTHS);

	/* Sending Second Start         */
	TWI_voidStartCondition();

	/* 	Send RTC Address Again		*/
	TWI_voidSlaveAddressReads(RTC_ADR);

	/*  Receiving Seconds			*/
	Local_u8Months = TWI_u8MasterReceiveData();

	/* Stop Condition  				*/
	TWI_voidStopCondition();

	/* Return Data					*/
	return Local_u8Months;
}

u8 RTC_u8ReadYears(void)
{
	u8 Local_u8Years = 0;

	/* 	Send Start Condition		*/
	TWI_voidStartCondition();

	/* 	Send RTC Address			*/
	TWI_voidSlaveAddressWrite(RTC_ADR);

	/* 	Send RTC Second Register	*/
	TWI_voidMasterSendData(YEARS);

	/* Sending Second Start         */
	TWI_voidStartCondition();

	/* 	Send RTC Address Again		*/
	TWI_voidSlaveAddressReads(RTC_ADR);

	/*  Receiving Seconds			*/
	Local_u8Years = TWI_u8MasterReceiveData();

	/* Stop Condition  				*/
	TWI_voidStopCondition();

	/* Return Data					*/
	return Local_u8Years;
}

u8 RTC_u8ReadDate(void)
{
	u8 Local_u8Date = 0;

	/* 	Send Start Condition		*/
	TWI_voidStartCondition();

	/* 	Send RTC Address			*/
	TWI_voidSlaveAddressWrite(RTC_ADR);

	/* 	Send RTC Second Register	*/
	TWI_voidMasterSendData(DATE);

	/* Sending Second Start         */
	TWI_voidStartCondition();

	/* 	Send RTC Address Again		*/
	TWI_voidSlaveAddressReads(RTC_ADR);

	/*  Receiving Seconds			*/
	Local_u8Date = TWI_u8MasterReceiveData();

	/* Stop Condition  				*/
	TWI_voidStopCondition();

	/* Return Data					*/
	return Local_u8Date;
}

