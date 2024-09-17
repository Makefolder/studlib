#ifndef stack

#include <stdio.h>

#define _INITIAL_STACK_SIZE 32

// FILO - First IN Last OUT
// GTA V <- pop
// GTA IV <- then
// Skyrim <- then
// Minecraft <- first
//
typedef struct {
    size_t stack_capacity;
    size_t stack_size;
    void **stack_values; // array of values
} Stack;

Stack* init_stack (void);

// pushes an item in front of entire array (stack_values)
// copies passed value
int push_stack (Stack *const stack, const void *const src, size_t src_size);

// get the first item in stack
void* pop_stack (Stack *const stack);

#endif
