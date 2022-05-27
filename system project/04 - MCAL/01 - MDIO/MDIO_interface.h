/* Author: Ahmed Nabil
SWC:  MDIO interface
Version:  1.0
Modified date:  August 26, 2021 */
/*************************/

#ifndef  _MDIO_INTERFACE_H_
#define  _MDIO_INTERFACE_H_

#define  MDIO_PORTA  12
#define  MDIO_PORTB  35
#define  MDIO_PORTC  20
#define  MDIO_PORTD  50


#define MDIO_HIGH     1
#define MDIO_LOW      0
#define MDIO_OUTPUT   1
#define MDIO_INPUT    0


//PORTA
#define MDIO_u8_PINA_0    0
#define MDIO_u8_PINA_1    1
#define MDIO_u8_PINA_2    2
#define MDIO_u8_PINA_3    3
#define MDIO_u8_PINA_4    4
#define MDIO_u8_PINA_5    5
#define MDIO_u8_PINA_6    6
#define MDIO_u8_PINA_7    7
//PORTB                         
#define MDIO_u8_PINB_8    8  
#define MDIO_u8_PINB_9    9  
#define MDIO_u8_PINB_10   10 
#define MDIO_u8_PINB_11   11 
#define MDIO_u8_PINB_12   12 
#define MDIO_u8_PINB_13   13 
#define MDIO_u8_PINB_14   14 
#define MDIO_u8_PINB_15   15 
//PORTC                         
#define MDIO_u8_PINC_16   16 
#define MDIO_u8_PINC_17   17 
#define MDIO_u8_PINC_18   18 
#define MDIO_u8_PINC_19   19 
#define MDIO_u8_PINC_20   20 
#define MDIO_u8_PINC_21   21 
#define MDIO_u8_PINC_22   22 
#define MDIO_u8_PINC_23   23 
//PORTD                         
#define MDIO_u8_PIND_24   24 
#define MDIO_u8_PIND_25   25 
#define MDIO_u8_PIND_26   26 
#define MDIO_u8_PIND_27   27 
#define MDIO_u8_PIND_28   28 
#define MDIO_u8_PIND_29   29 
#define MDIO_u8_PIND_30   30 
#define MDIO_u8_PIND_31   31 



void MDIO_voidSetPortDirection(u8 ARG_u8Port,u8 ARG_u8Direction);
void MDIO_voidSetPortValue(u8 ARG_u8Port,u8 ARG_u8Value);
u8   MDIO_u8GetPortValue(u8 ARG_u8Port);

void MDIO_voidInitialize(void);
void MDIO_voidSetPinDirection(u8 ARG_u8Pin,u8 ARG_u8Port,u8 ARG_u8Direction);
void MDIO_voidSetPinValue(u8 ARG_u8Pin,u8 ARG_u8Port,u8 ARG_u8Value);
u8   MDIO_u8GetPinValue(u8 ARG_u8Pin);

#endif
