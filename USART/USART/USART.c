/*
 * USART.c
 *
 * Created: 09-03-2016 22:15:21
 *  Author: LALANDHU
 */
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#define BAUD 9600                                   // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)            // set baud rate value for UBRR for asynchronous  normal mode

// function to initialize UART
void uart_init (void)
{
	UBRRH = (BAUDRATE>>8);                      // shift the register right by 8 bits
	UBRRL = BAUDRATE;                           // set baud rate
	UCSRB|= (1<<TXEN)|(1<<RXEN);                // enable receiver and transmitter
	UCSRC|= (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1);   // 8bit data format,UMSEL is 0 as for asynchronous communication,,no parity mode,stop bit one bit
	//for even parity mode,,set UPM1=1,UPM0=0
}
// function to send data - NOT REQUIRED FOR THIS PROGRAM IMPLEMENTATION
void uart_transmit (unsigned char data)
{
	while (!( UCSRA & (1<<UDRE)));            // wait while register is free
	UDR = data;                             // load data in the register
}

// function to receive data
unsigned char uart_recieve (void)
{
	while(!(UCSRA) & (1<<RXC));           // wait while data is being received
	return UDR;                             // return 8-bit data
}

// main function: entry point of program
int main (void)
{
	uart_init();                            // initialize UART                            
	
	while(1)
	{
	    uart_transmit('k');
		_delay_ms(1000);              
	}
	
	return 0;
}