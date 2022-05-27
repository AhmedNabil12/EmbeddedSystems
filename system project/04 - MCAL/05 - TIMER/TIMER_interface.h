/* Author: Ahmed Nabil
SWC:  TIMER interface
Version:  1.0
Modified date: SEPTEMBER 4, 2021 */
/*************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


void TIMER_void_Init(void);
void TIMER_void_SetTimerReg(u8 ARG_u8Value);
void TIMER_void_SetCompareVal(u8 ARG_u8Value);
void TIMER_void_EnableOVInt(void);
void TIMER_void_DisableOVInt(void);
void TIMER_void_EnableCTCInt(void);
void TIMER_void_DisableCTCInt(void);
void TIMER_void_SetOVCallBack(void (*ARG_ptr) (void) ) ;
void TIMER_void_SetCTCCallBack(void (*ARG_ptr) (void) ) ;


#endif