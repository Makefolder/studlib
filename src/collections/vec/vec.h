#ifndef vec

#include <stdio.h>

#define _INITIAL_CAPACITY 16

typedef struct {
    size_t size;
    size_t capacity;
    void **arr;
} vec_t;

vec_t* init_vec (void);
int deinit_vec (vec_t **vec);

int push_vec (vec_t *vec, void *value, size_t size);

#endif
