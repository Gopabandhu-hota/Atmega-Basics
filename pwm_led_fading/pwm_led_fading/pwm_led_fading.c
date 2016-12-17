/*
 * pwm_led_fading.c
 *
 * Created: 07-03-2016 01:13:24
 *  Author: LALANDHU
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
int main(void)
{	
	TCCR0 |= TCCR0 | (1<<WGM01) | (1<<WGM00) | (1<<COM01) | (1<<CS02) | (1<<CS00) ;
	DDRB=0b00001000;
	PORTB=0b00001000;
    while(1)
    {	
		float i;
		i=0;
		OCR0=0;
		for(i=0;i<1.57;i=i+.2)
		{	
			OCR0=255*sin(i);
			_delay_ms(100);
		}
		for(i=1.57;i>0;i=i-.2)
		{	
			OCR0=255*sin(i);
			_delay_ms(100);
		}
		/*for(OCR0=0;OCR0<255;OCR0=OCR0+20)
		{
			_delay_ms(1000);	
		}
		for(OCR0=255;OCR0>0;OCR0=OCR0-20)
		{
			_delay_ms(1000);
		}*/			
        //TODO:: Please write your application code 
    }
}