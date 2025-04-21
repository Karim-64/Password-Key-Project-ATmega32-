/*
 * LM35.c
 *
 * Created: 9/23/2024 1:53:26 PM
 *  Author: pc
 */ 

#include "LM35.h"



u8 Conversion_Unit = 100;   // the unit is max temp / max voltage of LM035

u8 LM35_getTemperature(u16 digital_signal){
	u16 signal = digital_signal * Conversion_Unit * ADC_REF_VOLT_VALUE;
	u8 temperature = signal / ADC_MAXIMUM_VALUE;
	return temperature;
}
