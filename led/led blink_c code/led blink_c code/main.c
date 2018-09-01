/*
 * led blink_c code.c
 *
 * Created: 11/12/2017 1:03:20 PM
 * Author : Raj_the_innovator
 */ 

#define F_CPU 8000000UL   // clock frequency of arduino nano	
#include <avr/io.h>       // input and ouput library for avr	
#include <util/delay.h>   // delay library for avr	
#define led (1<<5)        // define arduino led port B5 pin as led

int main(void)
{
    DDRB |= led;          // declare 13 pin of arduino as ouput
    while (1) 
    {
		PORTB ^= led;     // ex-or ouput pin to get blink effect
		_delay_ms(1000);  // delay is called for blink 
    }
}

// if you know c and circuit then must start with atmel studio it has best features and makes your code moore compact and efficient.