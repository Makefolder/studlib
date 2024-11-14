#ifndef HASHMAP_H

#define HASHMAP_H

#include <stdio.h>

typedef struct hashmap_node {
  void *key;
  void *value;
  struct hashmap_node *next;
} hashmap_node_t;

typedef struct {
  hashmap_node_t **buckets;
  size_t size;
  // pointers to functions
  unsigned (*hash_func)(void *key);
  int (*key_cmp_func)(void *key1, void *key2);
} hashmap_t;

// Default functions
// Use these or implement your own

#ifndef HASHMAP_FUNCS

#define HASHMAP_FUNCS

int compare_strings(void *key1, void *key2);

unsigned int hash_string(void *key);

#endif

// END

hashmap_t *init_hashmap(const size_t capacity,
                        unsigned int (*hash_func)(void *key),
                        int (*key_cmp_func)(void *key1, void *key2));

int deinit_hashmap(hashmap_t **const map);

int push_hashmap(hashmap_t *const map, void *const key, void *const value);

void *get_hashmap(hashmap_t *const map, void *const key);

int remove_hashmap(hashmap_t *const map, void *const key);

#endif
