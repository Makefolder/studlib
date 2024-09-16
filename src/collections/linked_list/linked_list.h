#include <stdio.h>

#ifndef linked_list

typedef struct Node
{
    const void *value;
    struct Node *next;
} Node;

typedef struct
{
    unsigned size;
    size_t value_size;
    Node* next;
} LinkedList;

Node* init_node(const LinkedList *list, const void *value);

int deinit_node(Node *node);

void print_linkedlist(const LinkedList *list);

LinkedList* init_linkedlist(size_t value_size);

unsigned length_linkedlist(const LinkedList *const list);

int append_linkedlist(LinkedList *const list, const void *value);

int insert_linkedlist(LinkedList *const list, const void *value);

int pop_linkedlist(LinkedList *const list);

int deinit_linkedlist(LinkedList *const list);

#endif
