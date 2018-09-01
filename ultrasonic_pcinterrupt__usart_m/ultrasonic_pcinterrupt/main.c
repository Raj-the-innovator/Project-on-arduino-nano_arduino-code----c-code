#include "lib.h" // library of atmel avr is included
#include "timer0_fun.h" // timer 0 is set up
#include "timer_fun.h" // timer 1 is set up
#include "ultrasonic_fun.h" // utrasonic sensor library is included
#include "pin_change_interrupt.h" //pin change library is included
#include "lcd_fun.h"
#include "usart.h"

 double distance;

int main(void)
{ 
   char final_distance[5];
   
   ultrasonic_init(); // ultrasonic setup
   pinchange_int();  // pin change interrupt setup
   timer0_init();
   usart_init();
   lcd_init(); //lcd is initialize
   SendString("Ultrasonic by RJ");
   usart_putstring("Ultrasonic by RJ");
   
   while(1)
   {     
        lcd_command(0xC0);
		SendString("Distance:");
	    dtostrf(distance,2,2,final_distance);
		SendString(final_distance);
		SendString("m  ");
		usart_putstring(final_distance);
		usart_putstring("  ");
		_delay_ms(200);
        timer0_init();
    	sei();
  }
}

