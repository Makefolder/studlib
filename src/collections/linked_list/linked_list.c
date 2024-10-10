#include "linked_list.h"
#include <stdlib.h>

#define _CHECK_NULL(ptr)                                                       \
  do {                                                                         \
    if (!(ptr))                                                                \
      return -1;                                                               \
  } while (0)

#define _CHECK_NULL_RETURN(ptr, type)                                          \
  do {                                                                         \
    if (!(ptr))                                                                \
      return type;                                                             \
  } while (0)

static node_t *_init_node(void *const value) {
  node_t *node = (node_t *)malloc(sizeof(node_t));
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
  _CHECK_NULL(list);
  _CHECK_NULL(node);
  if (node->value != NULL)
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
  _CHECK_NULL(node);
  _CHECK_NULL(*node);
  if ((*node)->value != NULL)
    free((*node)->value);
  free(*node);
  *node = NULL;
  return 0;
}

linkedlist_t *init_linkedlist(size_t value_size) {
  linkedlist_t *list = (linkedlist_t *)malloc(sizeof(linkedlist_t));
  list->value_size = value_size;
  list->size = 0;
  list->next = NULL;
  return list;
}

int deinit_linkedlist(linkedlist_t **const list) {
  _CHECK_NULL(list);
  _CHECK_NULL(*list);
  node_t *ptr = (*list)->next;
  while (ptr != NULL) {
    node_t *next = ptr->next;
    _deinit_node(*list, ptr);
    ptr = next;
  }
  free(*list);
  *list = NULL;
  return 0;
}

int append_linkedlist(linkedlist_t *const list, void *const value) {
  _CHECK_NULL(list);
  if (list->next == NULL) {
    node_t *node = _init_node(value);
    if (!node)
      return -1;
    list->next = node;
    list->size++;
    return 0;
  }
  node_t *next = list->next;
  while (next->next != NULL)
    next = next->next;
  node_t *node = _init_node(value);
  if (!node)
    return -1;
  next->next = node;
  list->size++;
  return 0;
}

int push_linkedlist(linkedlist_t *const list, void *const value) {
  _CHECK_NULL(list);
  _CHECK_NULL(value);
  if (list->next == NULL) {
    int result = append_linkedlist(list, value);
    if (result != 0)
      return result;
  } else {
    // leak leak leak
    node_t *node = _init_node(value);
    if (!node)
      return -1;
    _CHECK_NULL(node);
    node_t *temp = list->next;
    node->next = temp;
    list->next = node;
    list->size++;
  }
  return 0;
}

node_t *pop_linkedlist(linkedlist_t *const list) {
  _CHECK_NULL_RETURN(list, NULL);
  _CHECK_NULL_RETURN(list->next, NULL);

  node_t *node = list->next;
  if (node->next != NULL)
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
  _CHECK_NULL(list);
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
  while (current->next != NULL) {
    previous = current;
    current = current->next;
  }
  free(current->value);
  free(current);
  previous->next = NULL;
  list->size--;
  return 0;
}
