/* Author: Ahmed Nabil
SWC:  HSSEG program
Version:  1.0.
Modified date: August 27, 2021 */
/*************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include "HSSEG_private.h"
#include "HSSEG_config.h"
#include "HSSEG_interface.h"

#include<util/delay.h>

void HSSEG_voidInitialize()
{
	MDIO_voidSetPortDirection( MDIO_PORTD,0xFF);
	MDIO_voidSetPortDirection( MDIO_PORTC,0xFF);
}


void HSSEG_voidDisplayNumber(u8 ARG_u8Number)
{

	for(int i=ARG_u8Number;i<10;i++){
		MDIO_voidSetPortValue(MDIO_PORTD,HSSEG_u8SSEGArr[i]);
		for(int j=0;j<10;j++){
			MDIO_voidSetPortValue(MDIO_PORTC,HSSEG_u8SSEGArr[j]);
			_delay_ms(250);
		}

	}
}
