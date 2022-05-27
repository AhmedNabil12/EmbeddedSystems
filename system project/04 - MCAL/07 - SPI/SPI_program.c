/* Author: Ahmed Nabil
SWC:  SPI program
Version:  1.0
Modified date: SEPTEMBER 8, 2021 */
/*************************/


#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MDIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"


void ((*voidSetCallBack) (void));


void SPI_voidMasterInt(void)
{
	SET_BIT(SPCR,6); 
	CLEAR_BIT(SPCR,5); 
	SET_BIT(SPCR,4); 
	SET_BIT(SPCR,3); 
	SET_BIT(SPCR,2); 
	CLEAR_BIT(SPSR,0);
	SET_BIT(SPCR,1); 
	SET_BIT(SPCR,0); 
	return;
}
void SPI_voidSlaveInt(void)
{
	SET_BIT(SPCR,6); 
	CLEAR_BIT(SPCR,5); 
	SET_BIT(SPCR,4); 
	SET_BIT(SPCR,3); 
	SET_BIT(SPCR,2); 
	CLEAR_BIT(SPSR,0);
	SET_BIT(SPCR,1); 
	SET_BIT(SPCR,0); 
	return;
}
u8   SPI_u8Transfer(u8 ARG_u8Data)
{
	SPDR= ARG_u8Data;
	while((GET_BIT(SPSR,7))==0); 
	return SPDR ;	
}



u8   SPI_u8RedDataISR(void)
{
	return SPDR ;
}
void SPI_voidSendDataISR(u8 ARG_u8Data)
{
	SPDR = ARG_u8Data ;
}


void SPI_voidSetCallBack( void (*PtrToFunc) (void) )
{
	voidSetCallBack = PtrToFunc ;
}

void __vector_12(void) __attribute__((signal , used));
void __vector_12(void)
{

	PtrToFunc();

}