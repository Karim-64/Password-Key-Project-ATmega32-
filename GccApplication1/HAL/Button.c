/*
 * Button.c
 *
 * Created: 8/28/2024 10:32:17 PM
 *  Author: pc
 */ 

#include "Button.h"

void BUTTON_voidInit(u8 BUTTON_ID){
	DIO_voidSetPinDirection(B_PORT,BUTTON_ID,PIN_INPUT);
 	DIO_voidSetPinValue(B_PORT,BUTTON_ID,PIN_HIGH);
}

