/*
 * DHT11_types.h
 *
 * Created: 8/9/2024 1:21:15 AM
 *  Author: Mahmoud Hossam
 */ 


#ifndef DHT11_TYPES_H_
#define DHT11_TYPES_H_

/******************************
Types, structures , enums ...
*******************************/
typedef struct{
	uint8_t integer_RH,
	frac_RH,
	integer_Temp,
	frac_Temp,
	sensor_pin;
	GPIO_PORT gpio_port;
}DHT11_t;



#endif /* DHT11_TYPES_H_ */