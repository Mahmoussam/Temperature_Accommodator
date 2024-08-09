/*
 * uart.c
 *
 * Created: 8/8/2024 9:22:28 PM
 * Author : Mahmoud Hossam
 */ 
#include "uart.h"

/************************************************************************/
/* Implementations                                                      */
/************************************************************************/
/*
*	TRX_mask : enable/disable transmission => bit 0
*			enable/disable  Reception =>bit 1
*/
void init_uart(unsigned int baud_rate,unsigned char TRX_mask){
	uint16_t BAUD_PRESCALE = F_CPU/16/baud_rate - 1;
	UCSRA = 0;
	UCSRB = 0;
	if(TRX_mask & 1)
		UCSRB |= (1<<TXEN);
	if(TRX_mask & 2)
		UCSRB |= (1<<RXEN);
	
	UCSRC |= (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit char size + 1 stop bit*/
	UBRRL = BAUD_PRESCALE;
	UBRRH = (BAUD_PRESCALE >> 8);		
}
void uart_send_byte(unsigned char byte){
	// Wait for empty transmit buffer 
	while ( !( UCSRA & (1<<UDRE)) );
	UDR = byte;
}
void uart_send_string(char * s_ptr){
	while(s_ptr && *s_ptr != '\0'){
		uart_send_byte(*s_ptr);
		s_ptr++;
	}
	
}
void uart_send_dec_string(uint8_t byte,uint8_t sz){
	char data[sz];
	itoa(byte,data,10);
	uart_send_string(data);
}
