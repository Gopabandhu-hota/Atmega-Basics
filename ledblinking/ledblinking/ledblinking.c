/*
 * ledblinking.c
 *
 * Created: 06-03-2016 00:34:56
 *  Author: LALANDHU
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{	
	DDRB |=(1<<PB1);
    while(1)
    {	
		PORTB=(1<<PB1);
		_delay_ms(500);
		PORTB=(0<<PB1);
		_delay_ms(500);
        //TODO:: Please write your application code 
    }
}