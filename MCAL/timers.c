/*
 * timers.c
 *
 * Created: 8/9/2024 2:56:09 PM
 *  Author: Mahmoud Hossam
 */ 
#include "timers.h"

void init_timer1_interrupt(void){
	TCNT1 = TCNT1_VAL;   // for 1 sec at 16 MHz

	TCCR1A = 0x00;
	TCCR1B = (1<<CS10) | (1<<CS12);;  // Timer mode with 1024 prescaler
	TIMSK = (1 << TOIE1) ;   // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}

void init_timer0_PWM(void){
	//Set pin to output
	MOTOR_PWM_DDR |= (1<<MOTOR_PWM_PIN);
	//set timer0
	// Fast non inverted PWM 
	TCCR0 =(1<<COM01)|(1<<WGM01)|(1<<WGM00);
	TCCR0 |=(1<<CS00)|(1<<CS02);//1024 as prescaler to obtain cycle with 16 ms width
}
void disable_timer0_PWM(void){
	TCCR0 = 0;
}