/*
 * mem_queue_types.h
 *
 * Created: 8/9/2024 3:53:00 PM
 *  Author: Mahmoud Hossam
 */ 


#ifndef MEM_QUEUE_TYPES_H_
#define MEM_QUEUE_TYPES_H_

#include <avr/io.h>
/*
	* A tag or metadata to utilize a shared memory as a shared queue 
	* FIFO
	* Fits for Producer-consumer for example
	=> mem_queue_ts supports up to 256 items
*/
typedef struct{
	void *begin;
	uint8_t max_size , cur_append , cur_remove , size; 
} mem_queue_ts;



#endif /* MEM_QUEUE_TYPES_H_ */