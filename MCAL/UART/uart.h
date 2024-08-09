/*
 * uart.h
 *
 * Created: 8/8/2024 9:22:43 PM
 * Author : Mahmoud Hossam
 */ 


#ifndef UART_H_
#define UART_H_

/* Includes */
#include <stdlib.h>
#include <avr/io.h>
#include "../../naive_configs.h"

/* Declarations */
void init_uart(unsigned int,unsigned char);
void uart_send_byte(unsigned char);	
void uart_send_string(char*);
void uart_send_dec_string(uint8_t,uint8_t);

#endif /* UART_H_ */