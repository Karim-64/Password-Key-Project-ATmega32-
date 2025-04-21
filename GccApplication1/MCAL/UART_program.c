#include "UART_interface.h"
#include "UART_configuration.h"
#include "UART_private.h"
#include "../LIB/BitMath.h"
#include "util/delay.h"

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

void UART_init(u32 baud_rate)
{
	u16 ubrr_value = 0;

/* U2X = 1 for double transmission speed */
#if (UART_TRANSMISSION_SPEED == UART_DOUBLE_SPEED)
	SetBit(UCSRA_REG, U2X_BIT);

#else
	ClrBit(UCSRA_REG, U2X_BIT);

#endif

	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * TXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/
	// UCSRB_REG = 0;
	SetBit(UCSRB_REG, RXEN_BIT);
	SetBit(UCSRB_REG, TXEN_BIT);

	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/
	SetBit(UCSRC_REG, URSEL_BIT);
	SetBit(UCSRC_REG, UCSZ0_BIT);
	SetBit(UCSRC_REG, UCSZ1_BIT);

	/* Calculate the UBRR register value */

#if (UART_TRANSMISSION_SPEED == UART_DOUBLE_SPEED)
	ubrr_value = (u16)(((F_CPU / (baud_rate * 8UL))) - 1);

#else
	ubrr_value = (u16)(((F_CPU / (baud_rate * 16UL))) - 1);

#endif

	// use 16UL if you're not using double speed mode

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	ClrBit(UBRRH_REG, URSEL_BIT);
	UBRRH_REG = ubrr_value >> 8;
	UBRRL_REG = ubrr_value;
}

/*
 * Description :
 * Functional responsible for send byte to another UART device.
 */
void UART_sendByte(const u8 data)
{
	while (!GetBit(UCSRA_REG, UDRE_BIT))
		;

	UDR_REG = data;

	_delay_us(100);
}

/*
 * Description :
 * Functional responsible for receive byte from another UART device.
 */
u8 UART_recieveByte(void)
{
	while (!GetBit(UCSRA_REG, RXC_BIT))
		;

	return UDR_REG;
}

/*
 * Description :
 * Send the required string through UART to the other UART device.
 */
void UART_sendString(const u8 *str)
{
	u8 Str_iterator = 0;
	while (str[Str_iterator] != '\0')
	{
		UART_sendByte(str[Str_iterator]);
		Str_iterator++;
		_delay_us(100);
	}
	// UART_sendByte('#'); //to indicate that this is the end of the string
}

void UART_receiveString(u8 *Str)
{
	u8 i = 0;

	/* Receive the first byte */
	Str[i] = UART_recieveByte();

	/* Receive the whole string until the '#' */
	while (Str[i] != '#')
	{
		i++;
		Str[i] = UART_recieveByte();
	}

	/* After receiving the whole string plus the '#', replace the '#' with '\0' */
	Str[i] = '\0';
}
