/*
 * mem_queue.c
 *
 * Created: 8/9/2024 3:50:27 PM
 *  Author: Mahmoud Hossam
 */ 
#include "mem_queue.h"


void init_mem_queue_ts(mem_queue_ts* queue ,void* mem_ptr ,uint8_t max_size ){
	queue->begin = mem_ptr;
	queue->max_size = max_size;
	queue->cur_append = 0;
	queue->cur_remove = 0;
	queue->size = 0;
}
/*
* Pushes word (16 bit) to mem_queue type
* returns 1 if successful,0 otherwise
*/
uint8_t push_word(mem_queue_ts* queue,uint16_t word){
	if(queue->size == queue->max_size)return 0;
	
	if(queue->cur_append >= queue->max_size)queue->cur_append = 0;
	((uint16_t*)(queue->begin))[queue->cur_append] = word;
	queue->cur_append++;
	queue->size++;
	return 1;
}
/*
* fetches and removes word (16 bit) from mem_queue type and writes to a given `res`
* returns 1 if successful,0 otherwise
*/
uint8_t pop_word(mem_queue_ts* queue,uint16_t* res){
	if(queue->size == 0)return 0;
	
	if(queue->cur_remove >= queue->max_size)queue->cur_remove = 0;
	*res = ((uint16_t*)(queue->begin))[queue->cur_remove];
	queue->cur_remove++;
	queue->size--;
	return 1;
}