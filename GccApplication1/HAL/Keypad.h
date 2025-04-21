/*
 * Keypad.h
 *
 * Created: 9/1/2024 8:16:14 PM
 *  Author: pc
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "../MCAL/DIO.h"
#include "../LIB/STD_types.h"
#include "LCD.h"

#define KEYPAD_PORT PORTC_ID

#define KEYPAD_ROW0 PIN0_ID
#define KEYPAD_ROW1 PIN1_ID
#define KEYPAD_ROW2 PIN2_ID
#define KEYPAD_ROW3 PIN3_ID
#define KEYPAD_COL0 PIN4_ID
#define KEYPAD_COL1 PIN5_ID
#define KEYPAD_COL2 PIN6_ID
#define KEYPAD_COL3 PIN7_ID

u8 Keypad_Flag;
u8 Keypad_Row;
u8 Keypad_Col;


void KEYPAD_voidInit(void);
u8 KEYPAD_u8ReadButton(u8 row, u8 col);
void KEYPAD_voidOutput(void);
void Keypad_Input(void);

#endif /* KEYPAD_H_ */