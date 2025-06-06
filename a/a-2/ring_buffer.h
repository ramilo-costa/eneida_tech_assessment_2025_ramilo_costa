#include <stdint.h>


#define BUFFER_SIZE 128


typedef struct {

    uint8_t buffer[BUFFER_SIZE];
    uint8_t head;  
    uint8_t tail;  
    uint8_t count; // Number of elements in the buffer

} RingBuffer;

 

void rb_init(RingBuffer *cb);

uint8_t rb_is_empty(RingBuffer *cb);

uint8_t rb_is_full(RingBuffer *cb);

uint8_t rb_push(RingBuffer *cb, uint8_t data);

uint8_t rb_pop(RingBuffer *cb, uint8_t *data);

 

 
