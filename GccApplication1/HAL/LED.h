/*
 * IncFile1.h
 *
 * Created: 9/8/2024 7:33:50 PM
 *  Author: pc
 */ 


#ifndef INCFILE1_H_
#define INCFILE1_H_
#include "../MCAL/DIO.h"

#define LED_PORT PORTD_ID
#define LED1_PIN PIN0_ID
#define LED2_PIN PIN1_ID
#define LED3_PIN PIN2_ID

#define LED1_ID   0
#define LED2_ID   1
#define LED3_ID   2

void LED_voidInit(u8 LED_NO);
void LED_On(u8 LED_NO);
void LED_OFF(u8 LED_NO);
void LED_Toggle(u8 LED_NO);


#endif /* INCFILE1_H_ */