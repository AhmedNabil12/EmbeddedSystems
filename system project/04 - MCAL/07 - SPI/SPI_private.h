/* Author: Ahmed Nabil
SWC:  SPI private
Version:  1.0
Modified date: SEPTEMBER 8, 2021 */
/*************************/



#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


#define SPCR (*((volatile uint8 *)0x2D ))
#define SPSR (*((volatile uint8 *)0x2E ))
#define SPDR (*((volatile uint8 *)0x2F ))

#define SPIE 7
#define SPE  6
#define DORD 5
#define MSTR 4
#define CPOL 3
#define CPHA 2
#define SPR1 1
#define SPR0 0

#define SPIF  7
#define WCOL  6
#define SPI2X 0

#endif