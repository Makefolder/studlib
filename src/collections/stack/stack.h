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
    size_t stack_size;
    size_t value_size;
    void *stack_values;
} Stack;

Stack* init_stack (size_t value_size);
int push_stack (Stack *const stack, void *value);
void* pop_stack (Stack *const stack);

#endif
