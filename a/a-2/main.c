
#include <stdio.h>
#include <stdint.h>
#include "ring_buffer.h"

int main() {

    RingBuffer cb;
    uint8_t const TEST_LIM = 10;
    uint8_t value;

    // start
    rb_init(&cb);

 

    // adding data 
    for (uint8_t i = 0; i < TEST_LIM; i++) {
        if (rb_push(&cb, i)) {
            printf("Pushed: %d\n", i);
        } else {
            printf("Buffer full, could not push: %d\n", i);
        }
    }

 

    // clear data
    while (!rb_is_empty(&cb)) {
        if (rb_pop(&cb, &value)) {
            printf("Popped: %d\n", value);
        }
    }


    return 0;

}