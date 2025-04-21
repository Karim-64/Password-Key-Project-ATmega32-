/*
 * Buzzer.h
 *
 * Created: 2024/09/21 2:27:35 AM
 *  Author: Karim Maaty
 */ 

#include "../MCAL/DIO.h"

#ifndef BUZZER_H_
#define BUZZER_H_

void BUZZER_SetPin(u8 PORT_ID, u8 PIN_ID);
void BUZZER_TurnON(u8 PORT_ID, u8 PIN_ID);
void BUZZER_TurnOFF(u8 PORT_ID, u8 PIN_ID);

#endif /* BUZZER_H_ */