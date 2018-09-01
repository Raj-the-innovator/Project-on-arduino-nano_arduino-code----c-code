// lcd program for display

#include "lib.h" // avr library is included 
#include "lcd_fun.h" // lcd library is included 
#include "timer_fun.h" //timer library is included

unsigned char sec,minute,hour; // initialze sec,minute and hour

int main(void)
{
   lcd_init(); //lcd is initialize
 //  timer_init(); //timer is initialize
   lcd_command(0x02);  // lcd in 4 bit interfacing
   lcd_command(0x28); // lcd is initialze 8 bit mode and 16*2 rows and column
   lcd_command(0x0C);
   lcd_command(0x01); // clear the screen
   lcd_command(0x80);
   SendString("Wed");
 //  lcd_command(0xC0);
 //  SendString("  raj lab");
}

