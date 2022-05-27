/* Author: Ahmed Nabil
SWC:  MDIO 
Version:  1.0
Modified date: August 22, 2021 */
/*************************/

#ifndef BITMATH_H_
#define BITMATH_H_

#define SET_BIT(Var,BitNo) (Var)=(Var)|(1<<BitNo)
#define CLEAR_BIT(Var,BitNo) (Var)=(Var)&~(1<<BitNo)
#define TOOGLE_BIT(Var,BitNo) (Var)=(Var)^(1<<BitNo)
#define GET_BIT(Var,BitNo) (((Var) >> (BitNo)) & 0x01)
#define CONC_BIT(A7,A6,A5,A4,A3,A2,A1,A0) CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0)
#define CONC_HELP(A7,A6,A5,A4,A3,A2,A1,A0) 0b##A7##A6##A5##A4##A3##A2##A1##A0
#define SET_BYTE(Var) Var =0xFF
#define CLEAR_BYTE(Var)=0x00

#endif /* BITMATH_H_ */
