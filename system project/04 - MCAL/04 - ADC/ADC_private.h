/* Author: Ahmed Nabil
SWC:  ADC private
Version:  1.0
Modified date: SEPTEMBER 1, 2021 */
/*************************/


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_ADMUX     *((volatile u8*)0x27)
#define ADCSRA        *((volatile u8*)0x26)
#define ADCH          *((volatile u8*)0x25)
#define ADCL          *((volatile u8*)0x24)
#define SFIOR         *((volatile u8*)0x50)

#define LEFT_ADJUSTMENT         1
#define RIGHT_ADJUSTMENT        0

#endif