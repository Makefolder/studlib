#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

int main(void)
{
    LinkedList *list = init_linkedlist(sizeof(int));
    int n = 248;
    int i = -42;
    append_linkedlist(list, &i);
    append_linkedlist(list, &n);
    append_linkedlist(list, &n);
    append_linkedlist(list, &n);

    print_linkedlist(list);
    Node node = pop_linkedlist(list);
    printf("node value: %d\n", *(int *) node.value);
    pop_linkedlist(list);
    pop_linkedlist(list);
    pop_linkedlist(list);

    print_linkedlist(list);
    deinit_linkedlist(list);
    return 0;
}

Node* _init_node(const LinkedList *list, const void *const value)
{
    Node *node = (Node *) malloc(sizeof(Node));
    node->value = malloc(list->value_size);
    memcpy((void *) node->value, value, list->value_size);
    node->next = NULL;
    return node;
}

int _deinit_node(LinkedList *list, Node *node)
{
    if (list == NULL || node == NULL)
        return -1;
    free((void *) node->value);
    node->value = NULL;
    if (list->next == node)
        list->next = NULL;
    free(node);
    if (list->size > 0)
        list->size -= 1;
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
        list->next = _init_node(list, value);
        list->size += 1;
        return 0;
    }
    Node *next = list->next;
    while (next->next != NULL)
        next = next->next;
    next->next = _init_node(list, value);
    list->size += 1;
    return 0;
}

int deinit_linkedlist(LinkedList *list)
{
    if (list == NULL)
        return -1;
    Node *ptr = list->next;
    while (ptr != NULL) {
        Node *next = ptr->next;
        _deinit_node(list, ptr);
        ptr = next;
    }
    free(list);
    list = NULL;
    return 0;
}

// PRINTS INTS
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
        printf("size: %u, value: %d, next: %p\n",
            list->size, *(int *) next->value, (void *) next->next);
        next = next->next;
    }
}

Node pop_linkedlist(LinkedList *const list)
{
    Node node = {
        .value = NULL,
        .next = NULL,
    };
    if (list == NULL)
        return node;
    else if (list->next == NULL)
        return node;
    if (list->next != NULL)
    {
        node.value = list->next->value;
        Node *popped = list->next;
        if (popped->next != NULL)
            list->next = popped->next;
        free(popped);
        if (list->size > 0)
            list->size -= 1;
    }
    if (list->size == 0 && list->next != NULL)
        list->next = NULL;
    return node;
}
