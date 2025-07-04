#ifndef VEC_H

#define VEC_H

#include <stddef.h>

typedef struct {
  size_t size;
  size_t capacity;
  void **arr;
} vec_t;

vec_t *init_vec(void);

vec_t *init_reserve_vec(size_t capacity);

int deinit_vec(vec_t **const vec);

// push in the end of vec
int push_vec(vec_t *const vec, void *const value);

// macro that allocates value on heap, stores ptr in the vector
#define push_nvec(vec_ptr, result_ptr, value, type)                            \
  do {                                                                         \
    if (!vec_ptr) {                                                            \
      if (result_ptr) {                                                        \
        int *tmp = (int *)result_ptr;                                          \
        *tmp = -1;                                                             \
      }                                                                        \
    } else {                                                                   \
      type *ptr = malloc(sizeof(type));                                        \
      if (ptr) {                                                               \
        *ptr = value;                                                          \
        int i = push_vec(vec_ptr, ptr);                                        \
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

// removes last element and returns it
void *pop_vec(vec_t *const vec);

// removes element by index
void *remove_vec(vec_t *const vec, size_t index);

// reverses the order of elements in vec
int reverse_vec(const vec_t *const vec);

#endif
