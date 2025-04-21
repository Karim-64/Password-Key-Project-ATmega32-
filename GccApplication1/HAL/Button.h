/*
 * Button.h
 *
 * Created: 8/28/2024 10:32:07 PM
 *  Author: pc
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../MCAL/DIO.h"

#define B_PORT PORTD_ID

#define Button0 PIN2_ID
#define Button1 PIN3_ID
#define Button2 PIN4_ID

void BUTTON_voidInit(u8 BUTTON_ID);



#endif /* BUTTON_H_ */