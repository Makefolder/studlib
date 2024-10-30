#ifndef LINKEDLIST_H

#define LINKEDLIST_H

#include <stddef.h>

typedef struct node_t {
  void *value;
  struct node_t *next;
} node_t;

typedef struct {
  unsigned size;
  size_t value_size;
  node_t *next;
} linkedlist_t;

// Deinit popped node
int deinit_node(node_t **node);

// Make linked list
linkedlist_t *init_linkedlist(size_t value_size);

// Destroy list and its contents
int deinit_linkedlist(linkedlist_t **const list);

// Append value to the end
int append_linkedlist(linkedlist_t *const list, void *const value);

// Insert value in the beginning
int push_linkedlist(linkedlist_t *const list, void *const value);

// Pop the first node from list
node_t *pop_linkedlist(linkedlist_t *const list);

// Pop the last node in the list
node_t *pop_end_linkedlist(linkedlist_t *const list);

#endif
