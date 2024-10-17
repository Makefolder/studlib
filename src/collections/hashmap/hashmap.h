#ifndef hashmap

#include <stdio.h>

typedef struct {
  size_t size;
  size_t capacity;
  void **arr;
} hashmap_t;

hashmap_t *init_hashmap(void);

int deinit_hashmap(hashmap_t **hashmap);

int push_hashmap(hashmap_t *hashmap, void *data);

/* todo */

#endif
