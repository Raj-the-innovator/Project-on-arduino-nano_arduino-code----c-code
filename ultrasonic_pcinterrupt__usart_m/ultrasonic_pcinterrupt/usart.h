/*
 * usart.h
 *
 * Created: 12/8/2017 11:56:48 AM
 *  Author: Rajesh Jat
 */ 


#ifndef USART_H_
#define USART_H_

void usart_init(void);

unsigned char usart_receive(void);

void usart_send( unsigned char data);

void usart_putstring(char* StringPtr);

#endif /* USART_H_ */