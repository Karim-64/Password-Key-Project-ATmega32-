/*
 * TIMER0_Private.h
 *
 * Created: 9/2/2024 5:58:22 AM
 *  Author: Karim Mohamed
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
#include "../LIB/STD_types.h"



#define TCCR0     (*((volatile u8*)0x53))
#define TIMSK     (*((volatile u8*)0x59))
#define TCNT0     (*((volatile u8*)0x52))
#define OCR0      (*((volatile u8*)0x5C))


// TCCR0 BITS
#define WGM00          6
#define COM01          5
#define COM00          4
#define WGM01          3
#define CS02           2
#define CS01           1
#define CS00           0

// TIMSK BITS
#define TOIE0          0
#define OCIE0          1

/*Timer Mode*/
#define   TIMER0_NORMAL_MODE        0
#define   TIMER0_CTC_MODE           1
#define   TIMER0_PHASECORRECT_MODE  2
#define   TIMER0_FASTPWM_MODE       3

/*Timer prescaler*/
#define    TIMER0_PRESCALER_1                   0
#define    TIMER0_PRESCALER_8                   1
#define    TIMER0_PRESCALER_64                  2
#define    TIMER0_PRESCALER_256                 3
#define    TIMER0_PRESCALER_1024                4
#define    TIMER0_PRESCALER_EXTCLK_FALLEDGE     5
#define    TIMER0_PRESCALER_EXTCLK_RAISEDGE     6

/*Timer OC0 Mode */
#define   TIMER0_OC0_DISCONNECTED        0
#define   TIMER0_OC0_TOG                 1
#define   TIMER0_OC0_CLEAR               2
#define   TIMER0_OC0_SET                 3
#define	  TIMER_OC0_PWM_NON_INVERTING    4
#define	  TIMER_OC0_PWM_INVERTING	 	 5



#endif /* TIMER0_PRIVATE_H_ */