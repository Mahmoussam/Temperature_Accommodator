/*
 * extended_gpio.h
 *
 * Created: 8/9/2024 12:55:40 AM
 *  Author: Mahmoud Hossam
 */ 


#ifndef EXTENDED_GPIO_H_
#define EXTENDED_GPIO_H_

#include <avr/io.h>
#include <stddef.h>
#include "extended_gpio_types.h"

#define IO_PORT_SIZE 8

/**************************
Declarations
***************************/
volatile uint8_t* resolve_DD_port(GPIO_PORT);
volatile uint8_t* resolve_PORT_port(GPIO_PORT);
volatile uint8_t* resolve_PIN_port(GPIO_PORT);


#endif /* EXTENDED_GPIO_H_ */