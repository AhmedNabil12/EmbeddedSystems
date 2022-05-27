/* Author: Ahmed Nabil
SWC:  EEPTOM interface
Version:  1.0
Modified date: SEPTEMBER 8, 2021 */
/*************************/


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_


u8   EEPROM_u8ReadLastByte(u8 ARG_u8Block);
u8   EEPROM_u8ReadByte(u8 ARG_u8Address,u8 ARG_u8Block);
void EEPROM_voidWriteByte(u8 ARG_u8Address,u8 ARG_u8Block,u8 ARG_u8Data);

void EEPROM_voidWritePage(u8 ARG_u8Address,u8 ARG_u8Block,u8* ARG_u8pData, u8 ARG_u8DataSize);
void EEPROM_voidReadSequential(u8 ARG_u8Address,u8 ARG_u8Block,u8* ARG_u8pData,u8 ARG_u8NoBytes);


#endif