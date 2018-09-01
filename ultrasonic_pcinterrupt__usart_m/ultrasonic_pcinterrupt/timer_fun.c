//timer function

#include "lib.h"
volatile unsigned char timer_overflow; 

void timer1_init(void)
{
	TCCR1B |=(1<<CS10); // prescalar is set to 1024 and timer is set in ctc mode
	TCNT1 = 0; // timer count is initialize to 0
	TIMSK1 |= (1<<TOIE1);
}

void timer1_off(void)
{
	TCCR1B =0;
}

void timer1_reset(void)
{
	TCNT1=0; // count is set to 0
}

ISR(TIMER1_OVF_vect)
{
	timer_overflow++;
	TCNT1=0;
}