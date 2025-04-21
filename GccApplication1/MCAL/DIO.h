/*
 * DIO.h
 *
 * Created: 13/8/2024 2:41:48 AM
 * Author: Karim Mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../LIB/BitMath.h"
#include "../LIB/STD_types.h"


#define PORTA		*( (volatile u8 *) 0x3B )
#define DDRA		*( (volatile u8 *) 0x3A )
#define PINA		*( (volatile u8 *) 0x39 )

#define PORTA		*( (volatile u8 *) 0x3B )
#define DDRA		*( (volatile u8 *) 0x3A )
#define PINA		*( (volatile u8 *) 0x39 )

#define PORTB		*( (volatile u8 *) 0x38 )
#define DDRB		*( (volatile u8 *) 0x37 )
#define PINB		*( (volatile u8 *) 0x36 )

#define PORTC		*( (volatile u8 *) 0x35 )
#define DDRC		*( (volatile u8 *) 0x34 )
#define PINC		*( (volatile u8 *) 0x33 )

#define PORTD		*( (volatile u8 *) 0x32 )
#define DDRD		*( (volatile u8 *) 0x31 )
#define PIND		*( (volatile u8 *) 0x30 )

/*******************************Definitions******************************************/

#define PORTA_ID 0    
#define PORTB_ID 1
#define PORTC_ID 2
#define PORTD_ID 3

#define PIN0_ID 0
#define PIN1_ID 1
#define PIN2_ID 2
#define PIN3_ID 3
#define PIN4_ID 4
#define PIN5_ID 5
#define PIN6_ID 6
#define PIN7_ID 7

/*Timer pins */

 

#define PIN_LOW		0
#define PIN_HIGH	1

#define PIN_INPUT	0
#define PIN_OUTPUT	1

#define PORT_INPUT	0
#define PORT_OUTPUT	0xFF

#define PORT_LOW	0
#define PORT_HIGH	0xFF

/*******************************Functions*****************************************/



void DIO_voidSetPinDirection (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8DIRECTION);

void DIO_voidSetPinValue (u8 Copy_u8PORT , u8 Copy_u8PIN , u8 Copy_u8VALUE);

void DIO_voidSetPortValue (u8 Copy_u8PORT , u8 Copy_u8VALUE);

u8 DIO_u8GetPinValue (u8 Copy_u8PORT , u8 Copy_u8PIN );

void DIO_voidSetPortDirection (u8 Copy_u8PORT , u8 Copy_u8Direction );

void DIO_voidTogglePinValue(u8 Copy_u8PORT , u8 Copy_u8PIN);
















#endif /* DIO_H_ */