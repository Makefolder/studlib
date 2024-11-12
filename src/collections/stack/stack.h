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
int push_stack(mstack_t *const stack, void *const value);

// macro that allocates value on heap, stores ptr in the stack
#define push_nstack(stack_ptr, result_ptr, value, type)                        \
  do {                                                                         \
    if (!stack_ptr) {                                                          \
      if (result_ptr) {                                                        \
        int *tmp = (int *)result_ptr;                                          \
        *tmp = -1;                                                             \
      }                                                                        \
    } else {                                                                   \
      type *ptr = malloc(sizeof(type));                                        \
      if (ptr) {                                                               \
        *ptr = value;                                                          \
        int i = push_stack(stack_ptr, ptr);                                    \
        if (result_ptr) {                                                      \
          int *tmp = (int *)result_ptr;                                        \
          *tmp = i;                                                            \
        }                                                                      \
      } else {                                                                 \
        if (result_ptr) {                                                      \
          int *tmp = (int *)result_ptr;                                        \
          *tmp = -1;                                                           \
        }                                                                      \
      }                                                                        \
    }                                                                          \
  } while (0)

// get the first item in stack
// NOTE: don't forget to free the returned value!
void *pop_stack(mstack_t *const stack);

#endif
