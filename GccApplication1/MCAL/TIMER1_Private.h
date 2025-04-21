/*
 * TIMER1_Private.h
 *
 * Created: 2024/09/17 4:26:23 PM
 *  Author: Karim Mohamed
 */ 


#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_

/*Registsers*/
#define TCCR1A		(*((volatile u8*)0x4F))
#define TCCR1B		(*((volatile u8*)0x4E))
#define TCNT1H		(*((volatile u8*)0x4D))
#define TCNT1L		(*((volatile u8*)0x4C))
#define OCR1AH		(*((volatile u8*)0x4B))
#define OCR1AL		(*((volatile u8*)0x4A))
#define OCR1BH		(*((volatile u8*)0x49))
#define OCR1BL		(*((volatile u8*)0x48))
#define ICR1H		(*((volatile u8*)0x47))
#define ICR1L		(*((volatile u8*)0x46))

// TCCR1A Pins
#define WGM10	0
#define WGM11	1
#define COM1B0	4
#define COM1B1	5
#define COM1A0	6
#define COM1A1	7

// TCCR1B Pins
#define CS10	0
#define CS11	1 
#define CS12	2
#define WGM12	3
#define WGM13	4 

/*Timer Mode*/
#define TIMER1_NORMAL_MODE					0
#define TIMER1_FASTPWM_ICR_MODE				14
#define	TIMER1_FASTPWM_COMPAREMATCH_MODE	15

/*Timer prescaler*/
#define	TIMER1_PRESCALER_1				 0
#define	TIMER1_PRESCALER_8				 1
#define	TIMER1_PRESCALER_64				 2
#define	TIMER1_PRESCALER_256			 3
#define	TIMER1_PRESCALER_1024			 4

/*Timer OC1 Mode */
#define   TIMER1_OC1_DISCONNECTED        0
#define   TIMER1_OC1_TOG                 1
#define   TIMER1_OC1_CLEAR               2
#define   TIMER1_OC1_SET                 3
#define	  TIMER1_OC1_PWM_NON_INVERTING   4
#define	  TIMER1_OC1_PWM_INVERTING	 	 5

#endif /* TIMER1_PRIVATE_H_ */