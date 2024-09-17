#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

Stack* init_stack (void)
{
    Stack *stack = (Stack *) malloc (sizeof (Stack));
    if (stack == NULL) return NULL;
    stack->values = malloc (sizeof (void *) * _INITIAL_STACK_SIZE);
    if (stack->values == NULL)
    {
        free (stack);
        return NULL;
    }
    stack->capacity = _INITIAL_STACK_SIZE;
    stack->size = 0;
    return stack;
}

int deinit_stack (Stack **stack)
{
    if (stack == NULL || *stack == NULL)
        return -1;
    for (size_t i = 0; i < (*stack)->size; i++)
        free ((*stack)->values[i]);
    free ((*stack)->values);
    free (*stack);
    *stack = NULL;
    return 0;
}

int push_stack (Stack *const stack, const void *const src, size_t src_size)
{
    if (stack == NULL || src == NULL) return -1;
    void *value = malloc (src_size);
    memcpy (value, src, src_size);
    if (stack->size == stack->capacity - 1)
    {
        void *temp = realloc (stack->values,
            sizeof (void *) * (stack->capacity * 2));
        if (temp == NULL) return -1;
        stack->values = temp;
        stack->capacity *= 2;
    }

    // shift from index -> index+1
    if (stack->size > 0)
        for (size_t i = stack->size; i > 0; i--)
            stack->values[i] = stack->values[i-1];
    stack->values[0] = value;
    stack->size++;
    return 0;
}

void* pop_stack (Stack *const stack)
{
    if (stack == NULL || stack->size == 0)
        return NULL;
    void *value = stack->values[0];

    // shift from index+1 -> index
    for (size_t i = 0; i < stack->size; i++)
        stack->values[i] = stack->values[i+1];
    stack->size--;
    if (stack->capacity > _INITIAL_STACK_SIZE &&
        (stack->capacity / 2) > stack->size + 1)
    {
        void *temp = realloc (stack->values,
            sizeof (void *) * (stack->capacity / 2));
        if (temp == NULL) return NULL;
        stack->values = temp;
        stack->capacity /= 2;
    }
    return value;
}
