#include "linked_list.h"
#include <stdlib.h>

static node_t *_init_node(void *const value) {
  node_t *node = malloc(sizeof(node_t));
  node->next = NULL;
  if (value)
    node->value = value;
  else
    node->value = NULL;
  if (!node)
    return NULL;
  return node;
}

static int _deinit_node(linkedlist_t *const list, node_t *node) {
  if (!list)
    return -1;
  if (!node)
    return -1;

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

int deinit_node(node_t **node) {
  if (!node)
    return -1;
  if (!*node)
    return -1;
  if ((*node)->value)
    free((*node)->value);
  free(*node);
  *node = NULL;
  return 0;
}

linkedlist_t *init_linkedlist(size_t value_size) {
  linkedlist_t *list = malloc(sizeof(linkedlist_t));
  list->value_size = value_size;
  list->size = 0;
  list->next = NULL;
  return list;
}

int deinit_linkedlist(linkedlist_t **const list) {
  if (!list)
    return -1;
  if (!*list)
    return -1;
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

int append_linkedlist(linkedlist_t *const list, void *const value) {
  if (!list)
    return -1;
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
  if (!node)
    return -1;
  next->next = node;
  list->size++;
  return 0;
}

int push_linkedlist(linkedlist_t *const list, void *const value) {
  if (!list)
    return -1;
  if (!value)
    return -1;
  if (!list->next) {
    int result = append_linkedlist(list, value);
    if (result != 0)
      return result;
  } else {
    node_t *node = _init_node(value);
    if (!node)
      return -1;
    node_t *temp = list->next;
    node->next = temp;
    list->next = node;
    list->size++;
  }
  return 0;
}

node_t *pop_linkedlist(linkedlist_t *const list) {
  if (!list)
    return NULL;
  if (!list->next)
    return NULL;

  node_t *node = list->next;
  if (node->next)
    list->next = node->next;
  else
    list->next = NULL;

  node->next = NULL;
  if (list->size <= 0)
    return NULL;
  list->size--;
  return node;
}

int remove_last_linkedlist(linkedlist_t *const list) {
  if (!list)
    return -1;
  if (list->size == 0)
    return -1;
  if (list->size == 1) {
    free(list->next->value);
    free(list->next);

    list->next = NULL;
    list->size -= 1;
    return 0;
  }

  node_t *previous = list->next;
  node_t *current = list->next;

  while (current->next) {
    previous = current;
    current = current->next;
  }

  free(current->value);
  free(current);
  previous->next = NULL;
  list->size--;
  return 0;
}
