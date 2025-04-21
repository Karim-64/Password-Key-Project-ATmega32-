/*
 * TIMER0_interface.h
 *
 * Created: 9/2/2024 4:37:10 PM
 *  Author: Karim Mohamed
 */
 
#include "../LIB/STD_types.h"

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

#define TIMER0_OVF_INT_ID          0
#define TIMER0_COMP_MATCH_INT_ID   1

void Timer0_voidInit(void);
void Timer0_voidStop(void);
void Timer0_voidStart(void);
void Timer0_voidEnableInt(u8 IntId);
void Timer0_voidDisableInt(u8 IntId);
void Timer0_voidSetTime(u32 DesiredTime_ms);
void Timer0_SetPhaseCorrect(u8 DutyCycle);
void Timer0_SetFastPWM(u8 DutyCycle);


#endif /* TIMER0_INTERFACE_H_ */