/* Author: Ahmed Nabil
SWC:  MEXTI program
Version:  1.0
Modified date: August 31, 2021 */
/*************************/

#include <util/delay.h>
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MEXTI_interface.h"
#include "MEXTI_private.h"

void (*MEXTI_pvoidUserFunctionINT0)(void)=0;

void MEXTI_voidInt(u8 ARG_u8EdgeType)
{
	#if ARG_u8EdgeType == IOC
		CLEAR_BIT(MCUCR,ISC01);
		SET_BIT(MCUCR,ISC00);

	#elif ARG_u8EdgeType == MEXTI_FALLING_EDGE
		SET_BIT(MCUCR,ISC01);
		CLEAR_BIT(MCUCR,ISC00);
		
	#elif ARG_u8EdgeType == MEXTI_RISING_EDGE
		SET_BIT(MCUCR,ISC01);
		SET_BIT(MCUCR,ISC00);
	
	#else
		CLEAR_BIT(MCUCR,ISC01);
		CLEAR_BIT(MCUCR,ISC00);
		
	#endif
	
	CLEAR_BIT(GICR,INT0);
	SET_BIT(GIFR,INTF0);
}
void MEXTI_voidEnable(u8 ARG_u8Interrupt)
{
	
	SET_BIT(GICR,ARG_u8Interrupt);
}

void MEXTI_voidDisable(u8 ARG_u8Interrupt)
{
	CLEAR_BIT(GICR,ARG_u8Interrupt);
}

void MEXIT_voidSetCallBackINT0(void(*ARG_pvoifFFunctionPtr)(void))
{
	MEXTI_pvoidUserFunctionINT0=ARG_pvoifFFunctionPtr;
}

void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	(*MEXTI_pvoidUserFunctionINT0)();
}