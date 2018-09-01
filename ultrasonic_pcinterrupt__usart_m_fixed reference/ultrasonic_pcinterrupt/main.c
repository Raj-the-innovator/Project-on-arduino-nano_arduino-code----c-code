#include "lib.h" // library of atmel avr is included

int main(void)
{  
   ultrasonic_init(); // ultrasonic setup
   pinchange_int();  // pin change interrupt setup
   usart_init();
   lcd_init(); //lcd is initialize
   SendString("Dist with ref-RJ");
   usart_putstring("Change in distance with reference by RJ");
   timer0_init();
   while(1)
   {     
       
  }
}

