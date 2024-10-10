#include "vec.h"
#include <stdlib.h>

#define _INITIAL_CAPACITY 16

static void _realloc_vec(void *arr, size_t size, size_t *const capacity) {
  if ((*capacity / 2) > size && (*capacity / 2) >= _INITIAL_CAPACITY) {
    *capacity /= 2;
    void *tmp = realloc(arr, sizeof(void *) * *capacity);
    if (!tmp)
      puts("STUDlib: Failed to shrink vector but the value returned anyway.");
    arr = tmp;
  }
}

vec_t *init_vec(void) {
  vec_t *vec = (vec_t *)malloc(sizeof(vec_t));
  vec->size = 0;
  vec->capacity = _INITIAL_CAPACITY;
  vec->arr = malloc(sizeof(void *) * vec->capacity);
  return vec;
}

int deinit_vec(vec_t **const vec) {
  if (!vec || !*vec)
    return -1;
  for (size_t i = 0; i < (*vec)->size; i++)
    free((*vec)->arr[i]);
  free((*vec)->arr);
  free(*vec);
  *vec = NULL;
  return 0;
}

int push_vec(vec_t *vec, void *value) {
  if (!vec || !value)
    return -1;

  if (vec->size == vec->capacity - 1) {
    // todo resize logic
    vec->capacity *= 2;
    void *tmp = realloc(vec->arr, sizeof(void *) * vec->capacity);
    if (!tmp)
      return -1;
    vec->arr = tmp;
  }

  vec->arr[vec->size] = value;
  vec->size++;
  return 0;
}

void *pop_vec(vec_t *const vec) {
  if (!vec || vec->size == 0)
    return NULL;
  void *value = vec->arr[vec->size - 1];
  vec->arr[vec->size - 1] = NULL;
  vec->size--;

  _realloc_vec(vec->arr, vec->size, &vec->capacity);
  return value;
}

void *remove_vec(vec_t *const vec, size_t index) {
  if (!vec || vec->size == 0)
    return NULL;
  if (index > vec->size - 1)
    return NULL;
  void *value = vec->arr[index];
  for (size_t i = index; i < vec->size; i++) {
    int is_next = i != vec->size - 1; // indicates the last element in the array
    if (is_next == 1)
      vec->arr[i] = vec->arr[i + 1];
    else
      vec->arr[i] = NULL;
  }
  vec->size--;
  _realloc_vec(vec->arr, vec->size, &vec->capacity);
  return value;
}

int reverse_vec(const vec_t *const vec) {
  if (!vec)
    return -1;
  size_t len = vec->size;
  for (size_t i = 0; i < len / 2; i++) {
    void *tmp = vec->arr[i];
    vec->arr[i] = vec->arr[len - 1 - i];
    vec->arr[len - 1 - i] = tmp;
  }
  return 0;
}
