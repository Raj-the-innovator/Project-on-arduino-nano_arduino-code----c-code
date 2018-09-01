// pin change interrupt

#include "lib.h"
#include "timer_fun.h"
#include "timer0_fun.h"

#define max_array 5
#define max_distance 500

volatile double distance;
extern volatile unsigned int timer_overflow;


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
    timer1_init();
 }

   if(!(PIND & (1<<2)))// echo get low for calculation
  {
	 timer1_off();
	 timer0_off();
	 distance = (double) (TCNT1 + (timer_overflow * 65535)) * 0.00001071875; // http://www.electronicwings.com/avr-atmega/ultrasonic-module-hc-sr04-interfacing-with-atmega1632
	 timer_overflow=0;
     }
}