#include "hashmap.h"
#include "../../../src/errors/studerror.h"
#include <stdlib.h>
#include <string.h>

static hashmap_node_t *hashmap_node_create(void *const key, void *const value) {
  if (!key || !value)
    return NULL;

  hashmap_node_t *node = (hashmap_node_t *)malloc(sizeof(hashmap_node_t));
  node->key = key;
  node->value = value;
  node->next = NULL;
  return node;
}

// Default hash func for string keys
unsigned int hash_string(void *key) {
  char *str = (char *)key;
  unsigned hash = 0;
  while (*str)
    hash = hash * 31 + *str++;
  return hash;
}

// Default cmp func for string keys
int compare_strings(void *key1, void *key2) {
  return strcmp((char *)key1, (char *)key2);
}

hashmap_t *init_hashmap(const size_t capacity,
                        unsigned int (*hash_func)(void *key),
                        int (*key_cmp_func)(void *key1, void *key2)) {
  if (!key_cmp_func || !hash_func) {
    print_error("Failed to initialize hashmap (invalid function pointers).");
    return NULL;
  }

  hashmap_t *map = (hashmap_t *)malloc(sizeof(hashmap_t));
  if (!map) {
    print_error("Failed to initialize hashmap.");
    return NULL;
  }
  map->buckets = (hashmap_node_t **)calloc(capacity, sizeof(hashmap_node_t *));
  if (!map->buckets) {
    free(map);
    print_error("Failed to initialize hashmap.");
    return NULL;
  }
  map->size = capacity;
  map->hash_func = hash_func;
  map->key_cmp_func = key_cmp_func;
  return map;
}

int push_hashmap(hashmap_t *const map, void *const key, void *const value) {
  if (!map || !key || !value) {
    print_error("Failed to push into hashmap.");
    return -1;
  }

  unsigned int index = map->hash_func(key) % map->size;
  hashmap_node_t *node = hashmap_node_create(key, value);
  if (!node) {
    print_error("Failed to push into hashmap (node initialization failed).");
    return -1;
  }
  hashmap_node_t *current = map->buckets[index];

  while (current) {
    if (map->key_cmp_func(current->key, key) == 0) {
      current->value = value; // Update value if key matches
      free(node);             // Free the newly created node
      return 0;
    }
    current = current->next;
  }

  node->next = map->buckets[index];
  map->buckets[index] = node;
  return 0;
}

void *get_hashmap(hashmap_t *const map, void *const key) {
  if (!map || !key) {
    print_error("Failed to get value by key.");
    return NULL;
  }

  unsigned int index = map->hash_func(key) % map->size;
  hashmap_node_t *current = map->buckets[index];

  while (current) {
    if (map->key_cmp_func(current->key, key) == 0) {
      return current->value;
    }
    current = current->next;
  }
  print_error("Failed to get value by key (key not found).");
  return NULL;
}

int remove_hashmap(hashmap_t *const map, void *const key) {
  if (!map || !key) {
    print_error("Failed to remove from hashmap.");
    return -1;
  }

  unsigned int index = map->hash_func(key) % map->size;
  hashmap_node_t *current = map->buckets[index];
  hashmap_node_t *prev = NULL;

  while (current) {
    if (map->key_cmp_func(current->key, key) == 0) {
      if (prev) {
        prev->next = current->next;
      } else {
        map->buckets[index] = current->next;
      }
      free(current); // Free the node
      return 0;
    }
    prev = current;
    current = current->next;
  }
  return 0;
}

int deinit_hashmap(hashmap_t **const map) {
  if (!map || !*map) {
    print_error("Failed deinitialize hashmap.");
    return -1;
  }
  for (size_t i = 0; i < (*map)->size; ++i) {
    hashmap_node_t *current = (*map)->buckets[i];
    while (current) {
      hashmap_node_t *temp = current;
      current = current->next;
      free(temp);
    }
  }
  free((*map)->buckets);
  free(*map);
  *map = NULL;
  return 0;
}
