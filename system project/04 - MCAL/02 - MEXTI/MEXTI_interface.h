/* Author: Ahmed Nabil
SWC:  MEXTI interface
Version:  1.0
Modified date: August 31, 2021 */
/*************************/

#ifndef MEXTI_INT_H
#define MEXTI_INT_H

#define MEXTI_FALLING_EDGE 1
#define MEXTI_RISING_EDGE  2
#define MEXTI_LOW_LEVEL    3
#define MEXTI_IOC          4

#define MEXTI_INT0  6
#define MEXTI_INT1  7
#define MEXTI_INT2  5

void MEXTI_voidInt(u8 ARG_u8EdgeType);
void MEXTI_voidEnable(u8 ARG_u8Interrupt);
void MEXTI_voidDisable(u8 ARG_u8Interrupt);
void MEXIT_voidSetCallBackINT0(void(*ARG_pvoifFFunctionPtr)(void))


#endif
