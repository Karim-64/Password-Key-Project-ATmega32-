/*
 * program.c
 *
 * Created: 9/19/2024 2:05:00 PM
 *  Author: pc
 */ 

#include "program.h"
#define F_CPU 8000000UL
#include "util/delay.h"

extern u8 Keypad_Flag=0;
u8 correct=0;

void Set_password(){
	
	/*********text for the user*************/
	LCD_SendString("Plz enter pass:");
	LCD_MoveCursor(LCD_Row1,LCD_Col0);
	Keypad_Flag=0;
	
	/*****receiving the 5 letters of pass****/
	for(u8 pass_char = 0; pass_char<5; ++pass_char){
		while(!Keypad_Flag){
			Keypad_Input();
		}
		
		/**to make sure the user doen't include the on/off button***/
		
		if(KEYPAD_u8ReadButton(Keypad_Row,Keypad_Col)=='f'){
			Keypad_Flag=0;
			--pass_char;
			continue;
		}
		
		//assigning the letter in the password array
		pass[pass_char] = KEYPAD_u8ReadButton(Keypad_Row,Keypad_Col);
		Keypad_Flag=0;
		LCD_voidSendData('*');
		_delay_ms(5);
	}
	
	//waiting the user to press on the "enter" button
	while(1){
		Keypad_Input();
		if(Keypad_Flag==1 && KEYPAD_u8ReadButton(Keypad_Row,Keypad_Col)=='='){
			Keypad_Flag=0;
			LCD_ClearScreen();
			break;
		}
	}
	UART_sendString(pass);
	
}



/*this function is for entering password*/
void Enter_password(u8 trials){
	
	
	
	/*3 trial for the user to input the right password*/
	
	while(trials--){
		for(u8 pass_char = 0; pass_char<5; ++pass_char){
			while(!Keypad_Flag){
				Keypad_Input();
			}
			
			if(KEYPAD_u8ReadButton(Keypad_Row,Keypad_Col)=='f'){
				Keypad_Flag=0;
				--pass_char;
				continue;
			}
			
			pass[pass_char] = KEYPAD_u8ReadButton(Keypad_Row,Keypad_Col);
			
			Keypad_Flag=0;
			LCD_voidSendData('*');
			_delay_ms(5);
		}
		
		while(1){
			Keypad_Input();
			if(Keypad_Flag==1 && KEYPAD_u8ReadButton(Keypad_Row,Keypad_Col)=='='){
				Keypad_Flag=0;
				LCD_ClearScreen();
				break;
			}
		}
		
		/*check if the password is right*/
		UART_sendString(pass);
		u8 equal_flag = UART_recieveByte();
		
		if(equal_flag == '1'){
			correct = 1;
			return;
		}
		if(trials!=0){
			LCD_ClearScreen();
			LCD_voidSendData((trials)+'0');
			LCD_SendString(" trials left:");
			LCD_MoveCursor(LCD_Row1,LCD_Col0);
		}
	}
	
}

// it's the display of the MENU option
void Main_Menu(){
	
	LCD_ClearScreen();
	LCD_SendString("+: open door");
	LCD_MoveCursor(LCD_Row1,LCD_Col0);
	LCD_SendString("-: change pass");
}

// void Setup_password(){
// 	LCD_ClearScreen();
// 	Set_password();
// 	LCD_SendString("Re-enter pass:");
// 	LCD_MoveCursor(LCD_Row1,LCD_Col0);
// 	correct=0;
// 	Enter_password(3);
// }


void forget_pass(){
	LCD_ClearScreen();
	LCD_SendString("forgot password?");
	LCD_MoveCursor(LCD_Row1,LCD_Col0);
	LCD_SendString("+: YES  -: NO");
	while(1){
		Keypad_Input();
		if(Keypad_Flag==1){
			u8 data2 = KEYPAD_u8ReadButton(Keypad_Row,Keypad_Col);
			if(data2 == '+'){
				LCD_ClearScreen();
				LCD_SendString("confirm you are");
				LCD_MoveCursor(LCD_Row1,LCD_Col0);
				LCD_SendString("not a Robot");
				Keypad_Flag=0;
				while(!Keypad_Flag){
					Keypad_Input();
				}
				LCD_ClearScreen();
				Set_password();
				break;
			}
			else if (data2=='-'){
				Keypad_Flag=0;
				break;
			}
		}
	}
	Main_Menu();
}

// void door(){
// 	LCD_ClearScreen();
// 	LCD_SendString("Unlocking Door");
// 	Servo_Open();
// 	
// 	_delay_ms(3000);
// 	
// 	LCD_ClearScreen();
// 	LCD_SendString("Locking Door");
// 	Servo_Close();
// 	
// }

void error_handling(){
// 	BUZZER_TurnON(PORTD_ID,PIN0_ID);
// 	u8 remaining_time = 10;
// 	LCD_SendString("Error, try again");
// 	LCD_MoveCursor(LCD_Row1,LCD_Col0);
// 	LCD_SendString("after 10 sec");
// 	LCD_MoveCursor(LCD_Row1,LCD_Col6);
// 	cnt=0;
// 	counter=0;
// 	while (remaining_time)
// 	{
// 		if(counter==1){
// 		--remaining_time;
// 		LCD_DisplayCounter(remaining_time);
// 		LCD_SendString(" sec    ");
// 		LCD_MoveCursor(LCD_Row1,LCD_Col6);
// 		counter=0;
// 		}
// 	}
// 	BUZZER_TurnOFF(PORTD_ID,PIN0_ID);
}
