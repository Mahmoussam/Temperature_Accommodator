/*
 * Locks.c
 *
 * Created: 8/9/2024 4:21:04 PM
 *  Author: Mahmoud Hossam
 */ 
#include "Locks.h"


void lock_init(Lock *lock) {
	lock->flag[0] = 0;
	lock->flag[1] = 0;
	lock->turn = 0;
}

void lock_acquire(Lock *lock, int process_id) {
	lock->flag[process_id] = 1;
	lock->turn = 1 - process_id;
	while (lock->flag[1 - process_id] == 1 && lock->turn == 1 - process_id)
	;
}
uint8_t is_lock_acquired_by_other(Lock *lock, int process_id) {
	return lock->flag[1 - process_id] && lock->turn == (1 - process_id);
}
void lock_release(Lock *lock, int process_id) {
	lock->flag[process_id] = 0;
}
