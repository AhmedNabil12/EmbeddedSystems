/* Author: Ahmed Nabil
SWC:  UART interface
Version:  1.0
Modified date: SEPTEMBER 7, 2021 */
/*************************/


#ifndef UART_INTERFACE_H_
#defune UART_INETRFACE_H_


void UART_voidInt(u32 ARG_u32Fosc,u32 ARG_u32Baud);
u8   UART_u8RxChar(void);
void UART_voidRxString(u8* ARG_u8Data,u8 ARG_u8TerminatingChar);
void UART_voidTxChar(u8 ARG_u8Data);
void UART_voidTxString(char* ARG_u8pData);

#endif