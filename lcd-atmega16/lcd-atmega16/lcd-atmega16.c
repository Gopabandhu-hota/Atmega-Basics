#include<avr/io.h>
#include<util/delay.h>
#define F_CPU 16000000UL
#define lcd_port   PORTB //LCD connected to PORTB as shown above
#define LCD_RS     0×01
#define LCD_RW     0×02
#define LCD_EN     0×08

void lcd_reset(void)
{
	lcd_port = 0xFF;
	_delay_ms(20);
	lcd_port = 0×30+LCD_EN;
	lcd_port = 0×30;
	_delay_ms(10);
	lcd_port = 0×30+LCD_EN;
	lcd_port = 0×30;
	_delay_ms(1);
	lcd_port = 0×30+LCD_EN;
	lcd_port = 0×30;
	_delay_ms(1);
	lcd_port = 0×20+LCD_EN;
	lcd_port = 0×20;
	_delay_ms(1);
}


void lcd_cmd (char cmd)
{
	lcd_port = (cmd & 0xF0)|LCD_EN;
	lcd_port = (cmd & 0xF0);
	lcd_port = ((cmd << 4) & 0xF0)|LCD_EN;
	lcd_port = ((cmd << 4) & 0xF0);
	_delay_ms(2);
	_delay_ms(2);
}


void lcd_init (void)
{
	lcd_reset();       
	                 
	lcd_cmd(0×0C);      
	lcd_cmd(0×06);       
	lcd_cmd(0×80);       
}


// Function to display single Character
void lcd_data (unsigned char dat)
{
	lcd_port = ((dat & 0xF0)|LCD_EN|LCD_RS);
	lcd_port = ((dat & 0xF0)|LCD_RS);
	lcd_port = (((dat << 4) & 0xF0)|LCD_EN|LCD_RS);
	lcd_port = (((dat << 4) & 0xF0)|LCD_RS);
	_delay_ms(2);
	_delay_ms(2);
}


// Function to display a String
void lcd_puts(char *a)
{
	unsigned int i;
	for(i=0;a[i]!=0;i++)
	lcd_data(a[i]);
}



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
