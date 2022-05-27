/* Author: Ahmed Nabil
SWC:  MEXTI config
Version:  1.0
Modified date: August 30, 2021 */
/*************************/

#ifndef MEXTI_CONFIG_H_
#define MEXTI_CONFIG_H_

#define MCUCR  *((volatile u8*)0x55)
#define MCUCSR *((volatile u8*)0x54)
#define GICR   *((volatile u8*)0x5B)
#define GIFR   *((volatile u8*)0x5A)
#define SREG   *((volatile u8*)0x5F)

#endif
