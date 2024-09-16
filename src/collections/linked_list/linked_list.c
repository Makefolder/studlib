#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

// PRINTS INTS
void print_linkedlist (const LinkedList *list)
{
    if (list == NULL)
        return ;
    if (list->next == NULL)
    {
        puts ("LinkedList is empty!");
        return ;
    }
    Node *next = list->next;
    while (next != NULL)
    {
        // printf("value: %d, next: %p\n",
        //     *(int *) next->value, (void *) next->next);
        printf ("value: %d\n", *(int *) next->value);
        next = next->next;
    }
}

int main (void)
{
    LinkedList *list = init_linkedlist (sizeof (int));
    int x = -42;
    int y = 6;
    int z = 231;

    append_linkedlist (list, &x); // -42
    append_linkedlist (list, &y); // -42 6
    append_linkedlist (list, &z); // -42 6 231
    Node node = pop_linkedlist (list); // 6 231
    if (node.value != NULL)
        free ((void *) node.value);
    remove_last_linkedlist (list); // 6


    // LEAK LINE DO NOT CROSS LEAK LINE DO NOT CROSS LEAK LINE DO NOT CROSS

    // leak if pop used after
    // append doesn't leak even if pop is used
    insert_linkedlist (list, &x); // -42 6

    print_linkedlist(list);
    {
        // memory leak happens here
        Node node = pop_linkedlist (list); // 6
        free ((void *) node.value);
    }

    // LEAK LINE DO NOT CROSS LEAK LINE DO NOT CROSS LEAK LINE DO NOT CROSS

    deinit_linkedlist (&list);
    return 0;
}

Node* _init_node (const LinkedList *list, const void *const value)
{
    Node *node = (Node *) malloc (sizeof (Node));
    node->value = malloc (list->value_size);
    memcpy ((void *) node->value, value, list->value_size);
    node->next = NULL;
    return node;
}

int _deinit_node (LinkedList *list, Node *node)
{
    if (list == NULL || node == NULL)
        return -1;
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
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->value_size = value_size;
    list->size = 0;
    list->next = NULL;
    return list;
}

int deinit_linkedlist (LinkedList **list)
{
    if (list == NULL || *list == NULL)
        return -1;
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
    if (list == NULL)
        return -1;

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
    if (list == NULL || value == NULL)
        return -1;
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
        if (node == NULL)
            return -1;
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
        free (popped);
        if (list->size > 0)
            list->size -= 1;
    }
    if (list->size == 0 && list->next != NULL)
        list->next = NULL;
    return node;
}

int remove_last_linkedlist (LinkedList *const list)
{
    if (list == NULL || list->size == 0)
        return -1;
    if (list->size == 1)
    {
        free ((void *) list->next->value);
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
    free ((void *) current->value);
    free (current);
    previous->next = NULL;
    list->size--;
    return 0;
}
