/* Author: Ahmed Nabil
SWC:  LCD private
Version:  1.0.
Modified date: August 25, 2021 */
/*************************/

#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

#define LCD_CLEAR_ALL        0x01
#define LCD_RM_CURSOR        0x0C
#define LCD_Cursor_BLINK     0x0F
#define LCD_CURSOR_NO_BLINK  0x0E

#define LCD_CURSOR_MV_RIGHT  0x14 
#define LCD_CURSOR_MV_LEFT   0x10
#define LCD_DISP_MV_RIGHT    0x1C
#define LCD_DISP_MV_LEFT     0x18

#define LCD_DISP_ONE_LINE    0x30
#define LCD_DISP_TWO_LINES   0x38

#define LCD_GOTO_CGRAM       0x40
#define LCD_FIRST_LINE       0x80
#define LCD_SECOND_LINE      0xC0

#endif