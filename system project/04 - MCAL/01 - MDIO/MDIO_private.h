/* Author: Ahmed Nabil
SWC:  MDIO private 
Version:  1.0
Modified date: August 23, 2021 */
/*************************/


#ifndef _MDIO_PRIVATE_H
#define _MDIO_PRIVATE_H

typedef struct{
	u8 PIN;
	u8 DDR;
	u8 PORT;
}GPIO_Type;

#define GPIOA ((volatile GPIO_Type *) 0x39 )
#define GPIOB ((volatile GPIO_Type *) 0x36 )
#define GPIOC ((volatile GPIO_Type *) 0x33 )
#define GPIOD ((volatile GPIO_Type *) 0x30 )


#endif