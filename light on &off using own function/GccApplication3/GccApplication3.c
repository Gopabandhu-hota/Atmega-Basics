/*
 * GccApplication3.c
 *
 * Created: 02-12-2015 16:20:27
 *  Author: user
 */ 


#include <avr/io.h>
#include<util/delay.h>
void delay(int x)
{	
	int N;
	N=1;
	N=(16000/1024);
	N=N*x;
	N=N/256;
	TCNT0=0;
	int count=0;
	while(1)
	{
		if(TCNT0==255)
	{
		count++;
		TCNT0=0;
	}
	if(count>=N)
		return;
	
	
	}			
}
int main(void)
{	
	DDRB=0b11111111;
	TCCR0=TCCR0 | (1<<CS00) |(0<<CS01) | (1<<CS02);
	
    while(1)
    {	
		PORTB=0b11111111;
		delay(1000);
		PORTB=0b00000000;
		delay(1000);
        //TODO:: Please write your application code 
    };
}