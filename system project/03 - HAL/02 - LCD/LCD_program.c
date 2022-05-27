/* Author: Ahmed Nabil
SWC:  LCD program
Version:  1.0.
Modified date: August 29, 2021 */
/*************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"
#include <util/delay.h>


void LCD_voidWWriteCmd(u8 ARG_u8CMD)
{
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,MDIO_LOW);
	MDIO_voidSetPortValue(LCD_DATA_PORT,ARG_u8CMD);
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,MDIO_LOW);
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,MDIO_HIGH);
	_delay_us(1);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,MDIO_LOW);
}

void LCD_voidInitalize(u8 ARG_u8DisplayPort,u8 ARG_u8ENPin,u8 ARG_u8RSPin)
{
	u8 L_u8_DispBusPort;
	u8 L_u8_ENPIN=0;
	u8 L_u8_RSPIN=0;
	switch(ARG_u8DisplayPort)
	{
		case MDIO_PORTA:
		{
			MDIO_voidSetPortDirection(MDIO_PORTA,0xFF);
			break;
		}
		case MDIO_PORTB:
		{
			MDIO_voidSetPortDirection(MDIO_PORTB,0xFF);
			break;
		}
		case MDIO_PORTC:
		{
			MDIO_voidSetPortDirection(MDIO_PORTC,0xFF);
			break;
		}
		case MDIO_PORTD:
		{
			MDIO_voidSetPortDirection(MDIO_PORTD,0xFF);
			break;
		}
		default:
		{
			//error
			break;
		}
	}
	
	L_u8_DispBusPort=ARG_u8DisplayPort;
	if(ARG_u8ENPin<=MDIO_PIN_1 && ARG_u8RSPin<=MDIO_PIN_0)
	{
		LCD_EN_PIN=ARG_u8ENPin;
		L_u8_RSPIN=ARG_u8RSPin;
		MDIO_voidSetPinDirection(L_u8_ENPIN,0xFF);
		MDIO_voidSetPinDirection(L_u8_RSPIN,0xFF);
	}
	else
	{
		//error
	}
	LCD_voidWWriteCmd(0x38);
	LCD_voidWWriteCmd(0x07);
	LCD_voidWWriteCmd(0x0F);
	_delay_ms(1);
}

void LCD_voidWriteData(u8 ARG_u8DATA)
{
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,MDIO_HIGH);
	MDIO_voidSetPortValue(LCD_DATA_PORT,ARG_u8DATA);
	_delay_ms(1);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,MDIO_LOW);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,MDIO_HIGH);
	_delay_us(1);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,MDIO_LOW);
}