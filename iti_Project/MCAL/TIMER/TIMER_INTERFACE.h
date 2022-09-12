#ifndef  TIMER_INTERFACE_H
#define  TIMER_INTERFACE_H


void TIMER0_INT(void);
u8 Timer0_SetCallBack(void(*Lpf)(void),u8 index);
void TIMER1_INT(void);
void Timer1SetAngle_A(u16 OCRA);
#endif
