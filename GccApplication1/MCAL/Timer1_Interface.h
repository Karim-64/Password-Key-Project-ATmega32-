/*
 * Timer1_Interface_.h
 *
 * Created: 2024/09/17 5:40:26 PM
 *  Author: Karim Mohamed
 */ 

#include "../LIB/STD_types.h"

#ifndef TIMER1_INTERFACE _H_
#define TIMER1_INTERFACE _H_

void TIMER1_vInit(void);
void TIMER1_vStart(void);
void Timer1_SetFastPWMCompareMatch(f32 DutyCycle);
void TIMER1_SetFastPWMICR(u16 TopValue);

#endif /* TIMER1_INTERFACE _H_ */