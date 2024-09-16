#ifndef linked_list

#include <stdio.h>

#define _CHECK_NULL(ptr) do { if ((ptr) == NULL) return -1; } while(0)

typedef struct Node
{
    void *value;
    struct Node *next;
} Node;

typedef struct
{
    unsigned size;
    size_t value_size;
    Node* next;
} LinkedList;

// Not for external usage (at least I didn't mean that)
Node* _init_node(const LinkedList *list, const void *const value);

// Not for external usage (at least I didn't mean that)
int _deinit_node(LinkedList *const list, Node *node);

// Make linked list
LinkedList* init_linkedlist(size_t value_size);

// Destroy linked list and its contents
int deinit_linkedlist(LinkedList **const list);

// Append node to the end (Content gets copied into linked list)
int append_linkedlist(LinkedList *const list, const void *value);

// Insert node as first (Content gets copied into linked list)
int insert_linkedlist(LinkedList *const list, const void *value);

// Get and remove first node
Node pop_linkedlist(LinkedList *const list);

// Remove last node in linked list
int remove_last_linkedlist(LinkedList *const list);

#endif
