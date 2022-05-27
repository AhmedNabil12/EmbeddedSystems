/* Author: Ahmed Nabil
SWC:  KEYPAD config
Version:  1.0.
Modified date: August 26, 2021 */
/*************************/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define KEYPAD_PORT     MDIO_PORTA


#define KEYPAD_ROW1 	MDIO_PIN_0
#define KEYPAD_ROW2		MDIO_PIN_1
#define KEYPAD_ROW3		MDIO_PIN_2
#define KEYPAD_ROW4		MDIO_PIN_3


#define KEYPAD_COL1		MDIO_PIN_28
#define KEYPAD_COL2		MDIO_PIN_29
#define KEYPAD_COL3		MDIO_PIN_30
#define KEYPAD_COL4		MDIO_PIN_31

#define KEYPAD_R1C1					'1'	
#define KEYPAD_R1C2					'2'
#define KEYPAD_R1C3					'3'
#define KEYPAD_R1C4					'+'

#define KEYPAD_R2C1					'4'
#define KEYPAD_R2C2					'5'
#define KEYPAD_R2C3					'6'
#define KEYPAD_R2C4					'-'

#define KEYPAD_R3C1					'7'
#define KEYPAD_R3C2					'8'
#define KEYPAD_R3C3					'9'
#define KEYPAD_R3C4					'*'

#define KEYPAD_R4C1					'0'
#define KEYPAD_R4C2					'.'
#define KEYPAD_R4C3					'/'
#define KEYPAD_R4C4					'='

#endif