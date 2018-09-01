#include "lib.h" // library of atmel avr is included

volatile double distance[2],difference,time1;
volatile char final_distance[6];

int main(void)
{  
   ultrasonic_init(); // ultrasonic setup
   pinchange_int();  // pin change interrupt setup
   usart_init();
   lcd_init(); //lcd is initialize
   SendString(" speed m/s - RJ");
   usart_putstring("speed m/s by RJ");
   timer0_init();
   while(1)
   {     
       lcd_command(0xC0);
       SendString("speed:");
       dtostrf(difference,2,1,final_distance);
       SendString(final_distance);
       SendString("m/s  ");
       dtostrf(distance[0],2,2,final_distance);
       usart_putstring(final_distance);
       usart_putstring("  ");
       dtostrf(distance[1],2,2,final_distance);
       usart_putstring(final_distance);
       usart_putstring("  ");
       dtostrf(distance[2],2,2,final_distance);
       usart_putstring(final_distance);
       usart_putstring("  ");
       dtostrf(time1,2,2,final_distance);
       usart_putstring(final_distance);
       usart_putstring("  ");
       dtostrf(difference,2,2,final_distance);
       usart_putstring(final_distance);
       usart_putstring("  "); 
	   _delay_ms(200);
  }
}

