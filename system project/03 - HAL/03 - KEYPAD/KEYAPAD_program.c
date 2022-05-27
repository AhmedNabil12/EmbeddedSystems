/* Author: Ahmed Nabil
SWC:  KEYPAD program
Version:  1.0.
Modified date: August 26, 2021 */
/*************************/

#include "LSTD_types.h"
#include "LBIT_math.h"

#include "MDIO_interface.h"
#include "KeyPad_interface.h"
#include "KeyPad_private.h"
#include "KeyPad_config.h"

void KeyPad_voidInit(void)
{
	MDIO_voidSetPortDirection(KEYPAD_PORT,KEYPAD_DIRECTION_1);
	#if ( KEYPAD_WIRING == KEYPAD_INTPULL)
	MDIO_voidSetPinValue(MDIO_PORTD,KEYPAD_COL1 , MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTD,KEYPAD_COL2 , MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTD,KEYPAD_COL3 , MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTD,KEYPAD_COL4 , MDIO_HIGH);
	#if KEYPAD_WIRING == KEYPAD_EXTPULL
#endif
}

u8 KeyPad_u8GetButton(void)
{
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW1 , MDIO_LOW);
    MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW2 , MDIO_HIGH);
    MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW3 , MDIO_HIGH);
    MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW4 , MDIO_HIGH);
	
	u8 L_u8Result = KeyPad_GetCol(KEYPAD_ROW1);
	 if(L_u8Result != '\0')
	 {
		 return L_u8Result;
	 }
	
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW1 , MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW2 , MDIO_LOW);
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW3 , MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW4 , MDIO_HIGH);
	u8 L_u8Result = KeyPad_GetCol(KEYPAD_ROW2);
	 if(L_u8Result != '\0')
	 {
		 return L_u8Result;
	 }
	
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW1 , MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW2 , MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW3 , MDIO_LOW);
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW4 , MDIO_HIGH);
	u8 L_u8Result = KeyPad_GetCol(KEYPAD_ROW3);
	 if(L_u8Result != '\0')
	 {
		 return L_u8Result;
	 }
		
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW1 , MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW2 , MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW3 , MDIO_HIGH);
	MDIO_voidSetPinValue(MDIO_PORTA,KEYPAD_ROW4 , MDIO_LOW);
	u8 L_u8Result = KeyPad_GetCol(KEYPAD_ROW4);
	 if(L_u8Result != '\0')
	 {
		 return L_u8Result;
	 }	
	}
}

static void KeyPad_GetCol(u8 ARG_ROW)
{
	u8 L_u8Res='\0';
	switch(ARG_ROW)
	{
		// ROW1
		case KEYPAD_ROW1: 
			if(MDIO_u8GetPinValue(KEYPAD_COL1)==0)
			{
				L_u8Res = KEYPAD_R1C1;
			}
		 
		else if(MDIO_u8GetPinValue(KEYPAD_COL2)==0)
			{
				L_u8Res = KEYPAD_R1C2;
			}
		 
		else if(MDIO_u8GetPinValue(KEYPAD_COL3)==0)
			{
				L_u8Res = KEYPAD_R1C3;
			}
		
		else if(MDIO_u8GetPinValue(KEYPAD_COL4)==0)
			{
				L_u8Res = KEYPAD_R1C4;
			}
			break;
		// ROW2	
		case KEYPAD_ROW2: 
			if(MDIO_u8GetPinValue(KEYPAD_COL1)==0)
			{
				L_u8Res = KEYPAD_R2C1;
			}	
		 
		else if(MDIO_u8GetPinValue(KEYPAD_COL2)==0)
			{
				L_u8Res = KEYPAD_R2C2;
			}		
		 
		else if(MDIO_u8GetPinValue(KEYPAD_COL3)==0)
			{
				L_u8Res = KEYPAD_R2C3;
			}
		 
		else if(MDIO_u8GetPinValue(KEYPAD_COL4)==0)
			{
				L_u8Res = KEYPAD_R2C4;
			}	
			break;
        // ROW3   
		case KEYPAD_ROW3: 
			if(MDIO_u8GetPinValue(KEYPAD_COL1)==0)
			{
				L_u8Res = KEYPAD_R3C1;
			}
		
		else if(MDIO_u8GetPinValue(KEYPAD_COL2)==0)
			{
				L_u8Res = KEYPAD_R3C2;
			}	
		
		else if(MDIO_u8GetPinValue(KEYPAD_COL3)==0)
			{
				L_u8Res = KEYPAD_R3C3;
			}
		 
		else if(MDIO_u8GetPinValue(KEYPAD_COL4)==0)
			{
				L_u8Res = KEYPAD_R3C4;
			}	
			break;
		// ROW4	
		case KEYPAD_ROW4: 
			if(MDIO_u8GetPinValue(KEYPAD_COL1)==0)
			{
				L_u8Res = KEYPAD_R4C1;
			}
		 
		else if(MDIO_u8GetPinValue(KEYPAD_COL2)==0)
			{
				L_u8Res = KEYPAD_R4C2;
			}
		
		else if(MDIO_u8GetPinValue(KEYPAD_COL3)==0)
			{
				L_u8Res = KEYPAD_R4C3;
			}	
		 
		else if(MDIO_u8GetPinValue(KEYPAD_COL4)==0)
			{
				L_u8Res = KEYPAD_R4C4;
			}	
			break;
	}
	return L_u8Res;
}