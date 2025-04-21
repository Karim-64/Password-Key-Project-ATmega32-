/*
 * SERVO.h
 *
 * Created: 2024/09/17 2:51:50 PM
 *  Author: Home
 */ 



#ifndef SERVO_H_
#define SERVO_H_

#include "../MCAL/Timer1_Config.h"
#include "../MCAL/Timer1_Interface.h"
#include "../MCAL/TIMER1_Private.h"
#include "../LIB/STD_types.h"
#define F_CPU 8000000UL
#include "util/delay.h"


void Servo_Adjust(u16 angle);
void Servo_Open(void);
void Servo_Close(void);



#endif /* SERVO_H_ */