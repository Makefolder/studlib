#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

Node* init_node(const LinkedList *list, const void *value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = malloc(list->value_size);
    memcpy((void *) node->value, value, list->value_size);
    node->next = NULL;
    return node;
}

int deinit_node(Node *node)
{
    if (node == NULL)
        return -1;
    free((void *) node->value);
    free(node);
    return 0;
}

LinkedList* init_linkedlist(size_t value_size)
{
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->value_size = value_size;
    list->size = 0;
    list->next = NULL;
    return list;
}

unsigned length_linkedlist(const LinkedList *const list)
{
    if (list == NULL)
        return 0;
    return list->size;
}

int append_linkedlist(LinkedList *const list, const void *value)
{
    if (list == NULL)
        return -1;

    if (list->next == NULL)
    {
        list->next = init_node(list, value);
        list->size += 1;
        return 0;
    }
    Node *next = list->next;
    while (next->next != NULL)
        next = next->next;
    next->next = init_node(list, value);
    list->size += 1;
    return 0;
}

int deinit_linkedlist(LinkedList *const list)
{
    if (list == NULL)
        return -1;
    Node *ptr = list->next;
    while (ptr != NULL) {
        Node *next = ptr->next;
        deinit_node(ptr);
        ptr = next;
    }
    free(list);
    return 0;
}

void print_linkedlist(const LinkedList *list)
{
    if (list == NULL)
        return ;
    if (list->next == NULL)
    {
        puts("LinkedList is empty!");
        return ;
    }
    Node *next = list->next;
    while (next != NULL)
    {
        printf("size: %u, value: %d, next: %p\n", list->size, *(int *) next->value, (void *) next->next);
        next = next->next;
    }
}

int pop_linkedlist(LinkedList *const list)
{
    if (list == NULL)
        return -1;
    return 0;
}
