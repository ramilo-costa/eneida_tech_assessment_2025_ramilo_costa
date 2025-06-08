
#include "ring_buffer.h"

void rb_init(RingBuffer *cb) 
{
    cb->head = 0;
    cb->tail = 0;
    cb->count = 0;
}

 

uint8_t rb_is_empty(RingBuffer *cb) 
{
    uint8_t output = 0;
    output = cb->count == 0;

    return output;
}

 

uint8_t rb_is_full(RingBuffer *cb) 
{
    uint8_t output = 0;
    output = cb->count == BUFFER_SIZE;

    return output;  
}

 

uint8_t rb_push(RingBuffer *cb, uint8_t data) 
{
    uint8_t output = 0;  

    if (rb_is_full(cb)) return output;
 
    cb->buffer[cb->head] = data;
    cb->head = (cb->head + 1) % BUFFER_SIZE;
    cb->count++;
    output = 1;

    return output;
}

 

uint8_t rb_pop(RingBuffer *cb, uint8_t *data) 
{
    uint8_t output = 0;

    if (rb_is_empty(cb)) return output; 

    *data = cb->buffer[cb->tail];
    cb->tail = (cb->tail + 1) % BUFFER_SIZE;
    cb->count--;
    output = 1;

    return output;
}

 

 

