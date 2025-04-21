/*
 * INTERRUPT.c
 *
 * Created: 2/17/2024 7:54:01 PM
 *  Author: Karim Mohamed
 */ 


#include "EXT_INTERRUPT.h"

void (*EXTI_CallBack[22])() ={NULL} ;


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

void EXTI_voidDisableInterrupt(u8 Copy_u8INT_Number){
	switch(Copy_u8INT_Number){
		case INT0: ClrBit(GICR,GICR_INT0); break;
		case INT1: ClrBit(GICR,GICR_INT1); break;
		case INT2: ClrBit(GICR,GICR_INT2); break;
	}
}


u8 EXTI_u8GetFlag(u8 Copy_u8INT_Number){
	
}

void EXTI_voidSetCallBack(void (*Copy_pvoidCallBack)(void) , u8 Copy_u8INT_Number){
	if(Copy_u8INT_Number!=NULL){
		EXTI_CallBack[Copy_u8INT_Number]=Copy_pvoidCallBack;
	}
}


/*

{

	if( EXTI_CallBack[0] != NULL )
	{	
		EXTI_CallBack[0]();      //  Call The Global Pointer to Function   
	}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if (EXTI_CallBack[1] != NULL)
	{
		EXTI_CallBack[1]();      //  Call The Global Pointer to Function 
	}
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if (EXTI_CallBack[2] != NULL)
	{
		EXTI_CallBack[2]();      //  Call The Global Pointer to Function 
	}
}

*/