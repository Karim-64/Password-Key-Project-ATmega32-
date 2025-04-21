/*
 * GccApplication1.c
 *
 * Created: 9/9/2024 1:36:54 PM
 * Author : pc
 */ 


#include "program.h"

#define F_CPU 8000000UL
#include "util/delay.h"



extern u32 Timer0_NumOfCM;
extern u32 Timer0_NumOfOV;
u32 cnt;


int main(void)
{
	
	KEYPAD_voidInit();
	LCD_voidInit();
	UART_init(9600);
	ADC_init(ADC_Divide_by_4);
	TIMER1_vInit();
	TIMER1_vStart();
	Timer1_SetFastPWMCompareMatch(80);
	Set_password();
	Keypad_Flag=0;
	u8 temp0=0;
	Main_Menu();
    while (1){
		
		Keypad_Input();
		u8 data = KEYPAD_u8ReadButton(Keypad_Row,Keypad_Col);
		if(Keypad_Flag){
			if(data=='+'){
				correct = 0;
				Keypad_Flag=0;
				LCD_ClearScreen();
				LCD_SendString("ENTER PASS:");
				LCD_MoveCursor(LCD_Row1,LCD_Col0);
				Enter_password(3);
				
				if(!correct){
					//error_handling();
					UART_sendString("error");
					forget_pass();
					continue;
				}
				//door();
				UART_sendString("door");
				Main_Menu();
			}
			else if (data=='-'){
				Set_password();
				UART_sendString(pass);
				Main_Menu();
			}
			Keypad_Flag=0;
		}
		u8 digital_signal = ADC_readChannel_single_conv(ADC_CHANNEL_0);
		u8 currTemp = LM35_getTemperature(digital_signal);
	
		if(currTemp!=temp0){
			temp0 = currTemp;
			if(currTemp>35)
			Timer1_SetFastPWMCompareMatch(100);
			else if (currTemp>25 && currTemp<=35)
			Timer1_SetFastPWMCompareMatch(50);
			else if (currTemp>20 &&  currTemp<=25)
			Timer1_SetFastPWMCompareMatch(10);
			else
			Timer1_SetFastPWMCompareMatch(0);
		}
			
			
	}
}



