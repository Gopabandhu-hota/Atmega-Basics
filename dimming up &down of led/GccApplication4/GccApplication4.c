/*
 * GccApplication4.c
 *
 * Created: 02-12-2015 19:22:12
 *  Author: user
 */ 


#include <avr/io.h>
#include <util/delay.h>
#define F_CPU 16000000UL

int main(void)
{	
	TCCR0=TCCR0 | (1<<WGM01) | (1<<WGM00) |(0<<COM00) | (1<<COM01) | (0<<CS01) |(1<<CS00) |(1<<CS02);
	DDRB=0b11111111;
    while(1)
    {
        for(OCR0=0;OCR0<256;OCR0++)
		{
			
			_delay_ms(10);
	     }		
		 for(OCR0=256;OCR0>0;OCR0--)
	{
		
		_delay_ms(10);
	
	}	
		}
		//TODO:: Please write your application code 
		return 0;
		}		
		