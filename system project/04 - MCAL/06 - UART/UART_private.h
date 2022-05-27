/* Author: Ahmed Nabil
SWC:  UART private
Version:  1.0
Modified date: SEPTEMBER 7, 2021 */
/*************************/


#ifndef UART_PRIVATE_H_
#defune UART_private_H_



#define UCSRA 		*((volatile u8 *)   0x2B)
#define UCSRB 		*((volatile u8 *)   0x2A)
#define UCSRC 		*((volatile u8 *)   0x40)
#define UBRRH 		*((volatile u8 *)   0x40)
#define UBRRL 		*((volatile u8 *)   0x29)
#define UDR 		*((volatile u8 *)   0x2C)


#define ASYNCHRONOUS    1
#define SYNCHRONOUS     3

#define NORMAL_SPEED_MODE   5
#define DOUBLE_SPEED_MODE   7

#define DISABLED    9 
#define EVEN        11
#define ODD         13

#define ONE_BIT     15
#define TWO_BITS    17

#define RISING	    19
#define FALLING     21

#endif