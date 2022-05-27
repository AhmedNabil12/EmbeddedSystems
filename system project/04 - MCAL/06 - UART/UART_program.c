/* Author: Ahmed Nabil
SWC:  UART program
Version:  1.0
Modified date: SEPTEMBER 7, 2021 */
/*************************/

#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MDIO_interface.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_voidInt(u32 ARG_u32Fosc,u32 ARG_u32Baud)
{
	u16 L_u16UBR0 = (ARG_u32Fosc / (16 * ARG_u32Baud))-1;
	UBR0L = (u8)L_u16UBR0;
	UBR0H = L_u16UBR0 >>8;
	
	CLEAR_BIT(UCSR0C, 7);
	CLEAR_BIT(UCSR0C, 6);
	
	CLEAR_BIT(UCSR0B, 2);
	SET_BIT(UCSR0C, 2);
	SET_BIT(UCSR0C, 1);
	
	CLEAR_BIT(UCSR0C, 3);
	
	SET_BIT(UCSR0B, 3);
	SET_BIT(UCSR0B, 4);
}

u8   UART_u8RxChar(void)
{
	u8 L_u8Data;
	while(!GET_BIT(UCSR0A, 7));
	L_u8Data = UDR0;
	return L_u8Data;
}

void UART_voidRxString(u8* ARG_u8Data,u8 ARG_u8TerminatingChar)
{
	u16 L_u16i = 0;
	do
	{
		ARG_u8Data[L_u16i] = UART_u8RxChar();
		L_u16i++;
	}while(ARG_u8Data[L_u16i-1] != ARG_u8TerminatingChar);
	ARG_u8Data[L_u16i]='\0';
	return;
}

void UART_voidTxChar(u8 ARG_u8Data)
{
	while(!GET_BIT(UCSR0A, 5));
	UDR0 = ARG_u8Data;
	while(!GET_BIT(UCSR0A, 6));
	SET_BIT(UCSR0A, 6);
}

void UART_voidTxString(char* ARG_u8pData)
{
	u16 L_u16i = 0;
	while(ARG_u8pData[L_u16i] != '\0';)
	{
		UART_voidTxChar(ARG_u8pData[L_u16i]);
		L_u16i++;
	}
}
