/*
 * Buzzer.c
 *
 * Created: 2024/09/21 2:27:21 AM
 *  Author: Karim Maaty
 */ 

#include "BUZZER.h"

void BUZZER_SetPin(u8 PORT_ID, u8 PIN_ID)
{
	DIO_voidSetPinDirection(PORT_ID,PIN_ID,PIN_OUTPUT);
}

void BUZZER_TurnON(u8 PORT_ID, u8 PIN_ID)
{
	DIO_voidSetPinValue(PORT_ID,PIN_ID,PIN_HIGH);
}

void BUZZER_TurnOFF(u8 PORT_ID, u8 PIN_ID)
{
	DIO_voidSetPinValue(PORT_ID,PIN_ID,PIN_LOW);
}