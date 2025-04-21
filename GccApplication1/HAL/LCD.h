/*
 * LCD.h
 *
 * Created: 8/27/2024 10:09:10 PM
 *  Author: pc
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../MCAL/DIO.h"


// ***************************************************Data Types and variables***************************************************

#define LCD_CONTROL_PORT PORTA_ID
#define LCD_DATA_PORT PORTB_ID

#define LCD_D0 PIN0_ID
#define LCD_D1 PIN1_ID
#define LCD_D2 PIN2_ID
#define LCD_D3 PIN3_ID
#define LCD_D4 PIN4_ID
#define LCD_D5 PIN5_ID
#define LCD_D6 PIN6_ID
#define LCD_D7 PIN7_ID

#define LCD_RS PIN3_ID
#define LCD_RW PIN1_ID
#define LCD_E PIN2_ID


#define	LCD_Row0 0
#define	LCD_Row1 1

#define LCD_Col0 0
#define LCD_Col1 1
#define LCD_Col2 2
#define LCD_Col3 3
#define LCD_Col4 4
#define LCD_Col5 5
#define LCD_Col6 6
#define LCD_Col7 7
#define LCD_Col8 8
#define LCD_Col9 9
#define LCD_Col10 10
#define LCD_Col11 11



// ****************************************************************Functions*****************************************************



void LCD_voidInit(void);

void LCD_voidEnableFunction(void);

void LCD_voidSendCommand(u8 command);

void LCD_voidSendData(u8 data);

void LCD_SendString(const u8 *Str); // this func may write in DDRAM unseen part of it

void LCD_MoveCursor(u8 row,u8 col); // you are not allowed to use the invisible part of the DDRAM

void LCD_ClearScreen(void);

void LCD_SendString_ALW_SEEN (u8 *Str,u8 row,u8 col); // more professional func write in visible region only

void LCD_Scroll_RIGHT(u8 no);

void LCD_Scroll_LEFT(u8 no);

void LCD_SET_CGRAM (u8 address);

void LCD_STORE_CUST_CHAR (u8* arr_char ,u8 no );

void LCD_PRINT_CUST_CHAR (u8 address,u8 x , u8 y);

void LCD_DisplayCounter (u16 counter);



//**********************************************commands*************************************************

#define LCD_FunctionSet 0x38
#define LCD_Display 0x0C              //entire display with cursor off
#define LCD_DisplayWithCursor 0x0F    // entire display with blinking cursor
#define LCD_DisplayClr 0x01
#define LCD_EntryModeSet 0x06
#define LCD_CursorStart 0x80
#define LCD_CursorSecondLine 0xC0
#define LCD_LeftShift 0x18
#define LCD_RightShift 0x1C




#endif /* LCD_H_ */