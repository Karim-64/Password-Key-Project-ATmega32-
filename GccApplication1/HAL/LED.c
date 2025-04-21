/*
 * LED.c
 *
 * Created: 9/8/2024 7:34:09 PM
 *  Author: pc
 */ 
#include "LED.h"

void LED_voidInit(u8 LED_NO){
	switch(LED_NO){
		case LED1_ID: DIO_voidSetPinDirection(LED_PORT,LED1_PIN,PIN_OUTPUT); break;
		case LED2_ID: DIO_voidSetPinDirection(LED_PORT,LED2_PIN,PIN_OUTPUT); break;
		case LED3_ID: DIO_voidSetPinDirection(LED_PORT,LED3_PIN,PIN_OUTPUT); break;
	}
}

void LED_On(u8 LED_NO){
	switch(LED_NO){
		case LED1_ID: DIO_voidSetPinValue(LED_PORT,LED1_PIN,PIN_HIGH); break;
		case LED2_ID: DIO_voidSetPinValue(LED_PORT,LED2_PIN,PIN_HIGH); break;
		case LED3_ID: DIO_voidSetPinValue(LED_PORT,LED3_PIN,PIN_HIGH); break;
	}
}

void LED_OFF(u8 LED_NO){
	switch(LED_NO){
		case LED1_ID: DIO_voidSetPinValue(LED_PORT,LED1_PIN,PIN_LOW); break;
		case LED2_ID: DIO_voidSetPinValue(LED_PORT,LED2_PIN,PIN_LOW); break;
		case LED3_ID: DIO_voidSetPinValue(LED_PORT,LED3_PIN,PIN_LOW); break;
	}
}

void LED_Toggle(u8 LED_NO){
	switch(LED_NO){
	case LED1_ID:
	ToggleBit(PORTD,LED1_PIN); break;
	
	case LED2_ID:
	ToggleBit(PORTD,LED2_PIN); break;
	
	case LED3_ID:
	ToggleBit(PORTD,LED3_PIN); break;
 }

	
}