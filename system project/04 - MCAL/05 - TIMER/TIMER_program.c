/* Author: Ahmed Nabil
SWC:  TIMER program
Version:  1.0
Modified date: SEPTEMBER 4, 2021 */
/*************************/


#include "LBIT_math.h"
#include "LSTD_types.h"

#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

void (*TIMER_OV_CallBack) (void) ;
void (*TIMER_CTC_CallBack) (void) ;

void TIMER_void_Init(void)
{
	#if(TIMER_MODE == TIMER_NORMAL)
		CLEAR_BIT(TCCR0 , 6);
		CLEAR_BIT(TCCR0 , 3);
	
	#elif(TIMER_MODE == TIMER_CTC)
		CLEAR_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		
	#elif(TIMER_MODE == TIMER_FAST_PWM )
		SET_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
		
	#elif(TIMER_MODE == TIMER_PHASE_PWM )
		SET_BIT(TCCR0 , 6);
		CLEAR_BIT(TCCR0 , 3);
		
	#endif
	
	#if(TIMER_PRESCALER == TIMER_DIV_BY_1)
		SET_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	
	#elif(TIMER_PRESCALER == TIMER_DIV_BY_8)
		CLEAR_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	#elif(TIMER_PRESCALER == TIMER_DIV_BY_64 )
		SET_BIT(TCCR0 , 0);
		SET_BIT(TCCR0 , 1);
		CLEAR_BIT(TCCR0 , 2);
	#elif(TIMER_PRESCALER == TIMER_DIV_BY_256 )
		CLEAR_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
	#elif(TIMER_PRESCALER == TIMER_DIV_BY_1024 )
		SET_BIT(TCCR0 , 0);
		CLEAR_BIT(TCCR0 , 1);
		SET_BIT(TCCR0 , 2);
		
	#endif
	
	#if(TIMER_COM_EVENT == TIMER_NO_ACTION)
		CLEAR_BIT(TCCR0 , 4);
		CLEAR_BIT(TCCR0 , 5);
		
	
	#elif(TIMER_COM_EVENT == TIMER_TOGGLE)
		SET_BIT(TCCR0 , 4)
		CLEAR_BIT(TCCR0 , 5);
	#elif(TIMER_COM_EVENT == TIMER_CLEAR )
		CLEAR_BIT(TCCR0 , 4);
		SET_BIT(TCCR0 , 5);
	#elif(TIMER_COM_EVENT == TIMER_SET )
		SET_BIT(TCCR0 , 4);
		SET_BIT(TCCR0 , 5);

		
	#endif
	/*Disable Interrupts*/
	CLEAR_BIT(TIMSK , 0);	
	CLEAR_BIT(TIMSK , 1);
	/*CLEAR FLAGS*/
	SET_BIT(TIFR , 0);	
	SET_BIT(TIFR , 1);
	/*Clear register*/
	TCNT0 = 0 ;
	OCR0 = 0 ;
}

void TIMER_void_SetTimerReg(u8 ARG_u8Value)
{
	TCNT0 = ARG_u8Value ;
}

void TIMER_void_SetCompareVal(u8 ARG_u8Value)
{
	OCR0 = ARG_u8Value ;
}

void TIMER_void_EnableOVInt(void)
{
	SET_BIT(TIMSK , 0);
}

void TIMER_void_DisableOVInt(void)
{
	CLEAR_BIT(TIMSK , 0);
}

void TIMER_void_EnableCTCInt(void)
{
	SET_BIT(TIMSK , 1);
}

void TIMER_void_DisableCTCInt(void)
{
	CLEAR_BIT(TIMSK , 1);
}

void TIMER_void_SetOVCallBack(void (*ARG_ptr) (void) ) 
{
	TIMER_OV_CallBack = ARG_ptr ;
}

void TIMER_void_SetCTCCallBack(void (*ARG_ptr) (void) ) 
{
	TIMER_CTC_CallBack = ARG_ptr ;
	
}

void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{
	
	TIMER_OV_CallBack();
}

void __vector_10(void) __attribute__((signal , used));

void __vector_10(void)
{
	TIMER_CTC_CallBack();
}