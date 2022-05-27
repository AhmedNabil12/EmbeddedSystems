/* Author: Ahmed Nabil
SWC:  MTWI program
Version:  1.0
Modified date: SEPTEMBER 7, 2021 */
/*************************/


#include "LBIT_math.h"
#include "LSTD_types.h"
#include "MDIO_interface.h"
#include "MTWI_interface.h"
#include "MTWI_private.h"


void sendStartCondition(void)
{
	TWCR |= ((1<< TWINT) | (1<< TWSTA));
	while(GET_BIT(TWCR, TWINT) == 0);
	return;
}

void sendStopCondition(void)
{
	TWCR |= ((1<< TWINT) | (1<< TWSTO));
	return;
}

void sendData(u8 Data)
{
	TWDR =data;
	if(START_CONDITION_STATUS == GET_STATUS)
	{
		CLEAR_BIT(TWCR,TWSTA);
	}
	SET_BIT(TWCR, TWINT);
	while(GET_BIT(TWCR, TWINT) == 0);
	return;
}

void SendAck(void)
{
	SET_BIT(TWCR,)
}

u8  readData(void)
{
	u8 L_u8DataRead;
	L_u8ReceivedData = TWDR;
	while(GET_BIT(TWCR, TWINT) == 0);
	return L_u8DataRead;
}

void MTWI_voidInt(u32 ARG_u32ClkSpeed,u8 ARG_u8SlaveAddr)
{
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR, TWEA);
	TWBR=10;
	SET_BIT(TWSR,TWPS0);
	CLEAR_BIT(TWSR,TWPS1);
	TWAR=(ARG_u8SlaveAddr<<1);
	return;
}



void MTWI_voidSendData(u8 ARG_u8Address,u8* ARG_u8pData,u8 ARG_u8Count)
{
	u8 L_u8counter;
	sendStartCondition();
	sendData(ARG_u8Address << 1);
	for(L_u8counter = 0; L_u8counter < ARG_u8Count; L_u8counter++)
	{
		sendData(ARG_u8pData[L_u8counter]);
	}
	sendStopCondition();
	return;
}

u8   MTWI_u8ReceiveData(u8 ARG_u8Address,u8 ARG_u8Back)
{
	u8 L_u8ReceivedData;
	sendStartCondition();
	sendData((ARG_u8Address << 1) | 1);
	L_u8ReceivedData = readData();
	if(1 == ARG)
	{
		sendAck();
	}
	else
	{
		
	}
	sendStopCondition();
	return L_u8ReceivedData;
}

u8  MTWI_u8SendReceive(u8 ARG_u8Address, u8 ARG_u8Data,u8 ARG_u8LastACK)
{
	u8 L_u8Data;
	sendStartCondition();
	sendData(ARG_u8Address << 1);
	sendData(ARG_u8Data);
	sendStartCondition();
	sendData((ARG_u8Address << 1) | 1);
	L_u8Data = readData();
	if(1 == ARG_u8LastACK)
	{
		sendAck();
	}
	else
	{}
	sendStopCondition();
	return L_u8Data;
}

void MTWI_voidSendReceiveSeq(u8 ARG_u8Address, u8 ARG_u8Data,u8* ARG_u8pRecevData,u8 ARG_u8Count,u8 ARG_u8LastACK)
{
	u8 L_u8Counter;
	u8 L_u8Data;
	sendStartCondition();
	sendData(ARG_u8Address << 1);
	sendData(ARG_u8Data);
	sendStartCondition();
	sendData((ARG_u8Address << 1) | 1);
	for(L_u8counter = 0; L_u8counter < ARG_u8Count; L_u8counter++)
	{
		ARG_u8pRecevData[L_u8Counter] = readData();
		sendAck();
	}
	ARG_u8pRecevData[L_u8Counter] = readData();
	if(1 == ARG_u8LastACK)
	{
		sendAck();
	}
	else
	{}
	sendStopCondition();
	return;
}