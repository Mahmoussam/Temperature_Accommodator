/*
 * timers.h
 *
 * Created: 8/9/2024 2:56:27 PM
 *  Author: Mahmoud Hossam
 */ 


#ifndef TIMERS_H_
#define TIMERS_H_

#include "../naive_configs.h"
#include<avr/interrupt.h>

#ifndef TCNT1_VAL
#error TCNT1_VAL must be defined in order to set interrupt every period
#endif

void init_timer1_interrupt(void);
void init_timer0_PWM(void);
void disable_timer0_PWM(void);
#endif /* TIMERS_H_ */