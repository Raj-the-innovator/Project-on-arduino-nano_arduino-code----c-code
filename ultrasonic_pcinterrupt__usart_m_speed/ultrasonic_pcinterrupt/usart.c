/*
 * usart.c
 *
 * Created: 12/8/2017 11:56:34 AM
 *  Author: Rajesh Jat
 */ 

#include "lib.h"

#define BAUDRATE 9600
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)


void usart_init(void){
	
	UBRR0H = (uint8_t)(BAUD_PRESCALLER>>8);
	UBRR0L = (uint8_t)(BAUD_PRESCALLER);
	UCSR0B = (1<<RXEN0)|(1<<TXEN0);
	UCSR0C = (3<<UCSZ00);
}

unsigned char usart_receive(void){
	
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
	
}

void usart_send( unsigned char data){
	
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0 = data;
	
}

void usart_putstring(volatile char* StringPtr){
	
	while(*StringPtr != 0x00){
		usart_send(*StringPtr);
	StringPtr++;}
	
}