/*
 * TIMER0_program.c
 *
 * Created: 9/2/2024 4:37:55 PM
 *  Author: Abanoub Osama
 */ 


#include "TIMER0_Private.h"
#include "TIMER0_Config.h"
#include "TIMER0_interface.h"
#include "../LIB/STD_types.h"
#include "EXT_INTERRUPT.h"
#include "DIO.h"
#include <stdlib.h>
#define F_CPU 800000UL
#include "util/delay.h"


u32  Timer0_NumOfOV = 0;
u32  Timer0_NumOfCM = 0;
u8 PWM_PORT = 1;
u8 PB3 = 3;
void Timer0_voidInit(void)
{
	// step 1 : config Timer Mode
	

	#if (TIMER0_MODE==TIMER0_NORMAL_MODE)
	
		ClrBit(TCCR0,WGM00);
		ClrBit(TCCR0,WGM01);
		
	#elif (TIMER0_MODE == TIMER0_CTC_MODE)
		ClrBit(TCCR0,WGM00);
		SetBit(TCCR0,WGM01);
		
	#elif (TIMER0_MODE == TIMER0_FASTPWM_MODE)
		SetBit(TCCR0,WGM00);
		SetBit(TCCR0,WGM01);
	
	#elif (TIMER0_MODE == TIMER0_PHASECORRECT_MODE)
		SetBit(TCCR0,WGM00);
		ClrBit(TCCR0,WGM01);
		
	
	#endif



}


void Timer0_voidEnableInt(u8 IntId)
{
	// step 2 : Enable interrupt Mode

	sei();
	switch(IntId){
		case TIMER0_OVF_INT_ID: SetBit(TIMSK,TOIE0); break;
		case TIMER0_COMP_MATCH_INT_ID: SetBit(TIMSK,OCIE0); break;
		default: break;
	}



}


void Timer0_voidDisableInt(u8 IntId)
{

	switch(IntId){
		case TIMER0_OVF_INT_ID: ClrBit(TIMSK,TOIE0); break;
		case TIMER0_COMP_MATCH_INT_ID: ClrBit(TIMSK,OCIE0); break;
		default: break;
	}
}


void Timer0_voidStart(void)
{
	//step 1 : clear TCNT0
	
	ClrBit(TCCR0,CS00);
	ClrBit(TCCR0,CS01);
	ClrBit(TCCR0,CS02);
	
	
	//step 2 : insert clock
	#if( TIMER0_PRESCALER ==  TIMER0_PRESCALER_1 )
	
	SetBit(TCCR0,CS00);
	ClrBit(TCCR0,CS01);
	ClrBit(TCCR0,CS02);
	
	
	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_8 )

	ClrBit(TCCR0,CS00);
	SetBit(TCCR0,CS01);
	ClrBit(TCCR0,CS02);	
	

	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_64 )

	SetBit(TCCR0,CS00);
	SetBit(TCCR0,CS01);
	ClrBit(TCCR0,CS02);

	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_256 )
	
	SetBit(TCCR0,CS02);
	ClrBit(TCCR0,CS01);
	ClrBit(TCCR0,CS00);


	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_1024)
	
	SetBit(TCCR0,CS02);
	ClrBit(TCCR0,CS01);
	SetBit(TCCR0,CS00);


	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_EXTCLK_FALLEDGE)
	
	SetBit(TCCR0,CS02);
	SetBit(TCCR0,CS01);
	ClrBit(TCCR0,CS00);

	
	#elif( TIMER0_PRESCALER ==  TIMER0_PRESCALER_EXTCLK_RAISEDGE)
	
	SetBit(TCCR0,CS02);
	SetBit(TCCR0,CS01);
	SetBit(TCCR0,CS00);


	#endif
}

void Timer0_voidStop(void)
{
	// Clear all clock selection bits to stop the timer
	ClrBit(TCCR0,CS00);
	ClrBit(TCCR0,CS01);
	ClrBit(TCCR0,CS02);
}


