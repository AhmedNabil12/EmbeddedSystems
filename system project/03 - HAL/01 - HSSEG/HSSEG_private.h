/* Author: Ahmed Nabil
SWC:  HSSEG private
Version:  1.0
Modified date: August 24, 2021 */
/*************************/

#ifndef _HSSEG_PRIVATE_H
#define _HSSEG_PRIVATE_H

//comon cathode
 #define ZERO   0x3F
 #define ONE    0x06
 #define TWO    0x5B
 #define THREE  0x4F
 #define FOUR   0x66
 #define FIVE   0x6D
 #define SIX    0x7D
 #define SEVEN  0x07
 #define EIGHT  0x7F
 #define NINE   0x67

// //comon anode
// #define ZERO   0x40
// #define ONE    0x79
// #define TWO    0x24
// #define THREE  0x30
// #define FOUR   0x19
// #define FIVE   0x12
// #define SIX    0x02
// #define SEVEN  0x78
// #define EIGHT  0x00
// #define NINE   0x10

// #define COMMON_ANODE     0x50
// #define COMMON_CATHODE   0x0F




const u8 HSSEG_u8SSEGArr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};



#endif