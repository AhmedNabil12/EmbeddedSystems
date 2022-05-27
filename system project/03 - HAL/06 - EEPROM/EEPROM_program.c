/* Author: Ahmed Nabil
SWC:  EEPTOM program
Version:  1.0
Modified date: SEPTEMBER 8, 2021 */
/*************************/

#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MTWI_interface.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"

u8   EEPROM_u8ReadLastByte(u8 ARG_u8Block)
{
	u8 L_u8Data;
	L_u8Data = MTWI_u8ReceiveData(EEPROM_ADDR_R(ARG_u8Block),MTWI_NACK);
	return L_u8Data;
}
void EEPROM_voidWriteByte(u8 ARG_u8Address,u8 ARG_u8Block,u8 ARG_u8Data)
{
	 if(ARG_u8Block >=0 && ARG_u8Block <= 4)
	 {
		u8 L_u8Data[2] = {ARG_u8Address,ARG_u8Data};
		MTWI_voidSendData(EEPROM_ADDR_W(ARG_u8Block),L_u8Data,2); 
	 }
	 else
	 {
		 // error
	 }
}

void EEPROM_voidWritePage(u8 ARG_u8Address,u8 ARG_u8Block,u8* ARG_u8pData, u8 ARG_u8DataSize)
{
	u8 L_u8counter;
	if(ARG_u8Block <= 4 && ARG_u8Block <= 16)
	{
		u8 L_u8Data[17];
		L_u8Data[0] = ARG_u8Address;
		for(L_u8counter = 0; L_u8counter < ARG_u8Count; L_u8counter++)
		{
			L_u8Data[L_u8counter] = ARG_u8pData[L_u8counter];
		}
		MTWI_voidSendData(EEPROM_ADDR_W(ARG_u8Block),L_u8Data,ARG_u8DataSize);
	}
    else
    {
		// error
    }
}
void EEPROM_voidReadSequential(u8 ARG_u8Address,u8 ARG_u8Block,u8* ARG_u8pData,u8 ARG_u8NoBytes)
{
	MTWI_voidSendReceiveSeq(EEPROM_ADDR_W(ARG_u8Block), ARG_u8Address,ARG_u8pData, ARG_u8NoBytes,MTWI_NACK);
}

u8   EEPROM_u8ReadByte(u8 ARG_u8Address,u8 ARG_u8Block)
{
	u8 L_u8Data;
	L_u8Data = MTWI_u8SendReceive((EEPROM_ADDR_W(ARG_u8Block), ARG_u8Address,MTWI_NACK);
	return L_u8Data;
}

