/*
 * naive_configs.h
 *
 * Created: 8/8/2024 9:55:54 PM
 *  Author: Mahmoud Hossam
 */ 


#ifndef NAIVE_CONFIGS_H_
#define NAIVE_CONFIGS_H_

#define F_CPU 8000000UL
// producer consumer queue size
#define PROD_CONS_Q_SIZE 5
// Timer 1 
#define TCNT1_VAL 64755 

// DHT11 sensor
#define DHT11_PIN 0
#define DHT11_PORT A_PORT

// PWM pin
#define MOTOR_PWM_PIN 3
#define MOTOR_PWM_DDR DDRB 
#define MOTOR_PWM_PORT PORTB 
#endif /* NAIVE_CONFIGS_H_ */