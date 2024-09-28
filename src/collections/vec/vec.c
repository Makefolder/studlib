#include <stdlib.h>
#include "vec.h"

int main (void)
{
    vec_t *vec = init_vec ();
    return 0;
}

vec_t* init_vec (void)
{
    vec_t *vec = (vec_t *) malloc (sizeof (vec_t));
    vec->size = 0;
    vec->capacity = _INITIAL_CAPACITY;
    vec->arr = malloc (sizeof (void *) * vec->capacity);
    return vec;
}

int deinit_vec (vec_t **vec)
{
    if (!vec || !*vec) return -1;

    for (size_t i = 0; i < (*vec)->size; i++)
        free ((*vec)->arr[i]);
    free (*vec);
    *vec = NULL;
    return 0;
}

int push_vec (vec_t *vec, void *value, size_t size)
{
    return 0;
}

