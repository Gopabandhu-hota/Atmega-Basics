/*
 * adc.c
 *
 * Created: 06-03-2016 01:11:23
 *  Author: LALANDHU
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
//below there are two adc functions ,,1st for ADLAR=1,2nd for ADLAR=0,,put the unused function in comments
int main(void)
{		
	//when ADLAR=1,adc operation is 8 bit,only ADCH is read,then data gets lost,,ADCL is not read
	 ADMUX = (1<<REFS0) | (1<<ADLAR); //MUX0=MUX1=MUX2=0-ADC INPUT AT PIN0
	 ADCSRA = (1<<ADEN) |(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);// ADC Enable and prescaler of 128// 16000000/128 = 125000
	 unsigned int adc_value; // Variable to hold ADC result
	 DDRB=0xff; // Set Port B as Output
	 PORTB = 0x00;//INITIALISE to LED off at portB
    while(1)
    {	
		ADCSRA |= (1<<ADSC); // Start conversion
         while(ADCSRA & 1<<ADSC);//wait for  conversion to complete
		 adc_value=ADCH;//operation becomes 8 bit mode
		 
		 if(adc_value>0 && adc_value<32)
		 {
			 PORTB=0b10000000;
		 }
		 if(adc_value>32 && adc_value<64)
		 {
			 PORTB=0b01000000;
		 }
		 if(adc_value>64 && adc_value<96)
		 {
			 PORTB=0b00100000;
		 }
		 if(adc_value>96 && adc_value<128)
		 {
			 PORTB=0b00010000;
		 }
		 if(adc_value>128 && adc_value<160)
		 {
			 PORTB=0b00001000;
		 }
		 if(adc_value>160 && adc_value<192)
		 {
			 PORTB=0b00000100;
		 }
		 if(adc_value>192 && adc_value<224)
		 {
			 PORTB=0b00000010;
		 }
		 if(adc_value>224 && adc_value<256 )
		 {
			 PORTB=0b00000001;
		 }	 
		 
    }
}
int main(void)
{	
	//when ADLAR=0,first ADCL read,,then ADCH,and ADCH is shifted 8 bit left
	unsigned int adc_value; // Variable to hold ADC result
	DDRB=0xff; // Set Port D as Output
	PORTB = 0x00;
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);//or ADCSRA |= ADCSRA |(1<<ADEN) | (1<<ADPS2) | (1<<ADPS0)
	// ADEN: Set to turn on ADC , by default it is turned off
	//ADPS2: ADPS2 and ADPS0 set to make division factor 32
	ADMUX=0b01000000; // ADC input channel set to PA),,ADLAR=0;
	while (1)
	{
		ADCSRA |= (1<<ADSC); // Start conversion
		while (ADCSRA & (1<<ADSC)); // wait for conversion to complete
		ADC |= ( ADCH<<8 | ADCL); //Store ADC value//or else direct adc_value =ADC can also be written
		adc_value=ADC;//operation becomes 10 bit mode
		if(adc_value>0 && adc_value<128)
		{
			PORTB=0b10000000;
		}
		if(adc_value>128 && adc_value<256)
		{0
			PORTB=0b01000000;
		}
		if(adc_value>256 && adc_value<384)
		{
			PORTB=0b00100000;
		}
		if(adc_value>384 && adc_value<512)
		{
			PORTB=0b00010000;
		}
		if(adc_value>512 && adc_value<640)
		{
			PORTB=0b00001000;
		}
		if(adc_value>640 && adc_value<768)
		{
			PORTB=0b00000100;
		}
		if(adc_value>768 && adc_value<896)
		{
			PORTB=0b00000010;
		}
		if(adc_value>896 && adc_value<1024 )
		{
			PORTB=0b00000001;
		}
		
		
	}
}