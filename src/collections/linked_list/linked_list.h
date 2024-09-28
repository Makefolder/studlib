#ifndef linked_list

#include <stdio.h>

#define _CHECK_NULL(ptr) \
    do { \
        if (!(ptr)) return -1; \
    } while (0)

#define _CHECK_NULL_RETURN(ptr, type) \
    do { \
        if (!(ptr)) return type; \
    } while (0)

typedef struct node_t
{
    void *value;
    struct node_t *next;
} node_t;

typedef struct
{
    unsigned size;
    size_t value_size;
    node_t* next;
} linkedlist_t;

// Not for external usage (at least I didn't mean that)
node_t* _init_node (void *const value);

// Not for external usage (at least I didn't mean that)
int _deinit_node (linkedlist_t *const list, node_t *node);

// Deinit popped node
int deinit_node (node_t **node);

// Make linked list
linkedlist_t* init_linkedlist (size_t value_size);

// Destroy list and its contents
int deinit_linkedlist (linkedlist_t **const list);

// Append value to the end
int append_linkedlist (linkedlist_t *const list, void *const value);

// Insert value in the beginning
int push_linkedlist (linkedlist_t *const list, void *const value);

// Pop the first node from list 
node_t* pop_linkedlist (linkedlist_t *const list);

// Remove last node in the list
int remove_last_linkedlist (linkedlist_t *const list);

#endif
