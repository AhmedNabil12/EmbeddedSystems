/* Author: Ahmed Nabil
SWC:  TIMER private
Version:  1.0
Modified date: SEPTEMBER 4, 2021 */
/*************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


#define TCCR0   *((volatile u8*)0x53)
#define TCNT0   *((volatile u8*)0x52)
#define OCR0    *((volatile u8*)0x5C)
#define TIMSK   *((volatile u8*)0x59)
#define TIFR    *((volatile u8*)0x58)


#define TIMER_NORMAL 		1
#define TIMER_CTC 			2
#define TIMER_FAST_PWM   	3
#define TIMER_PHASE_PWM 	4

#define TIMER_DIV_BY_1			1
#define TIMER_DIV_BY_8			5
#define TIMER_DIV_BY_64		    8
#define TIMER_DIV_BY_256		10
#define TIMER_DIV_BY_1024		15

#define TIMER_EXTERNAL_CLOCK_FALLING_EDGE      36 
#define TIMER_EXTERNAL_CLOCK_RISING_EDGE       37 


#define TIMER_NO_ACTION	    100
#define TIMER_TOGGLE		12
#define TIMER_SET			20
#define TIMER_CLEAR	    	25


#endif