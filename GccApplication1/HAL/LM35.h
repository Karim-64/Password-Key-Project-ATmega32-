/******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: header file for the LM35 Temperature Sensor driver
 *
 * Author: Abdelrahman Fathy
 *
 *******************************************************************************/

#ifndef LM35_SENSOR_H_
#define LM35_SENSOR_H_

#include "../LIB/STD_types.h"
#include "../MCAL/adc.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         ADC_CHANNEL_0  //you can use diff mode
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

#define Sensor_ERROR_OFFSET 1


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 * STEPS:
 * 1-Define 2 variable , Digital value and analog value and initialize them to zero
 * 2- Read the Digital value using functions from ADC driver
 * 3- convert it to analog value and return it
 * hint: go to slide number no 47 for help
 * hint: you will multiply a lot of values with each other, so make to explicitly cast those big values to avoid a overflow error
 */





u8 LM35_getTemperature(u16 digital_signal);

#endif /* LM35_SENSOR_H_ */