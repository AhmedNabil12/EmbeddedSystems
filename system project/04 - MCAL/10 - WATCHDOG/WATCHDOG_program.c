/* Author: Ahmed Nabil
SWC:  WATCHDOG program
Version:  1.0
Modified date: SEPTEMBER 13, 2021 */
/*************************/

#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MDIO_interface.h"
#include "WATCHDOG_interface.h"
#include "WATCHDOG_private.h"

void WATCHDOG_voidEnable(void)
{
	//SETBIT(WDTCR,WDTOE);
	WDTCR=0b00001111;
}

void WATCHDOG_voidDisable(void)
{
	WDTCR|=(1<<WDTOE) | (1<<WDE);
	CLEAR_BIT(WDTCR,WDE);	
}
