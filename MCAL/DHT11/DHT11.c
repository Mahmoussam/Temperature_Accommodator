/*
 * DHT11.c
 *
 * Created: 8/9/2024 12:49:25 AM
 *  Author: Mahmoud Hossam
 */ 

#include "DHT11.h"

/** static functions definitions **/
/* Microcontroller send start pulse/request */
static void request(volatile DHT11_t *dht)				
{
	volatile uint8_t *reg_ptr = resolve_DD_port(dht->gpio_port);
	if(reg_ptr == NULL)return;
	*reg_ptr |= (1<<dht->sensor_pin);
	
	reg_ptr = resolve_PORT_port(dht->gpio_port);
	if(reg_ptr == NULL)return;
	
	*reg_ptr &= ~(1<<dht->sensor_pin);	/* set to low pin */
	_delay_ms(20);			/* wait for 20ms */
	*reg_ptr |= (1<<dht->sensor_pin);	/* set to high pin */
}

/* receive response from DHT11 */
static void response(volatile DHT11_t *dht)				
{
	volatile uint8_t *reg_ptr = resolve_DD_port(dht->gpio_port);
	if(reg_ptr == NULL)return;
	
	*reg_ptr &= ~(1<<dht->sensor_pin);
	
	reg_ptr = resolve_PIN_port(dht->gpio_port);
	
	while(*reg_ptr & (1<<dht->sensor_pin));
	while((*reg_ptr & (1<<dht->sensor_pin))==0);
	while(*reg_ptr & (1<<dht->sensor_pin));
	
}
static uint8_t receive_byte(volatile DHT11_t *dht){			/* receive data */
	volatile uint8_t *reg_ptr = resolve_PIN_port(dht->gpio_port);
	uint8_t byte = 0;
	for (uint8_t q=0; q<8; q++)
	{
		while(((*reg_ptr) & (1<<dht->sensor_pin)) == 0);  /* check received bit 0 or 1 */
		_delay_us(30);
		if((*reg_ptr) & (1<<dht->sensor_pin))/* if high pulse is greater than 30ms */
			byte = (byte<<1)|(0x01);	/* then its logic HIGH */
		else			/* otherwise its logic LOW */
			byte = (byte<<1);
		while((*reg_ptr) & (1<<dht->sensor_pin));
	}
	return byte;
}
/* Initializes the necessary data and pins for given DHT11_t object
	returns 1 for successful operation
		0 for failure
*/
void init_dht11_t(volatile DHT11_t* dht,GPIO_PORT port,uint8_t pin){
	dht->sensor_pin = pin;
	dht->gpio_port = port;
	
	//set that pin to high
	volatile uint8_t *reg_ptr = resolve_DD_port(dht->gpio_port);
	if(reg_ptr == 0)return;
	*reg_ptr |= (1<<pin);
	reg_ptr = resolve_PORT_port(dht->gpio_port);
	if(reg_ptr == 0)return;
	*reg_ptr |= (1<<pin);
	//initialize all to 0
	dht->frac_RH = dht->frac_Temp = dht->integer_RH = dht->integer_Temp =0;
	_delay_ms(20);
}

/* updating the data of a DHT11_t object from sensor
	returns 1 for successful operation
		0 for failure
*/
uint8_t update_dht11_t(volatile DHT11_t* dht){
	uint8_t CheckSum;
	request(dht);
	response(dht);
	dht->integer_RH = receive_byte(dht);	/* store first eight bit in integer part for humidity RH */
	dht->frac_RH = receive_byte(dht);	/* store next eight bit in fraction RH part */
	dht->integer_Temp = receive_byte(dht);	
	dht->frac_Temp = receive_byte(dht);
	CheckSum=receive_byte(dht);/* store next eight bit in CheckSum */
	
	if(dht->integer_RH + dht->frac_RH + dht->integer_Temp + dht->frac_Temp != CheckSum)return 0;
	
	return 1;
}
