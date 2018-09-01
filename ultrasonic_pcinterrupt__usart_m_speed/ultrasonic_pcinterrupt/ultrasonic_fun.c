// ultrasonic function;

#include "lib.h"   // avr library is added
#define trigger (1<<3) // trigger pin is set to pin 5
#define echo (1<<2) // echo pin is set to pin 6

void ultrasonic_init() 
{
	DDRD |= trigger;  // trigger is set as output
    PORTD &= ~(trigger); // trigger is set to 0
	DDRD	&= ~(echo);  // echo is set as input
	PORTD |= echo; // echo pin pullup transistor is activated
}

void ultrasonic_trigger()
{
	sei(); // global interruptis enable
	PORTD &= ~(trigger); //trigger is set to  0
	_delay_us(2);
  PORTD |=trigger;
  _delay_us(10);   // high to low signal of 10 us is given for trigger signal
  PORTD &= ~(trigger);
}