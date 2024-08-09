/*
 * dc_motor_control.c
 *
 * Created: 8/9/2024 7:06:05 PM
 *  Author: Mahmoud Hossam
 */ 
#include "dc_motor_control.h"

static uint8_t is_running = 0;
void init_motor(){
	is_running = 0;
}
void turn_motor_off(){
	disable_timer0_PWM();
	MOTOR_PWM_PORT &= ~(1<<MOTOR_PWM_PIN);
	is_running = 0;
}
void apply_duty_cycle(uint16_t dc){
	if(!is_running)init_timer0_PWM();
	is_running = 1;
	uint8_t timer_val=dc*255/100;
	OCR0 = timer_val;
}