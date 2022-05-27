/* Author: Ahmed Nabil
SWC:  SPI interface
Version:  1.0
Modified date: SEPTEMBER 8, 2021 */
/*************************/


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#define DUMMY  0xFF

void SPI_voidMasterInt(void);

void SPI_voidSlaveInt(void);

u8   SPI_u8Transfer(u8 ARG_u8Data);

u8   SPI_u8RedDataISR(void);

void SPI_voidSendDataISR(u8 ARG_u8Data);

void SPI_voidSetCallBack(void (*PtrToFunc) (void));


#endif