void Timer0_voidSetTime(u32 DesiredTime_ms)
{
	// Array of prescaler values --> u32
	u32 prescaler[5] = {1,8,64,256,1024}; 

	// Calculate the tick time in microseconds u32---> // result will be in micro 
	u32 tickfreq =  1000 * F_OSC/ prescaler[TIMER0_PRESCALER] ;
	

	// Calculate the total number of ticks required u32

	u32 Total_Ticks = DesiredTime_ms * tickfreq;
	
	// If the timer is in Normal mode
	#if( TIMER0_MODE ==  TIMER0_NORMAL_MODE )
	
	// Calculate the number of overflows required (How many times does it go to the ISR)
	Timer0_NumOfOV = Total_Ticks / 256;
	
	// If the timer is in CTC mode
	#elif( TIMER0_MODE ==  TIMER0_CTC_MODE )
	
	u8 Maximum_Count = 255;

	// Find the appropriate compare match value (HINT : % )
	
	u8 Compare_Count = Maximum_Count;
	u8 Count = Maximum_Count;
	while(Count>0){
		if(Total_Ticks%Count==0){ 
			Compare_Count = Count;
			break;  
		}
		--Count;
	}
	
	
	
	// Set the output compare register
	
	OCR0 = Compare_Count;
	
	// Calculate the number of compare matches required
	
	Timer0_NumOfCM = Total_Ticks/Compare_Count;
	
	
	#endif
}


// Function to set the duty cycle for Fast PWM mode
void Timer0_SetFastPWM(u8 DutyCycle)
{
	// Set pin PB3 (OC0) as output
	DIO_voidSetPinDirection(PWM_PORT,PB3,PIN_OUTPUT);
	
	//check the TIMER0 mode

	
	if(TIMER0_MODE == TIMER0_FASTPWM_MODE){
		

	//check the output signal mode (NON_INVERTING)
	if (TIMER0_OC0_MODE == TIMER_OC0_PWM_NON_INVERTING){
		
		//for NON_INVERTING  select non-inverting mode
		SetBit(TCCR0,COM01);
		ClrBit(TCCR0,COM00);
		
		// Set the duty cycle for non-inverting mode --> value should be set on OCR0
		u32 COMP = DutyCycle * 256 / 100;
		OCR0 = abs(COMP-1);
		
	}
	

	

	//-----------------------------------------------------------//

	//check the output signal mode (INVERTING)
	if (TIMER0_OC0_MODE == TIMER_OC0_PWM_INVERTING){
		
		//for INVERTING  select inverting mode
		SetBit(TCCR0,COM01);
		SetBit(TCCR0,COM00);
		
		// Set the duty cycle for inverting mode --> value should be set on OCR0
		u32 COMP = (1-DutyCycle) * 256 / 100;
		OCR0 = abs(COMP-1);
	}
	}

	//-----------------------------------------------------------//

}



// Function to set the duty cycle for Phase Correct PWM mode
void Timer0_SetPhaseCorrect(u8 DutyCycle)
{
	// Set pin PB3 (OC0) as output
	DIO_voidSetPinDirection(PWM_PORT,PB3,PIN_OUTPUT);

	//check the TIMER0 mode
	if(TIMER0_MODE == TIMER0_PHASECORRECT_MODE){

	//check the output signal mode (NON_INVERTING)
	if (TIMER0_OC0_MODE == TIMER_OC0_PWM_NON_INVERTING){
		
		//for NON_INVERTING  select non-inverting mode
		SetBit(TCCR0,COM01);
		ClrBit(TCCR0,COM00);
		
		// Set the duty cycle for non-inverting mode --> value should be set on OCR0
		u32 COMP = DutyCycle * 256 / 100;
		OCR0 = abs(COMP-1);
	}

	//-----------------------------------------------------------//

	//check the output signal mode (INVERTING)
	if (TIMER0_OC0_MODE == TIMER_OC0_PWM_INVERTING){
		
		//for INVERTING  select inverting mode
		SetBit(TCCR0,COM01);
		SetBit(TCCR0,COM00);
		
		// Set the duty cycle for inverting mode --> value should be set on OCR0
		u32 COMP = (100-DutyCycle) * 256 / 100;
		OCR0 = abs(COMP-1);
	}
	}
	//-----------------------------------------------------------//

}

