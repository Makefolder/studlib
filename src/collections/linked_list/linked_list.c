#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

Node* _init_node (const LinkedList *list, const void *const value)
{
    Node *node = (Node *) malloc (sizeof (Node));
    node->next = NULL;
    node->value = malloc (list->value_size);
    memcpy (node->value, value, list->value_size);
    return node;
}

int _deinit_node (LinkedList *const list, Node *node)
{
    _CHECK_NULL(list);
    _CHECK_NULL(node);
    free ((void *) node->value);
    node->value = NULL;
    if (list->next == node)
        list->next = NULL;
    free (node);
    if (list->size > 0)
        list->size -= 1;
    return 0;
}

LinkedList* init_linkedlist (size_t value_size)
{
    LinkedList *list = (LinkedList *) malloc (sizeof (LinkedList));
    list->value_size = value_size;
    list->size = 0;
    list->next = NULL;
    return list;
}

int deinit_linkedlist (LinkedList **const list)
{
    _CHECK_NULL(list);
    _CHECK_NULL(*list);
    Node *ptr = (*list)->next;
    while (ptr != NULL) {
        Node *next = ptr->next;
        _deinit_node (*list, ptr);
        ptr = next;
    }
    free (*list);
    *list = NULL;
    return 0;
}

int append_linkedlist (LinkedList *const list, const void *value)
{
    _CHECK_NULL(list);
    if (list->next == NULL)
    {
        list->next = _init_node (list, value);
        list->size++;
        return 0;
    }
    Node *next = list->next;
    while (next->next != NULL)
        next = next->next;
    next->next = _init_node (list, value);
    list->size++;
    return 0;
}

int insert_linkedlist (LinkedList *const list, const void *value)
{
    _CHECK_NULL(list);
    _CHECK_NULL(value);
    if (list->next == NULL)
    {
        int result = append_linkedlist (list, value);
        if (result != 0)
            return result;
    }
    else
    {
        // leak leak leak
        Node *node = _init_node (list, value);
        _CHECK_NULL(node);
        Node *temp = list->next;
        node->next = temp;
        list->next = node;
    }
    return 0;
}

Node pop_linkedlist (LinkedList *const list)
{
    Node node = {
        .value = NULL,
        .next = NULL,
    };
    if (list == NULL || list->next == NULL)
        return node;

    node.value = list->next->value;
    Node *popped = list->next;
    list->next = popped->next;

    free (popped);

    if (list->size > 0)
        list->size--;
    return node;
}

int remove_last_linkedlist (LinkedList *const list)
{
    _CHECK_NULL(list);
    if (list->size == 0)
        return -1;
    if (list->size == 1)
    {
        free (list->next->value);
        free (list->next);
        list->next = NULL;
        list->size -= 1;
        return 0;
    }
    Node *previous = list->next;
    Node *current = list->next;
    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }
    free (current->value);
    free (current);
    previous->next = NULL;
    list->size--;
    return 0;
}
