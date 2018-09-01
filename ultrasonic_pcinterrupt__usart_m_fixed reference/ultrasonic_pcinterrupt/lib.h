// library for main

#ifndef LIB_H_
#define LIB_H_

#define F_CPU 16000000 // cpu  clock frequency
#include <avr/io.h>  //avr io library
#include <util/delay.h> //avr delay library 
#include <avr/interrupt.h> //avr interrupt library
#include "timer0_fun.h" // timer 0 is set up
#include "timer1_fun.h" // timer 1 is set up
#include "ultrasonic_fun.h" // utrasonic sensor library is included
#include "pin_change_interrupt.h" //pin change library is included
#include "lcd_fun.h"
#include "usart.h"

#endif /* LIB_H_ */