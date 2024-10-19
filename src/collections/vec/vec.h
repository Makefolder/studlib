#ifndef VEC_H

#define VEC_H

#include <stddef.h>

typedef struct {
  size_t size;
  size_t capacity;
  void **arr;
} vec_t;

/*todo*/
/*vec_t *init_vec(void *init_arr[]);*/
vec_t *init_vec(void);

int deinit_vec(vec_t **const vec);

// push in the end of vec
int push_vec(vec_t *vec, void *value);

// removes last element and returns it
void *pop_vec(vec_t *const vec);

// removes element by index (shifts other elements BigO(n))
void *remove_vec(vec_t *const vec, size_t index);

// reverses the order of elements in vec
int reverse_vec(const vec_t *const vec);

#endif
