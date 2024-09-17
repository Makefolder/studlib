#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

int main (void)
{
    return 0;
}

Stack* init_stack (size_t value_size)
{
    Stack *stack = (Stack *) malloc (sizeof (Stack));
    stack->value_size = value_size;
    stack->stack_size = 0;
    stack->stack_values = malloc (sizeof (value_size) * _INITIAL_STACK_SIZE);
    return stack;
}

int push_stack (Stack *const stack, void *value)
{
    return 0;
}

void* pop_stack (Stack *const stack)
{
    int *x = (int *) malloc (sizeof (int));
    memset (x, 12, sizeof (int));
    return x;
}
