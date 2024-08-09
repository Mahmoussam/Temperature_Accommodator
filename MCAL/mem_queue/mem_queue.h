/*
 * mem_queue.h
 *
 * Created: 8/9/2024 3:50:16 PM
 *  Author: Mahmoud Hossam
 */ 


#ifndef MEM_QUEUE_H_
#define MEM_QUEUE_H_

#include "mem_queue_types.h"
#include "Locks.h"

/* Functions Declarations */
void init_mem_queue_ts(mem_queue_ts* queue ,void* mem_ptr ,uint8_t max_size );
uint8_t push_word(mem_queue_ts* queue,uint16_t word);
uint8_t pop_word(mem_queue_ts* queue,uint16_t* res);
#endif /* MEM_QUEUE_H_ */