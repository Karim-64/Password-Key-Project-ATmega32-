/*
 * SERVO.c
 *
 * Created: 2024/09/17 2:51:38 PM
 *  Author: Home
 */ 

#include "SERVO.h"
#include "LCD.h"
#define F_CPU 8000000UL
#include "util/delay.h"


void Servo_Adjust(u16 angle)
{
	/*send the pulse according to the angle passed to the function*/
	u16 Compare = 1000 + ( (angle * 1000.0) / 1800);   
	
	//LCD_DisplayCounter(angle); for tracing the angle of servo motor 
	
	OCR1AH = (Compare>>8);		// to get the higher bits
	OCR1AL = (Compare& 0xFF);	// to get the lower bits
	TIMER1_SetFastPWMICR(19999); // to generate a PWM signal from timer1
}

void Servo_Open(void)
{
	for(u16 x = 900 ; x<=1800; x+=2)
	{
		Servo_Adjust(x);
		_delay_ms(30);
	}
}

void Servo_Close(void)
{
	for(u16 x = 1800 ; x>=900; x-=4)
	{
		Servo_Adjust(x);
		_delay_ms(30);
	}
	Servo_Adjust(899);
}