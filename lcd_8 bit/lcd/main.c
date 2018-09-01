// lcd program for display

#include "lib.h" // avr library is included 
#include "lcd_fun.h" // lcd library is included 
#include "timer_fun.h" //timer library is included

unsigned char sec,minute,hour; // initialze sec,minute and hour

int main(void)
{
   lcd_init(); //lcd is initialize
   timer_init(); //timer is initialize
   lcd_command(0x38); // lcd is initialze 8 bit mode and 16*2 rows and column
   lcd_command(0x01); // clear the screen
   lcd_command(0x80);
   SendString("     clock");
   
   while(1)  // for count icrementing and checking condition
   {
	lcd_command(0xC0); //first row is selected for ouput data
	SendString("Time ="); // time string is ouput on lcd 
	lcd_data((hour/10)%10+48); // ten place is display
	lcd_data((hour)%10+48); // unit place is display
	lcd_data(':'); //separator for time
	
	lcd_data((minute/10)%10+48); // ten place is display
	lcd_data((minute)%10+48); // unit place is display
	lcd_data(':');
	
	lcd_data((sec/10)%10+48); // ten place is display
	lcd_data((sec)%10+48); // unit place is display
	
	if(sec>=59) // sec greater than 59 then it to 0  
	{
		sec=0;
		minute++;
	}
	
	if(minute>=59) //minute greater than  59 then it to 0
	{
		sec=0;
		minute=0;
		hour++;
	}
	
	if(hour>=12) // hour greater than 12 then it to 0
	{
		sec=0;
		minute=0;
		hour=0;
	}
   }
}

