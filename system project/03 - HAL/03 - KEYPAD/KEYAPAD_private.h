/* Author: Ahmed Nabil
SWC:  KEYPAD private
Version:  1.0.
Modified date: August 26, 2021 */
/*************************/

#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_

#define KEYPAD_WIRING           
#define KEYPAD_DIRECTION_1  0x0F
#define KEYPAD_DIRECTION_2  0xF0
#define KEYPAD_INTPULL          0		
#define KEYPAD_EXTPULL          1

static void KeyPad_GetCol(u8 ARG_ROW);

#endif