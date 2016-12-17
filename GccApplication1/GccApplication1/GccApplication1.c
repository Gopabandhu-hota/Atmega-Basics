#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#define F_CPU 16000000UL
int main(void)
{
	lcd_init();
	lcd_cmd(0x01); // Clear screen
	lcd_cmd(0x80);  // Initially at first line
	lcd_puts("electroons.com");
	lcd_cmd(0xc0);  // Command to goto second line
	lcd_puts("LCD 4 Bit");
	while(1==1); // loop forever
	return 0;
}