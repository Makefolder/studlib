#ifndef vec

#include <stdio.h>

#define _INITIAL_CAPACITY 16

typedef struct {
    size_t size;
    size_t capacity;
    void **arr;
} vec_t;

vec_t *init_vec (void);

int deinit_vec (vec_t **const vec);

// push in the end of vec
int push_vec (vec_t *vec, void *value);

// removes last element and returns it
void* pop_vec (vec_t *const vec);

// removes element by index (shifts other elements BigO(n))
void* remove_vec (vec_t *const vec, size_t index);

// reverses the order of elements in vec
int reverse_vec (const vec_t *const vec);

void _realloc_vec (void *arr, size_t size, size_t *const capacity);

#endif
