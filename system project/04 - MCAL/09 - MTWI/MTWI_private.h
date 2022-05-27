/* Author: Ahmed Nabil
SWC:  MTWI private
Version:  1.0
Modified date: SEPTEMBER 7, 2021 */
/*************************/


#ifndef MTWI_PRIVATE_H_
#define MTWI_PRIVATE_H_

#define TWBR  *((volatile u8*)0x20)
#define TWDR  *((volatile u8*)0x23)

#define TWAR  *((volatile u8*)0x22)
#define TWGCE  0

#define TWSR  *((volatile u8*)0x21)
#define TWPS1   1
#define TWPS0   0

#define TWCR  *((volatile u8*)0x56)
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
#define TWIE    0

#define GET_STATUS  (TWSR >> 3)

#define START_CONDITION_STATUS    0x08
#define SLAW_ACK_STATUS           0x18
#define SLAR_ACK_STATUS           0x40
#define DATA_TX_ACK_STATUS        0x28
#define DATA_RX_ACK_STATUS        0x50

void sendStartCondition(void);
void sendStopCondition(void);
void sendData(u8 Data);
void SendAck(void);
u8   readData(void);

#endif