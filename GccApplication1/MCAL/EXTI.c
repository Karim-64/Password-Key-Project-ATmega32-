/*
 * EXTI.c
 *
 * Created: 9/2/2024 4:57:06 PM
 *  Author: Karim Mohamed
 */ 

#include "EXTI.h"

void (*EXTI_CallBack[3])() ={NULL} ;

	


void EXTI_voidGlobalEnable(){
	SetBit(SREG,SREG_I);
}

void EXTI_voidGlobalDisable(){
	ClrBit(SREG,SREG_I);
}

void EXTI_voidInit(u8 Copy_u8INT_Number, u8 Copy_u8Contol_Sensor){
	switch(Copy_u8INT_Number){
		case 0: SetBit(GICR, GICR_INT0);
		switch(Copy_u8Contol_Sensor){
			case LOW_LEVEL:
			ClrBit(MCUCR,MCUCR_ISC00);
			ClrBit(MCUCR,MCUCR_ISC01);
			break;
			case LOGICAL_CHANGE:
			SetBit(MCUCR,MCUCR_ISC00);
			ClrBit(MCUCR,MCUCR_ISC01);
			break;
			case FALLING_EDGE:
			ClrBit(MCUCR,MCUCR_ISC00);
			SetBit(MCUCR,MCUCR_ISC01);
			break;
			case RISING_EDGE:
			SetBit(MCUCR,MCUCR_ISC00);
			SetBit(MCUCR,MCUCR_ISC01);
			break;
		}
		break;
		
		case 1: SetBit(GICR, GICR_INT1);
		switch(Copy_u8Contol_Sensor){
			case LOW_LEVEL:
			ClrBit(MCUCR,MCUCR_ISC10);
			ClrBit(MCUCR,MCUCR_ISC11);
			break;
			case LOGICAL_CHANGE:
			SetBit(MCUCR,MCUCR_ISC10);
			ClrBit(MCUCR,MCUCR_ISC11);
			break;
			case FALLING_EDGE:
			ClrBit(MCUCR,MCUCR_ISC10);
			SetBit(MCUCR,MCUCR_ISC11);
			break;
			case RISING_EDGE:
			SetBit(MCUCR,MCUCR_ISC10);
			SetBit(MCUCR,MCUCR_ISC11);
			break;
		}
		 break;
		 
		case 2: SetBit(GICR, GICR_INT2);
		switch(Copy_u8Contol_Sensor){
			case FALLING_EDGE:
			ClrBit(MCUCSR, MCUCSR_ISC2);
			break;
			
			case RISING_EDGE:
			SetBit(MCUCSR, MCUCSR_ISC2);
			break;
		}
		break;
	}
	
	
}