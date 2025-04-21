/*
 * LCD.c
 *
 * Created: 8/27/2024 10:09:18 PM
 *  Author: pc
 */ 

#include "LCD.h"
#define F_CPU 8000000UL
#include <util/delay.h>


void LCD_voidInit(void){
	_delay_ms(40);
	DIO_voidSetPortDirection(LCD_CONTROL_PORT,0xFF);
	DIO_voidSetPortDirection(LCD_DATA_PORT,0xFF);
	
	LCD_voidSendCommand(LCD_FunctionSet);
	LCD_voidSendCommand(LCD_Display);
	LCD_voidSendCommand(LCD_DisplayClr);
	LCD_voidSendCommand(LCD_EntryModeSet);
	LCD_voidSendCommand(LCD_CursorStart);
}

void LCD_voidSendCommand(u8 command){
	DIO_voidSetPinValue (LCD_CONTROL_PORT,LCD_RS,PIN_LOW);
	DIO_voidSetPinValue (LCD_CONTROL_PORT,LCD_RW,PIN_LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT,command);
	LCD_voidEnableFunction();
	
	_delay_ms(10);
}

void LCD_voidSendData(u8 data){
	DIO_voidSetPinValue (LCD_CONTROL_PORT,LCD_RS,PIN_HIGH);
	DIO_voidSetPinValue (LCD_CONTROL_PORT,LCD_RW,PIN_LOW);
	DIO_voidSetPortValue(LCD_DATA_PORT ,data);
	LCD_voidEnableFunction();
	_delay_ms(10);
}

void LCD_voidEnableFunction(void){
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,PIN_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(LCD_CONTROL_PORT,LCD_E,PIN_LOW);
	_delay_ms(1);
}

void LCD_SendString(const u8 *Str){
	u8 Str_iterator=0;
	while(Str[Str_iterator]!='\0'){
		LCD_voidSendData(Str[Str_iterator++]);
	}
	}

void LCD_ClearScreen(void){
	LCD_voidSendCommand(LCD_DisplayClr);
	LCD_voidSendCommand(LCD_CursorStart);
	
}

void LCD_MoveCursor(u8 row,u8 col){
	if(row>1 || row<0 || col>15 || col<0){
		LCD_voidSendCommand(LCD_CursorStart);
	}
	else if (row==0){
		LCD_voidSendCommand(LCD_CursorStart+col);
	}
	else if (row==1){
		LCD_voidSendCommand(LCD_CursorStart+64+col);
	}
	_delay_ms(2);
}

void LCD_DisplayCounter (u16 counter)
{
	u8 str[8];
	u8 i = 0;
	u16 temp ;
	if (counter==0)
	temp = counter+1;
	else
	temp = counter;
	while(temp)
	{
		temp/=10;
		i++;
	}
	str[i]='\0';
	for(u8 j = 0; j<i; j++)
	{
		str[i-j-1]=(counter%10)+'0';
		counter/=10;
	}
	LCD_SendString(str);
}
