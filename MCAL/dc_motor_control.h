/*
 * dc_motor_control.h
 *
 * Created: 8/9/2024 7:06:19 PM
 *  Author: Mahmoud Hossam
 */ 
#ifndef DC_MOTOR_CONTROL_H_
#define DC_MOTOR_CONTROL_H_

#include "timers.h"

void init_motor();
void turn_motor_off();
void apply_duty_cycle(uint16_t dc);
#endif