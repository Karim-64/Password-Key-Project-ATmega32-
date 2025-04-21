

#include "adc.h"

void ADC_init(u8 ADC_freq_Prescaler){
	ADMUX=0;                     //initialize the register with zero
	
	ADMUX|=(ADC_ref_Type<<6);
	
	ADCSRA = 0;
	
	ADCSRA |= ADC_freq_Prescaler;
	
	SetBit(ADCSRA,ADCSRA_ADEN);
	
	DIO_voidSetPinDirection(PORTA_ID,PIN0_ID,PIN_INPUT);
	
	ADC_enable();
	
}

u16 ADC_readChannel_single_conv(u8 channel_no){
	ADMUX &= 0xE0;
	
	ADMUX|=channel_no;
	
	SetBit(ADCSRA,ADCSRA_ADSC);
	
	while(GetBit(ADCSRA,ADCSRA_ADIF)==0);
	
	SetBit(ADCSRA,ADCSRA_ADIF);
	
	return (ADCL) | (ADCH<<8);
}

u16 ADC_readChannel_diff_mode(u8 option){
	ADMUX &= 0xE0;
	
	ADMUX|=option;
	
	SetBit(ADCSRA,ADCSRA_ADSC);
	
	while(GetBit(ADCSRA,ADCSRA_ADIF)==0);
	
	SetBit(ADCSRA,ADCSRA_ADIF);
	
	return (ADCL) | (ADCH<<8);
}

void ADC_enable(){
	SetBit(ADCSRA,ADCSRA_ADEN);
}

void ADC_disable(){
	ClrBit(ADCSRA,ADCSRA_ADEN);
}