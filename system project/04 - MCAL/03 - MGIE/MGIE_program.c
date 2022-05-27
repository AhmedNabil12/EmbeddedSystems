/* Author: Ahmed Nabil
SWC:  MGIE program
Version:  1.0
Modified date: August 30, 2021 */
/*************************/

#include <util/delay.h>
#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MGIE_interface.h"
#include "MGIE_private.h"

void MGIE_voidEnableGI(void)
{
	SET_BIT(SREG,I_BIT);
}
void MGIE_voidDisableGI(void)
{
	CLEAR_BIT(SREG,I_BIT);
}