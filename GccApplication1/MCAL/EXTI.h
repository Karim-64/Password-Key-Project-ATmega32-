/*
 * EXTI.h
 *
 * Created: 9/2/2024 4:56:56 PM
 *  Author: Karim Mohamed
 */ 


#ifndef EXTI_H_
#define EXTI_H_
#include "DIO.h"
#define sei()     __asm__

#define NULL                 0

#define SREG		  *( (volatile u8 *) 0x5F )
#define SREG_I        7

#define GICR		*( (volatile u8 *) 0x5B )
#define GICR_INT0    6
#define GICR_INT1    7
#define GICR_INT2    5


#define GIFR		*( (volatile u8 *) 0x5A )
#define GIFR_INT0    6
#define GIFR_INT1    7
#define GIFR_INT2    5

#define MCUCR		*( (volatile u8 *) 0x55 )
#define MCUCR_ISC00    0
#define MCUCR_ISC01    1
#define MCUCR_ISC10    2
#define MCUCR_ISC11    3


#define MCUCSR		*( (volatile u8 *) 0x54 )
#define MCUCSR_ISC2     6



#define LOW_LEVEL         0
#define LOGICAL_CHANGE    1
#define FALLING_EDGE      2
#define RISING_EDGE       3


void EXTI_voidGlobalEnable(void);
void EXTI_voidGlobalDisable(void);
void EXTI_voidInit(u8 Copy_u8INT_Number, u8 Copy_u8Contol_Sensor);




#endif /* EXTI_H_ */