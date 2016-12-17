/*
 * GccApplication3.c
 *
 * Created: 20-08-2016 14:10:13
 *  Author: LALANDHU
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRB = 0b00000001; //Data Direction Register setting pin0 to output and the remaining pins as input
	while(1)
	{
		
		PORTB = 0b00000001;
		_delay_ms(60);
		

	}
	
}