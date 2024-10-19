#ifndef STACK_H

#define STACK_H

#include <stddef.h>

typedef struct {
  size_t capacity;
  size_t size;
  // array of pointer to the values
  void **values;
} mstack_t;

mstack_t *init_stack(void);

int deinit_stack(mstack_t **stack);

// pushes an item in front of entire array (stack->values)
int push_stack(mstack_t *const stack, void *const src);

// get the first item in stack
// NOTE: don't forget to free the returned value!
void *pop_stack(mstack_t *const stack);

#endif
