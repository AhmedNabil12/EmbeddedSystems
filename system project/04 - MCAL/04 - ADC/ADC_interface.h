/* Author: Ahmed Nabil
SWC:  ADC interface
Version:  1.0
Modified date: SEPTEMBER 1, 2021 */
/*************************/

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_



//ADMUX
#define ADC_ADMUX_MUX0        0
#define ADC_ADMUX_MUX1        1
#define ADC_ADMUX_MUX2        2
#define ADC_ADMUX_MUX3        3
#define ADC_ADMUX_MUX4        4
#define ADC_ADMUX_ADLAR       5
#define ADC_ADMUX_REFS0       6
#define ADC_ADMUX_REFS1       7
//ADCSRA
#define ADC_ADPS0             0
#define ADC_ADPS1             1
#define ADC_ADPS2             2
#define ADC_ADIE              3
#define ADC_ADIF              4
#define ADC_ADATE             5
#define ADC_ADSC              6
#define ADC_ADEN              7
//SFIOR
#define ADC_ADTS0             5
#define ADC_ADTS1             6
#define ADC_ADTS2             7
//CONFIG
#define ADC_VOLTAGE_REFERENCE   70
#define ADC_AREREF              50
#define ADC_RESERVEDREF			90
#define ADC_INTERNALREF			120
#define ADC_RIGHT_ADJUSTMENT    30
#define ADC_LEFT_ADJUSTMENT  	20



void ADC_voidInt(u8 ARG_u8RefrenceSel,u8 ARG_u8Right_Left_Adju);
void ADC_voidEnable();
void ADC_voidDisable();
void ADC_voidStartConversion();

u8 ADC_u8GetFlag(void);
u8 ADC_u8GetADCLPortValue(void);
u8 ADC_u8GetADCHPortValue(void);


#endif
