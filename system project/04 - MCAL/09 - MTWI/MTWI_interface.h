/* Author: Ahmed Nabil
SWC:  MTWI interface
Version:  1.0
Modified date: SEPTEMBER 7, 2021 */
/*************************/

#ifndef MTWI_INTERFACE_H_
#define MTWI_INTERFACE_H_

#define MTWI_ACK   1
#define MTWI_NACK  0

void MTWI_voidInt(u32 ARG_u32ClkSpeed,u8 ARG_u8SlaveAddr);
void MTWI_voidSendData(u8 ARG_u8Address,u8* ARG_u8pData,u8 ARG_u8Count);
u8   MTWI_u8ReceiveData(u8 ARG_u8Address,,u8 ARG_u8Back);

u8  MTWI_u8SendReceive(u8 ARG_u8Address, u8 ARG_u8Data,u8 ARG_u8LastACK);
void MTWI_voidSendReceiveSeq(u8 ARG_u8Address, u8 ARG_u8Data,u8* ARG_u8pRecevData,u8 ARG_u8Count,u8 ARG_u8LastACK);

#endif