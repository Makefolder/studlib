#include <stdio.h>

typedef struct Node
{
    const void *value;
    struct Node *next;
} Node;

typedef struct
{
    size_t value_size;
    Node* next;
} LinkedList;

Node* init_node(const LinkedList *list, const void *value);

int deinit_node(Node *node);

void print_linkedlist(const LinkedList *list);

LinkedList* init_linkedlist(size_t value_size);

int append_linkedlist(LinkedList *const list, const void *value);

int insert_linkedlist(LinkedList *const list, const void *value);

int pop_linkedlist(LinkedList *const list);

int deinit_linkedlist(LinkedList *const list);
