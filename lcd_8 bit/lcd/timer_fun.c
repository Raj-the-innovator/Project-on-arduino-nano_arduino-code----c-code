/*
 * timer_fun.c
 *
 * Created: 10/16/2017 11:03:50 AM
 *  Author: Administrator
 */ 
#include "lib.h"
extern volatile unsigned char sec,minute,hour; // sec, minute and hour is declared for displaying

void timer_init(void)
{
	TCCR1B |= (1<<WGM12) | (1<<CS12) | (1<<CS10); // prescalar is set to 1024 and timer is set in ctc mode
	TCNT1 = 0; // timer count is initialize to 0
	TIMSK1 |= (1<<OCIE1A); //timer interrupt 1A is selected to turn on
	OCR1A = 15624; // count compare value is assign to get delay of 1 sec
	sei(); // global interrupt enable
}

void timer_off(void)
{
	TCCR1B =0; // turn off the timer1
}


ISR (TIMER1_COMPA_vect)
{
  sec++;	 // sec for increment after 1 sec 
}