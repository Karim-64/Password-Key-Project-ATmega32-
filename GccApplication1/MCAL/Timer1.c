/*
 * Timer1.c
 *
 * Created: 2024/09/17 5:37:39 PM
 *  Author: Karim Mohamed
 */ 

#include "../LIB/STD_types.h"
#include "../LIB/BitMath.h"
#include "TIMER1_Private.h"
#include "TIMER1_Config.h"
#include "Timer1_Interface.h"
#include "EXT_INTERRUPT.h"
#include "DIO.h"
#include <stdlib.h>

void TIMER1_vInit(void)
{
	#if( TIMER1_MODE == TIMER1_NORMAL_MODE)
	#elif( TIMER1_MODE == TIMER1_FASTPWM_COMPAREMATCH_MODE )
	SetBit(TCCR1A,WGM10);
	SetBit(TCCR1A,WGM11);
	SetBit(TCCR1B,WGM12);
	SetBit(TCCR1B,WGM13);
	#elif( TIMER1_MODE == TIMER1_FASTPWM_ICR_MODE)
	ClrBit(TCCR1A,WGM10);
	SetBit(TCCR1A,WGM11);
	SetBit(TCCR1B,WGM12);
	SetBit(TCCR1B,WGM13);
	#endif
}

void TIMER1_vStart(void)
{	
	TCNT1L=0x0;
	TCNT1H=0x0;
	//step 2 : insert clock
	#if( TIMER1_PRESCALER   ==  TIMER1_PRESCALER_1 )
	SetBit(TCCR1B,CS10);
	ClrBit(TCCR1B,CS11);
	ClrBit(TCCR1B,CS12);
	
	#elif( TIMER1_PRESCALER ==  TIMER1_PRESCALER_8 )
	ClrBit(TCCR1B,CS10);
	SetBit(TCCR1B,CS11);
	ClrBit(TCCR1B,CS12);

	#elif( TIMER1_PRESCALER ==  TIMER1_PRESCALER_64 )
	SetBit(TCCR1B,CS10);
	SetBit(TCCR1B,CS11);
	ClrBit(TCCR1B,CS12);
	

	#elif( TIMER1_PRESCALER ==  TIMER1_PRESCALER_256 )
	ClrBit(TCCR1B,CS10);
	ClrBit(TCCR1B,CS11);
	SetBit(TCCR1B,CS12);

	#elif( TIMER1_PRESCALER ==  TIMER1_PRESCALER_1024)
	SetBit(TCCR1B,CS10);
	ClrBit(TCCR1B,CS11);
	SetBit(TCCR1B,CS12);

	#endif
}

void Timer1_SetFastPWMCompareMatch(f32 DutyCycle)
{
	DIO_voidSetPinDirection(PORTD_ID,PIN5_ID,PIN_OUTPUT);
	
	#if( TIMER1_MODE ==	TIMER1_FASTPWM_COMPAREMATCH_MODE)
	
	#if( TIMER1_OC1_MODE == TIMER1_OC1_PWM_NON_INVERTING)
	SetBit(TCCR1A,COM1A1);
	ClrBit(TCCR1A,COM1A0);
	u16 limit = abs(((65536*DutyCycle)/100)-1);
	OCR1AH = (limit>>8);
	OCR1AL = (limit & 0xFF); 
	#endif
	#endif
}

void TIMER1_SetFastPWMICR(u16 TopValue)
{
	// Set OC1A pin
	DIO_voidSetPinDirection(PORTD_ID,PIN5_ID,PIN_OUTPUT);
	
	#if( TIMER1_MODE ==	TIMER1_FASTPWM_ICR_MODE)
		
	#if( TIMER1_OC1_MODE == TIMER1_OC1_PWM_NON_INVERTING)
	
	// Select non-inverting mode
	SetBit(TCCR1A,COM1A1);
	ClrBit(TCCR1A,COM1A0);
	
	// Set TopValue (ICR1) to get 50 Hz
	ICR1H  = (TopValue>>8);			// to get the higher bits
	ICR1L  = (TopValue& 0xFF);		// to get the lower bits
			
	#endif
	#endif
}