/*
 * RTC.h
 *
 *  Created on: Sep 6, 2023
 *      Author: Mostafa Sayed
 */

#ifndef HAL_RTC_RTC_H_
#define HAL_RTC_RTC_H_

#include "../../LIB/STD_Types.h"

#define RTC_ADR		0b1101000
#define SECONDS 	0x00
#define MINUTES 	0x01
#define HOURS	 	0x02
#define DATE		0x03
#define DAYS	 	0x04
#define MONTHS	 	0x05
#define YEARS	 	0x06
#define CONTROL	 	0x07

void RTC_voidInit(void);
u8 	 RTC_u8ReadSeconds(void);
u8 	 RTC_u8ReadMinutes(void);
u8 	 RTC_u8ReadHours(void);
u8 	 RTC_u8ReadDays(void);
u8 	 RTC_u8ReadMonths(void);
u8 	 RTC_u8ReadYears(void);
u8 	 RTC_u8ReadDate(void);



#endif /* HAL_RTC_RTC_H_ */
