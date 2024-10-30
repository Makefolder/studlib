#include "stack.h"
#include "../../errors/studerror.h"
#include <stdlib.h>

#define INITIAL_STACK_SIZE 16

mstack_t *init_stack(void) {
  mstack_t *stack = malloc(sizeof(mstack_t));
  if (!stack) {
    print_error("Failed to initialize stack.");
    return NULL;
  }
  stack->values = malloc(sizeof(void *) * INITIAL_STACK_SIZE);
  if (!stack->values) {
    print_error("Failed to initialize stack's inner array.");
    free(stack);
    return NULL;
  }
  stack->capacity = INITIAL_STACK_SIZE;
  stack->size = 0;
  return stack;
}

int deinit_stack(mstack_t **stack) {
  if (!stack || !*stack) {
    print_error("Failed to deinitialize stack.");
    return -1;
  }
  for (size_t i = 0; i < (*stack)->size; i++)
    free((*stack)->values[i]);
  free((*stack)->values);
  free(*stack);
  *stack = NULL;
  return 0;
}

// Appends element to the beginning (on arr[0])
int push_stack(mstack_t *const stack, void *const src) {
  if (!stack || !src) {
    print_error("Failed to push into stack.");
    return -1;
  }
  if (stack->size == stack->capacity - 1) {
    void *tmp = realloc(stack->values, sizeof(void *) * (stack->capacity * 2));
    if (!tmp) {
      print_error("Failed to extend stack.");
      return -1;
    }
    stack->values = tmp;
    stack->capacity *= 2;
  }

  if (stack->size > 0)
    for (size_t i = stack->size; i > 0; i--)
      stack->values[i] = stack->values[i - 1];

  stack->values[0] = src;
  stack->size++;
  return 0;
}

// Pops the last element in array
void *pop_stack(mstack_t *const stack) {
  if (!stack || stack->size == 0) {
    print_error("Failed to pop from stack.");
    return NULL;
  }
  void *value = stack->values[0];

  // shift from index+1 -> index
  for (size_t i = 0; i < stack->size; i++)
    stack->values[i] = stack->values[i + 1];
  stack->size--;
  if (stack->capacity > INITIAL_STACK_SIZE &&
      (stack->capacity / 2) > stack->size + 1) {
    void *temp = realloc(stack->values, sizeof(void *) * (stack->capacity / 2));
    if (!temp) {
      print_error("Failed to shrink stack's capacity.");
      return NULL;
    }
    stack->values = temp;
    stack->capacity /= 2;
  }
  return value;
}
