#include "vec.h"
#include "../../../src/errors/studerror.h"
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_VEC_CAPACITY 16

// Used only to shrink vector's inner array
static void realloc_vec(void *arr, size_t size, size_t *const capacity) {
  if ((*capacity / 2) > size && (*capacity / 2) >= INITIAL_VEC_CAPACITY) {
    *capacity /= 2;
    void *tmp = realloc(arr, sizeof(void *) * *capacity);
    if (!tmp)
      print_error("Failed to shrink vector's capacity.");
    else
      arr = tmp;
  }
}

vec_t *init_vec(void) {
  vec_t *vec = malloc(sizeof(vec_t));
  if (!vec) {
    print_error("Failed to initialize vector.");
    return NULL;
  }
  vec->size = 0;
  vec->capacity = INITIAL_VEC_CAPACITY;
  vec->arr = malloc(sizeof(void *) * vec->capacity);
  if (!vec->arr) {
    print_error("Failed to initialize vector's internal array.");
    free(vec);
    return NULL;
  }
  return vec;
}

int deinit_vec(vec_t **const vec) {
  if (!vec || !*vec) {
    print_error("Failed to deinitialize vector.");
    return -1;
  }
  for (size_t i = 0; i < (*vec)->size; i++)
    free((*vec)->arr[i]);
  free((*vec)->arr);
  free(*vec);
  *vec = NULL;
  return 0;
}

// Appends element to the end
int push_vec(vec_t *vec, void *const value) {
  if (!vec || !value) {
    print_error("Failed to push into vector.");
    return -1;
  }

  if (vec->size == vec->capacity - 1) {
    vec->capacity *= 2;
    void *tmp = realloc(vec->arr, sizeof(void *) * vec->capacity);
    if (!tmp) {
      print_error("Failed to extend vector.");
      vec->capacity /= 2;
      return -1;
    }
    vec->arr = tmp;
  }

  vec->arr[vec->size] = value;
  vec->size++;
  return 0;
}

// Pops the last element from vector
void *pop_vec(vec_t *const vec) {
  if (!vec || vec->size == 0) {
    print_error("Failed to pop from vector.");
    return NULL;
  }
  void *value = vec->arr[vec->size - 1];
  vec->arr[vec->size - 1] = NULL;
  vec->size--;

  realloc_vec(vec->arr, vec->size, &vec->capacity);
  return value;
}

void *remove_vec(vec_t *const vec, size_t index) {
  if (!vec || vec->size == 0) {
    print_error("Failed to remove element from vector.");
    return NULL;
  }
  if (index > vec->size - 1) {
    print_error("Failed to remove element by index (index is bigger than "
                "vector size).");
    return NULL;
  }
  void *value = vec->arr[index];
  for (size_t i = index; i < vec->size; i++) {
    int is_next = i != vec->size - 1; // indicates the last element in the array
    if (is_next == 1)
      vec->arr[i] = vec->arr[i + 1];
    else
      vec->arr[i] = NULL;
  }
  vec->size--;
  realloc_vec(vec->arr, vec->size, &vec->capacity);
  return value;
}

int reverse_vec(const vec_t *const vec) {
  if (!vec) {
    print_error("Failed to reverse vector.");
    return -1;
  }
  size_t len = vec->size;
  for (size_t i = 0; i < len / 2; i++) {
    void *tmp = vec->arr[i];
    vec->arr[i] = vec->arr[len - 1 - i];
    vec->arr[len - 1 - i] = tmp;
  }
  return 0;
}
