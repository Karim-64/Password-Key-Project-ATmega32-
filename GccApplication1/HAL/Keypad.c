/*
 * Keypad.c
 *
 * Created: 9/1/2024 8:16:25 PM
 *  Author: pc
 */ 
#include "Keypad.h"
#define F_CPU 8000000UL
#include <util/delay.h>

u8 KEYPAD_CHARACTERS[5][5] = {{'7','8','9','/'},{'4','5','6','X'},{'1','2','3','-'}, {'f','0','=','+'}};
	
void KEYPAD_voidInit(){
	DIO_voidSetPortDirection(KEYPAD_PORT,0x0F);
	DIO_voidSetPortValue(KEYPAD_PORT,0);
}


u8 KEYPAD_u8ReadButton(u8 row, u8 col){
	
	return KEYPAD_CHARACTERS[row][col];
	
}

/*to input the signals from the keypad to detect input letters*/
void Keypad_Input(){
	for(u8 Row = KEYPAD_ROW0; Row<=KEYPAD_ROW3; Row++){
		DIO_voidSetPinValue(KEYPAD_PORT,Row,1);
		for(u8 Col = KEYPAD_COL0 ; Col <= KEYPAD_COL3 ; Col++){
			if(DIO_u8GetPinValue(KEYPAD_PORT,Col)){
				while(DIO_u8GetPinValue(KEYPAD_PORT,Col)){
					continue;
				}
				Keypad_Flag=1;
				Keypad_Row = Row;
				Keypad_Col = Col - 4;
				DIO_voidSetPinValue(KEYPAD_PORT,Row,PIN_LOW);
				return;
			}
		}
		DIO_voidSetPinValue(KEYPAD_PORT,Row,PIN_LOW);
		_delay_ms(5);
	}
}