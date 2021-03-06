// pin change interrupt

#include "lib.h"

#define max_array 5
#define max_distance 500

volatile double distance[2],difference,time1;
volatile char count,final_distance[6];
volatile unsigned int timer_overflow,timer_overflow1; 

void pinchange_int(void)
{
	PCICR = (1<<PCIE2); //pin change interrupt is initialze at 6 pin
	PCMSK2 = (1<<PCINT18); // pin 6 pin change interrupt is enable 
	sei(); // global interrupt enable
}

ISR (PCINT2_vect) // isr for pin change interrupt for echo pin
{ 
 if(PIND & (1<<2))// echo get high 
 {
//	 timer1_off();
//	 time1 =(double) (TCNT1 + (timer_overflow * 65535)) * 0.0000000625;
     timer1_init();
 }

   if(!(PIND & (1<<2)))// echo get low for calculation
  {
	 timer1_off();
	 timer0_off();
	 distance[count] = (double)(TCNT1 + (timer_overflow * 65535)) * 0.001071875; // http://www.electronicwings.com/avr-atmega/ultrasonic-module-hc-sr04-interfacing-with-atmega1632
//	 time1 += (double) (TCNT1 + (timer_overflow * 65535)) * 0.0000000625;
//	 if(!count)
//	 {
//	 timer1_init();
//	 }
	 if(count)
	 {
//	 timer1_off();
//	 time1 =(double) (TCNT2 + (timer_overflow1 * 255)) * 62.5;
	 difference =(double) (distance[1] - distance[0]); // time1;  //  speed = distance /time formula to get speed
	 lcd_command(0xC0);
	 SendString("new dis:");
	 dtostrf(difference,2,1,final_distance);
	 SendString(final_distance);
	 SendString("cm/r");
	 usart_putstring(final_distance);
	 usart_putstring("  ");
	 count=0;
	 }
	 timer0_init();
	 sei();
	 count++;
	 timer_overflow=0;
     }
}