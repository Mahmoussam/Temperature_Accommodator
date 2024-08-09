/*
 * extended_gpio.c
 *
 * Created: 8/9/2024 12:55:30 AM
 *  Author: Mahmoud Hossam
 */ 

#include "extended_gpio.h"

/************************************************************************/
/* Interfaces Implementations                                           */
/************************************************************************/
/*
* returns the address of the DD register for a given port
*/
volatile uint8_t* resolve_DD_port(GPIO_PORT port){
	switch(port){
		case A_PORT:
		return &DDRA;
		break;
		case B_PORT:
		return &DDRB;
		break;
		case C_PORT:
		return &DDRC;
		break;
		case D_PORT:
		return &DDRD;
		break;
		default:
		break;
	}
	return NULL;
}
/*
* returns the address of the PORT register for a given port
*/
volatile uint8_t* resolve_PORT_port(GPIO_PORT port){
	switch(port){
		case A_PORT:
		return &PORTA;
		break;
		case B_PORT:
		return &PORTB;
		break;
		case C_PORT:
		return &PORTC;
		break;
		case D_PORT:
		return &PORTD;
		break;
		default:
		break;
	}
	return NULL;
}
/*
* returns the address of the PIN register for a given port
*/
volatile uint8_t* resolve_PIN_port(GPIO_PORT port){
	switch(port){
		case A_PORT:
		return &PINA;
		break;
		case B_PORT:
		return &PINB;
		break;
		case C_PORT:
		return &PINC;
		break;
		case D_PORT:
		return &PIND;
		break;
		default:
		break;
	}
	return NULL;
}