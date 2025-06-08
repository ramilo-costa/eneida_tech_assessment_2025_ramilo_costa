# Where is the Bug?

## A- Is the code below compilable using standard ‘gcc‘?

#include <stdint.h>
#include <stdio.h>
int main(void) {
uint8_t i;
for (i = 250; i <= 1050; i++) {
printf("i=%d\n", i);
}
return 0;
}

### Yes, it is possible to compile it despite the error if compile flag -Werror is not in use

## B- Identify the bug(s) in the code snippet and explain them
### The for counts up to 1050 which overflows the data type size. 
### The variable i is an unsigned 8 which means it only has 256 bits.
### The i count will be 255 top and then will return to 0 making this an infinite loop
### To fix it change the variable length to uint16_t ou int16_t

### Check main.c for solution