/*
 * Temperature_Accomodator.c
 *
 * Created: 8/8/2024 6:11:59 PM
 * Author : Mahmoud Hossam
 */ 


#include "naive_configs.h"
#include <avr/io.h>
#include <util/delay.h>
#include "MCAL/UART/uart.h"
#include "MCAL/DHT11/DHT11.h"
#include "MCAL/timers.h"
#include "MCAL/dc_motor_control.h"
/* Global/volatile variables/objects definitions */

volatile DHT11_t dht;

/*
volatile Lock lock;
volatile mem_queue_ts queue_tag_temp,queue_tag_humid;
volatile uint16_t queue_mem_temp[PROD_CONS_Q_SIZE],queue_mem_humid[PROD_CONS_Q_SIZE];
*/

/* Functions Declarations */
void _init_all__(void);
void tcnt1_val_repeater_function(void);
/* ISRs */
ISR (TIMER1_OVF_vect)    // Timer1 ISR
{
	TCNT1 = TCNT1_VAL;   // for 100 m sec at 8 MHz
	tcnt1_val_repeater_function();
}

int main(void)
{	
	_init_all__();
	
	uart_send_string("Serial ready!\r\n");
	

    while(1)
    {
		
	}
}

void _init_all__(){
	/*
	lock_init(&lock);
	init_mem_queue_ts(queue_tag_temp,queue_mem_temp,PROD_CONS_Q_SIZE);
	init_mem_queue_ts(queue_tag_humid,queue_mem_humid,PROD_CONS_Q_SIZE);
	*/
	init_motor();
	
	init_uart(9600 , 1);
	
	init_timer1_interrupt();
	
	init_dht11_t(&dht ,DHT11_PORT ,DHT11_PIN);
	
}
void tcnt1_val_repeater_function(){
	/*
		Each (100ms) call read and react to temp
		Each 2(200ms) calls read humid..
		using dht11 we get both instantly. However, receiver is interested in humid every 200 ms only.   
	*/
	
	static uint8_t cnt = 0;
	cnt = !cnt;
	//get dht data
	if(!update_dht11_t(&dht))
		//failed..
		return;
	//push temp to consumer,we r inside the producer
	// we don't need to acquire the lock anyway here..
	uart_send_string("Temp : ");
	uart_send_dec_string(dht.integer_Temp,5);
	uart_send_byte('.');
	uart_send_dec_string(dht.frac_Temp,5);
	uart_send_string(" C # ");
	if(!cnt){
		uart_send_string("Humid : ");
		uart_send_dec_string(dht.integer_RH,5);
		uart_send_byte('.');
		uart_send_dec_string(dht.frac_RH,5);
		uart_send_string(" %");
	}
	if(dht.integer_Temp > 25){
		uint16_t perdif = (dht.integer_Temp - 25)*100 / 25;
		apply_duty_cycle(perdif);
	}
	else{
		turn_motor_off();	
	}
	uart_send_string("\n\r");
}