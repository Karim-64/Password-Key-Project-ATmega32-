/******************************************************************************
 *
 * Created: 2024/09/18 6:35:39 PM
 * Author: Karim Mohamed
 *
 *******************************************************************************/
 
#ifndef UART_UART_CONFIGURATION_H_
#define UART_UART_CONFIGURATION_H_

#define F_CPU				8000000UL
/*
 * Choose data size:
 * UART_DATA_SIZE_5_BITS
 * UART_DATA_SIZE_6_BITS
 * UART_DATA_SIZE_7_BITS
 * UART_DATA_SIZE_8_BITS
 */
#define UART_DATA_SIZE		UART_DATA_SIZE_8_BITS

/*
 * Choose parity:
 * UART_PARITY_ODD
 * UART_PARITY_EVEN
 * UART_PARITY_NO_PARITY
 */
#define UART_PARITY			UART_PARITY_NO_PARITY

/*
 * Choose stop bits:
 * UART_STOP_BITS_1
 * UART_STOP_BITS_2
 */
#define UART_STOP_BITS		UART_STOP_BITS_1




/*  
  choose the speed of the transmission
  UART_NORMAL_SPEED
  UART_DOUBLE_SPEED
*/
#define UART_TRANSMISSION_SPEED     UART_DOUBLE_SPEED

#endif /* UART_UART_CONFIGURATION_H_ */