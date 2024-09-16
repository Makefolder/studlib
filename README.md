# matelib

Simple "STUD" lib for C. <br />
All functions return -1 if fail and 0 if success.

## Algorithms

### Bubble sorting

Note: mutates the passed array.

```C
int bubble_sort(void *const arr, size_t size);
```

## Collections

### Linked lists

Header file for LinkedList:

```C
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

// Make linked list
LinkedList* init_linkedlist(size_t value_size);

// Destroy linked list and its contents
int deinit_linkedlist(LinkedList *list);

// Get length of linked list
unsigned length_linkedlist(const LinkedList *const list);

// Append node to the end (Content gets copied into linked list)
int append_linkedlist(LinkedList *const list, const void *value);

// Insert node as first (Content gets copied into linked list)
int insert_linkedlist(LinkedList *const list, const void *value);

// Get and remove first node
Node pop_linkedlist(LinkedList *const list);

// Remove last node
int remove_linkedlist(LinkedList *const list);

#endif

```
