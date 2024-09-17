#ifndef stack

#include <stdio.h>

#define _INITIAL_STACK_SIZE 4

typedef struct {
    size_t capacity;
    size_t size;
    // array of pointer to the values
    void **values;
} Stack;

Stack* init_stack (void);
int deinit_stack (Stack **stack);

// pushes an item in front of entire array (stack_values)
// copies passed value
int push_stack (Stack *const stack, const void *const src, size_t src_size);

// get the first item in stack
// DONT FORGET TO FREE RETURNED VALUE!
void* pop_stack (Stack *const stack);

#endif
