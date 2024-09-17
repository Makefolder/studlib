#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void print_stack (Stack *stack, size_t size)
{
    if (stack == NULL)
        return ;
    else if (stack->stack_size == 0)
    {
        puts ("Stack is empty!");
        return ;
    }
    for (size_t i = 0; i < size; i++)
        printf ("index[%zu]: %c\n", i, *(char *) stack->stack_values[i]);
}

int main (void)
{
    Stack *stack = init_stack ();

    char n = 'n';
    // char a = 'a';

    push_stack (stack, &n, sizeof (char));
    // push_stack (stack, &a, sizeof (char));
    // push_stack (stack, &n, sizeof (char));

    print_stack (stack, stack->stack_size);
    return 0;
}

Stack* init_stack (void)
{
    Stack *stack = (Stack *) malloc (sizeof (Stack));
    stack->stack_values = malloc (sizeof (void *) * _INITIAL_STACK_SIZE);
    //           size of pointer is 8 bytes ^
    stack->stack_capacity = _INITIAL_STACK_SIZE;
    stack->stack_size = 0;
    return stack;
}

// seg. fault
int push_stack (Stack *const stack, const void *const src, size_t src_size)
{
    void *value = malloc (src_size);
    // copy original source
    memcpy (value, src, src_size);

    // copy pointer to newly copied value
    memcpy (stack->stack_values[stack->stack_size], value, sizeof (void *));
    //                                    size of pointer is 8 bytes ^
    stack->stack_size++;
    return 0;
}

void* pop_stack (Stack *const stack)
{
    void *value = stack->stack_values[0];
    // memmove from index+1 -> index;
    return value;
}
