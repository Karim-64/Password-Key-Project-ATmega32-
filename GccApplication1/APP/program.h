/*
 * main.h
 *
 * Created: 9/19/2024 2:04:27 PM
 *  Author: pc
 */ 
#include "../MCAL/DIO.h"
#include "../MCAL/EXT_INTERRUPT.h"
#include "../HAL/LED.h"
#include "../MCAL/TIMER1_Private.h"
#include "../MCAL/Timer1_Interface.h"
#include "../MCAL/Timer1_Config.h"
#include "../HAL/LCD.h"
#include "../HAL/Keypad.h"
#include "../MCAL/Timer1_Config.h"
#include "../MCAL/Timer1_Interface.h"
#include "../MCAL/TIMER1_Private.h"
#include "../HAL/Buzzer.h"
#include "../MCAL/adc.h"
#include "../MCAL/UART_configuration.h"
#include "../MCAL/UART_interface.h"
#include "../MCAL/UART_private.h"
#include "../HAL/LM35.h"

#ifndef PROGRAM_H_
#define PROGRAM_H_

void Set_password(void);
void Setup_password(void);
void Enter_password(u8 trials);
void Main_Menu(void);
void forget_pass(void);
void door();
void error_handling(void);

extern u8 Keypad_Flag ;
extern u8 Keypad_Row;
extern u8 Keypad_Col;
u32 cnt;

u8 counter;

u8 correct ;
u8 pass[5];




#endif /* MAIN_H_ */