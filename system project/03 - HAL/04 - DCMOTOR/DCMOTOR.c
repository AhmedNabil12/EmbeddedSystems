/* Author: Ahmed Nabil
SWC:  DC MOTOR program
Version:  1.0.
Modified date: August 26, 2021 */
/*************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"

u8 L_i;
void DCMOTOR_voidSetSpeed(u8 ARG_u8Speed, u8 ARG_u8Direction)
{
	if(ARG_u8Direction == 1 && ARG_u8Speed == 1)
	{
		for(i=0;i<10;i++)
		{
			MDIO_voidSetPinValue(MDIO_u8_PINA_0,MDIO_PORTA,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_u8_PINA_1,MDIO_PORTA,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_u8_PINA_2,MDIO_PORTA,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_u8_PINA_3,MDIO_PORTA,MDIO_HIGH);
			_delay_ms(2);
			
			MDIO_voidSetPinValue(MDIO_u8_PINA_0,MDIO_PORTA,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_u8_PINA_1,MDIO_PORTA,MDIO_HIGH);
			MDIO_voidSetPinValue(MDIO_u8_PINA_2,MDIO_PORTA,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_u8_PINA_3,MDIO_PORTA,MDIO_LOW);
			_delay_ms(2);
			
			MDIO_voidSetPinValue(MDIO_u8_PINA_0,MDIO_PORTA,MDIO_HIGH);
			MDIO_voidSetPinValue(MDIO_u8_PINA_1,MDIO_PORTA,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_u8_PINA_2,MDIO_PORTA,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_u8_PINA_3,MDIO_PORTA,MDIO_LOW);
			_delay_ms(2);
			
			MDIO_voidSetPinValue(MDIO_u8_PINA_0,MDIO_PORTA,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_u8_PINA_1,MDIO_PORTA,MDIO_LOW);
			MDIO_voidSetPinValue(MDIO_u8_PINA_2,MDIO_PORTA,MDIO_HIGH);
			MDIO_voidSetPinValue(MDIO_u8_PINA_3,MDIO_PORTA,MDIO_LOW);
			_delay_ms(2);
		}
	}
}

void DCMOTOR_voidInit(void)
{
	MDIO_voidSetPinValue(MDIO_u8_PINA_0,MDIO_PORTA,MDIO_LOW);
	MDIO_voidSetPinValue(MDIO_u8_PINA_1,MDIO_PORTA,MDIO_LOW);
	MDIO_voidSetPinValue(MDIO_u8_PINA_2,MDIO_PORTA,MDIO_LOW);
	MDIO_voidSetPinValue(MDIO_u8_PINA_3,MDIO_PORTA,MDIO_LOW);
}
