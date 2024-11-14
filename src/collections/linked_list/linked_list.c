#include "linked_list.h"
#include "../../errors/studerror.h"
#include <stdlib.h>

static node_t *_init_node(void *const value) {
  node_t *node = malloc(sizeof(node_t));
  node->next = NULL;
  if (value)
    node->value = value;
  else
    node->value = NULL;
  if (!node) {
    print_error("Failed to allocate node for linked list.");
    return NULL;
  }
  return node;
}

// For internal deallocation (only internal logic of this library)
static int _deinit_node(linkedlist_t *const list, node_t *node) {
  if (!list) {
    print_error("Failed to deallocate node for linked list.");
    return -1;
  }
  if (!node) {
    print_error("Failed to deallocate node for linked list.");
    return -1;
  }

  if (node->value)
    free(node->value);

  node->value = NULL;
  if (list->next == node)
    list->next = NULL;
  free(node);

  if (list->size > 0)
    list->size -= 1;
  return 0;
}

// For external deallocation (only for users of this library)
int deinit_node(node_t **const node) {
  if (!node) {
    print_error("Failed to deinitialize node of linked list.");
    return -1;
  }
  if (!*node) {
    print_error("Failed to deinitialize node of linked list.");
    return -1;
  }
  if ((*node)->value)
    free((*node)->value);
  free(*node);
  *node = NULL;
  return 0;
}

linkedlist_t *init_linkedlist(const size_t value_size) {
  linkedlist_t *list = malloc(sizeof(linkedlist_t));
  if (!list) {
    print_error("Failed to initialize linked list.");
    return NULL;
  }
  list->value_size = value_size;
  list->size = 0;
  list->next = NULL;
  return list;
}

int deinit_linkedlist(linkedlist_t **const list) {
  if (!list) {
    print_error("Failed to deinitialize linked list.");
    return -1;
  }
  if (!*list) {
    print_error("Failed to deinitialize linked list.");
    return -1;
  }
  node_t *ptr = (*list)->next;
  while (ptr) {
    node_t *next = ptr->next;
    _deinit_node(*list, ptr);
    ptr = next;
  }
  free(*list);
  *list = NULL;
  return 0;
}

// Finds and appends to the last node in linked list
int append_linkedlist(linkedlist_t *const list, void *const value) {
  if (!list) {
    print_error("Failed to append to linked list.");
    return -1;
  }
  if (!list->next) {
    node_t *node = _init_node(value);
    if (!node)
      return -1;
    list->next = node;
    list->size++;
    return 0;
  }
  node_t *next = list->next;
  while (next->next)
    next = next->next;
  node_t *node = _init_node(value);
  if (!node) {
    print_error("Failed to initialize new node for linked list.");
    return -1;
  }
  next->next = node;
  list->size++;
  return 0;
}

// Sets head's next to newly allocated node
int push_linkedlist(linkedlist_t *const list, void *const value) {
  if (!list) {
    print_error("Failed to push into linked list.");
    return -1;
  }
  if (!value) {
    print_error("Failed to push into linked list.");
    return -1;
  }
  if (!list->next) {
    int result = append_linkedlist(list, value);
    if (result != 0) {
      print_error("Failed to push into linked list.");
      return -1;
    }
  } else {
    node_t *node = _init_node(value);
    if (!node) {
      print_error("Failed to initialize new node for linked list.");
      return -1;
    }
    node_t *temp = list->next;
    node->next = temp;
    list->next = node;
    list->size++;
  }
  return 0;
}

// Pops the first node of linked list
node_t *pop_linkedlist(linkedlist_t *const list) {
  if (!list) {
    print_error("Failed to pop from linked list.");
    return NULL;
  }
  if (!list->next) {
    print_error("Failed to pop from linked list.");
    return NULL;
  }

  node_t *node = list->next;
  if (node->next)
    list->next = node->next;
  else
    list->next = NULL;

  node->next = NULL;
  list->size--;
  return node;
}

node_t *pop_end_linkedlist(linkedlist_t *const list) {
  if (!list) {
    print_error("Failed to pop last node from linked list.");
    return NULL;
  }
  if (list->size == 0) {
    print_error("Failed to pop last node from linked list.");
    return NULL;
  }
  if (list->size == 1) {
    node_t *node = list->next;
    list->next = NULL;
    list->size--;
    return node;
  }

  node_t *previous = list->next;
  node_t *current = list->next;

  while (current->next) {
    previous = current;
    current = current->next;
  }
  previous->next = NULL;
  list->size--;
  return current;
}
