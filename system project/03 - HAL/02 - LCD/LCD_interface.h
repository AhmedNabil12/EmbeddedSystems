/* Author: Ahmed Nabil
SWC:  LCD interface
Version:  1.0.
Modified date: August 25, 2021 */
/*************************/

#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

void LCD_voidWWriteCmd(u8 ARG_u8CMD);
void LCD_voidInitalize(u8 ARG_u8DisplayPort,u8 ARG_u8ENPin,u8 ARG_u8RSPin);
void LCD_voidWriteData(u8 ARG_u8DATA);

#endif