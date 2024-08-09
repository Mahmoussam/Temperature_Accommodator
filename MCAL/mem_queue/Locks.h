/*
 * Locks.h
 *
 * Created: 8/9/2024 4:20:50 PM
 *  Author: Mahmoud Hossam
 */ 


#ifndef LOCKS_H_
#define LOCKS_H_

#include <avr/io.h>

/* Types */
typedef struct {
	volatile uint8_t flag[2];
	volatile uint8_t turn;
} Lock;


/* functions declaration*/
void lock_init(Lock *lock);
void lock_acquire(Lock *lock, int process_id);
void lock_release(Lock *lock, int process_id);
uint8_t is_lock_acquired_by_other(Lock *lock, int process_id);




#endif /* LOCKS_H_ */