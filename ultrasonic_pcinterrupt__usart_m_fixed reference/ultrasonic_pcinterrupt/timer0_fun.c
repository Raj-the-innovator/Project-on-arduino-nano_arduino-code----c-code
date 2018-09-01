
#include "lib.h"

void timer0_init(void)
{
	TCCR0B |= (1<<WGM02) | (1<<CS02) | (1<<CS00); // prescalar is set to 1024 and timer is set in ctc mode
	TCNT0 = 0; // timer count is initialize to 0
	TIMSK0 |= (1<<OCIE0A); //timer interrupt 0A is selected to turn on
	OCR0A = 250; // count compare value is assign to get delay of 35 msec
	sei(); // global interrupt enable
}

void timer0_reset(void)
{
	TCNT0=0; // count is set to 0
}

void timer0_off(void)
{
	TCNT0=0; // count is set to 0
	TCCR0B=0;
}

ISR (TIMER0_COMPA_vect)
{  
	ultrasonic_trigger(); // trigger function is call
    timer0_reset();  // count is set to 0
}