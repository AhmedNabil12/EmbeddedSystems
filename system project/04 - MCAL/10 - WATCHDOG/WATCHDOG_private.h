/* Author: Ahmed Nabil
SWC:  WATCHDOG private
Version:  1.0
Modified date: SEPTEMBER 13, 2021 */
/*************************/


#ifndef WATCHDOG_PRIVATE_H_
#define WATCHDOG_PRIVATE_H_

#define MCUCSR *((volatile u8*)0X54)
#define WDTCR *((volatile u8*) 0x41)
#define WDTOE 4
#define WDE  3
#define WDP2 2 
#define WDP1  1
#define WDP0 0

#endif