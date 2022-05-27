/* Author: Ahmed Nabil
SWC:  DC MOTOR interface
Version:  1.0.
Modified date: August 26, 2021 */
/*************************/

#ifndef DCMOTOR_INTERFACE_H_
#define DCMOTOR_INTERFACE_H_
/*
#define SPEED1 14
#define SPEED2 20
#define SPEED3 8
#define SPEED4 5
*/

void DCMOTOR_voidSetSpeed(u8 ARG_u8Speed, u8 ARG_u8Direction);
void DCMOTOR_voidInit(void);

#endif