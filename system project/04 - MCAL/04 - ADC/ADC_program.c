/* Author: Ahmed Nabil
SWC:  ADC program
Version:  1.0
Modified date: SEPTEMBER 1, 2021 */
/*************************/


#include "LBIT_math.h"
#include "LSTD_types.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "MDIO_interface.h"

void ADC_voidInt(u8 ARG_u8RefrenceSel,u8 ARG_u8Right_Left_Adju)
{
	switch(ARG_u8RefrenceSel)
	{
		case ADC_AREREF:
		{
			CLEAR_BIT(ADC_MUX,ADC_ADMUX_REFS1);
			CLEAR_BIT(ADC_MUX,ADC_ADMUX_REFS0);
			break;
		}
		case ADC_VOLTAGE_REFERENCE:
		{
			CLEAR_BIT(ADC_MUX,ADC_ADMUX_REFS1);
			SET_BIT(ADC_MUX,ADC_ADMUX_REFS0);
			break;
		}
		case ADC_RESERVEDREF:
		{
			SET_BIT(ADC_MUX,ADC_ADMUX_REFS1);
			CLEAR_BIT(ADC_MUX,ADC_ADMUX_REFS0);
			break;
		}
		case ADC_INTERNALREF:
		{
			SET_BIT(ADC_MUX,ADC_ADMUX_REFS1);
			SET_BIT(ADC_MUX,ADC_ADMUX_REFS0);
		}
	}
	
	switch(ARG_u8Right_Left_Adju)
	{
		case ADC_LEFT_ADJUSTMENT:
		{
			SET_BIT(ADC_MUX,ADC_ADMUX_ADLAR);
			break;
		}
		case ADC_RIGHT_ADJUSTMENT:
		{
			CLEAR_BIT(ADC_MUX,ADC_ADMUX_ADLAR);
			break;
		}
	}
	SET_BIT(ADCSRA,ADC_ADEN);
}


void ADC_voidEnable()
{
	SET_BIT(ADCSRA , ADC_ADEE );
}

void ADC_voidDisable()
{
	CLEAR_BIT(ADCSRA , ADC_ADEE );
}

void ADC_voidStartConversion(void)
{
	SET_BIT(ADCSRA , ADC_ADSC );
}


u8 ADC_u8GetFlag(void)
{
	u8 L_u8Val=GET_BIT(ADCSRA,ADC_ADIF);
}

u8 ADC_u8GetADCLPortValue(void)
{
	u8 L_u8Val=ADCL;
	return L_u8Val;
}

u8 ADC_u8GetADCHPortValue(void)
{
	u8 L_u8Val=ADCH;
	return L_u8Val;
}