/*
 * DIO.c
 *
 * Created: 8/22/2024 6:44:03 PM
 *  Author: Karim Mohamed
 */ 
#include "DIO.h"

void DIO_voidSetPinDirection (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8DIRECTION){
	if(Copy_u8DIRECTION==0){
	switch(Copy_u8PORT){
		case PORTA_ID:
		ClrBit(DDRA,Copy_u8PIN);
		break;
		case PORTB_ID:
		ClrBit(DDRB,Copy_u8PIN);
		break;
		case PORTC_ID:
		ClrBit(DDRC,Copy_u8PIN);
		break;
		case PORTD_ID:
		ClrBit(DDRD,Copy_u8PIN);
		break;
	}
	}
	else if (Copy_u8DIRECTION==1){
		switch(Copy_u8PORT){
		case PORTA_ID:
		SetBit(DDRA,Copy_u8PIN);
		break;
		case PORTB_ID:
		SetBit(DDRB,Copy_u8PIN);
		break;
		case PORTC_ID:
		SetBit(DDRC,Copy_u8PIN);
		break;
		case PORTD_ID:
		SetBit(DDRD,Copy_u8PIN);
		break;
		}
	}
}


void DIO_voidSetPinValue (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8VALUE){
	if(Copy_u8VALUE==0){
		switch(Copy_u8PORT){
			case PORTA_ID:
			ClrBit(PORTA,Copy_u8PIN);
			break;
			case PORTB_ID:
			ClrBit(PORTB,Copy_u8PIN);
			break;
			case PORTC_ID:
			ClrBit(PORTC,Copy_u8PIN);
			break;
			case PORTD_ID:
			ClrBit(PORTD,Copy_u8PIN);
			break;
		}
	}
		else if (Copy_u8VALUE==1){
			switch(Copy_u8PORT){
			case PORTA_ID:
			SetBit(PORTA,Copy_u8PIN);
			break;
			case PORTB_ID:
			SetBit(PORTB,Copy_u8PIN);
			break;
			case PORTC_ID:
			SetBit(PORTC,Copy_u8PIN);
			break;
			case PORTD_ID:
			SetBit(PORTD,Copy_u8PIN);
			break;
		}
	}
}

void DIO_voidSetPortDirection (u8 Copy_u8PORT , u8 Copy_u8Direction ){
	u8 PORT_DIRECTION = Copy_u8Direction;
	
	switch(Copy_u8PORT){
		case PORTA_ID:
		DDRA = PORT_DIRECTION;
		break;
		case PORTB_ID:
		DDRB = PORT_DIRECTION;
		break;
		case PORTC_ID:
		DDRC = PORT_DIRECTION;
		break;
		case PORTD_ID:
		DDRD = PORT_DIRECTION;
		break;
	}
}

void DIO_voidSetPortValue (u8 Copy_u8PORT , u8 Copy_u8VALUE ){
	u8 PORT_VALUE = Copy_u8VALUE;
	switch(Copy_u8PORT){
		case PORTA_ID:
		PORTA = PORT_VALUE;
		break;
		case PORTB_ID:
		PORTB = PORT_VALUE;
		break;
		case PORTC_ID:
		PORTC = PORT_VALUE;
		break;
		case PORTD_ID:
		PORTD = PORT_VALUE;
		break;
	}
}

u8 DIO_u8GetPinValue (u8 Copy_u8PORT , u8 Copy_u8PIN ){
	u8 INPUT_VALUE;
	switch (Copy_u8PORT){
		case PORTA_ID:
		INPUT_VALUE = GetBit(PINA,Copy_u8PIN);
		break;
		case PORTB_ID:
		INPUT_VALUE = GetBit(PINB,Copy_u8PIN);
		break;
		case PORTC_ID:
		INPUT_VALUE = GetBit(PINC,Copy_u8PIN);
		break;
		case PORTD_ID:
		INPUT_VALUE = GetBit(PIND,Copy_u8PIN);
		break;
	}
	return INPUT_VALUE;
}


void DIO_voidTogglePinValue(u8 Copy_u8PORT , u8 Copy_u8PIN){
	switch(Copy_u8PORT){
		case PORTA_ID: ToggleBit(PORTA,Copy_u8PIN);
		break;
		case PORTB_ID: ToggleBit(PORTB,Copy_u8PIN);
		break;
		case PORTC_ID: ToggleBit(PORTC,Copy_u8PIN);
		break;
		case PORTD_ID: ToggleBit(PORTD,Copy_u8PIN);
		break;
	}
}
