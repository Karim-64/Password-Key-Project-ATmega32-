/*
 * INTERRUPT.h
 *
 * Created: 2/17/2024 7:54:18 PM
 *  Author: Karim Mohamed
 * Description: Header file for the AVR External Interrupt driver
 */ 

#ifndef EXT_INTERRUPT_H
#define EXT_INTERRUPT_H

#include "../LIB/BitMath.h"
#include "../LIB/STD_types.h"


//external interrupts port and pin
#define INT0_PORT PORTD_ID
#define INT1_PORT PORTD_ID
#define INT2_PORT PORTB_ID
#define INT0_PIN  PIN2_ID
#define INT1_PIN  PIN3_ID
#define INT2_PIN  PIN2_ID


#define NULL                 0


#define SREG                 *((volatile u8*) 0x5F)  //Global Interrupt Enable
#define SREG_I               7

#define GICR                 *((volatile u8*) 0x5B)  //Interrupt Enable
#define GICR_INT0            6
#define GICR_INT1            7
#define GICR_INT2            5

#define GIFR                 *((volatile u8*) 0x5A)  //The Flag Enable
#define GIFR_INT0            6
#define GIFR_INT1            7
#define GIFR_INT2            5

#define MCUCR                *((volatile u8*) 0x55)  //MCU Control Register (INT0 & INT1)
#define MCUCR_ISC00          0
#define MCUCR_ISC01          1
#define MCUCR_ISC10          2
#define MCUCR_ISC11          3

#define MCUCSR               *((volatile u8*) 0x54)  //MCU Control and Status Register (INT2)
#define MCUCSR_ISC2          6



/* Copy_u8Sense_Control */
#define      LOW_LEVEL        0
#define      LOGICAL_CHANGE   1
#define      FALLING_EDGE      2
#define      RISING_EDGE      3



// Interrupt Numbers
#define INT0  0
#define INT1  1
#define INT2  2


#define      ENABLED         1
#define      DISABLED        0


//VECT_NO OF INTERRUPTS

#define _VECTOR(N)		__vector_ ## N         // ## -> concatinate     if N=1  ->  __vector_1

/* VECT_NO */
#define INT0_VECT					_VECTOR(1)
#define INT1_VECT					_VECTOR(2)
#define INT2_VECT					_VECTOR(3)
#define TIMER2_COMP_VECT			_VECTOR(4)
#define TIMER2_OVF_VECT 			_VECTOR(5)
#define TIMER1_CAPT_VECT			_VECTOR(6)
#define TIMER1_COMPA_VECT			_VECTOR(7)
#define TIMER1_COMPB_VECT   		_VECTOR(8)
#define TIMER1_OVF_VECT	    		_VECTOR(9)
#define TIMER0_COMP_VECT			_VECTOR(10)
#define TIMER0_OVF_VECT			    _VECTOR(11)
#define SPI_STC_VECT			    _VECTOR(12)
#define USART_RXC_VECT			    _VECTOR(13)
#define USART_UDRE_VECT			    _VECTOR(14)
#define USART_TXC_VECT			    _VECTOR(15)
#define ADC_VECT					_VECTOR(16)
#define EE_RDY_VECT					_VECTOR(17)
#define ANA_COMP_VECT				_VECTOR(18)
#define TWI_VECT					_VECTOR(19)
#define SPM_RDY_VECT				_VECTOR(20)
 
#define  ISR(VECT_NUM)		\
			void VECT_NUM(void) __attribute__((signal));\
			void VECT_NUM(void)



#define sei()		__asm__ __volatile__ ("sei")		//Set Global Interrupt Enable
#define cli()		__asm__ __volatile__ ("cli")		//Close Global Interrupt






void EXTI_voidGlobalINT_Enable();                                                           //IMP

void EXTI_voidGlobalINT_Disable();

void EXTI_voidInit(u8 Copy_u8INT_Number, u8 Copy_u8Sense_Control);                          //IMP IMP IMP

void EXTI_voidDisableInterrupt(u8 Copy_u8INT_Number);

u8   EXTI_u8GetFlag(u8 Copy_u8INT_Number);

void EXTI_voidSetCallBack(void (*Copy_pvoidCallBack)(void) , u8 Copy_u8INT_Number);          //IMP


#endif
