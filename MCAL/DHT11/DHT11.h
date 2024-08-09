/*
 * DHT11.h
 *
 * Created: 8/9/2024 12:49:14 AM
 *  Author: Mahmoud Hossam
 */ 


#ifndef DHT11_H_
#define DHT11_H_

/** Necessary includes **/
#include "../../naive_configs.h"
#include <util/delay.h>
#include "../extended_interfaces/extended_gpio.h"
#include "DHT11_types.h"

/******************************
# Functions Definitions
*******************************/
void init_dht11_t(volatile DHT11_t* ,GPIO_PORT ,uint8_t);
uint8_t update_dht11_t(volatile DHT11_t*);


#endif /* DHT11_H_ */