/* Author: Ahmed Nabil
SWC:  EEPTOM private
Version:  1.0
Modified date: SEPTEMBER 8, 2021 */
/*************************/

#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

#define EEPROM_ADDR_W(BLOCK) ((0xA << 4) | (Block << 1))
#define EEPROM_ADDR_R(BLOCK) ((0xA << 4) | (Block << 1) | 1)

#endif