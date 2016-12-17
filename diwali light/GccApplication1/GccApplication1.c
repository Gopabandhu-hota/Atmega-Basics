/*
 * GccApplication1.c
 *
 * Created: 02-12-2015 02:19:31
 *  Author: gopabandhu
 */ 

#include<util/delay.h>
#include<avr/io.h>
#define F_CPU 16000000UL
int main(void)
{   
	int i;
	DDRB = 0b11111111;
    while(1)
    {	
		for(i=0;i<8;i++)
		{
        //TODO:: Please write your application code 
		PORTB = 0b10000000 >> i;
		_delay_ms(1000);
		}
		i=0;
	
	}
  return (0);
   
}