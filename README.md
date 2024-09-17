# studlib

<div align="left">
  <img src="https://img.shields.io/badge/std-c99-black?logo=c&logoColor=fff" />
  <img src="https://img.shields.io/badge/license-MIT-orange?logo=github&logoColor=fff" />
</div>

Simple "STD" lib for C. <br />
All functions return -1 if fail and 0 if success.

## Algorithms

### Bubble sorting

Note: mutates the passed array.

```C
int bubble_sort(int *const arr, size_t size);
```

## Collections

### Linked lists

Header file for LinkedList:

```C
#ifndef linked_list

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

// Make linked list
LinkedList* init_linkedlist (size_t value_size);

// Destroy linked list and its contents
int deinit_linkedlist (LinkedList **const list);

// Append node to the end (Content gets copied into linked list)
int append_linkedlist (LinkedList *const list, const void *value);

// Insert node as first (Content gets copied into linked list)
int insert_linkedlist (LinkedList *const list, const void *value);

// Remove last node in linked list
int remove_last_linkedlist (LinkedList *const list);

// Get and remove first node
Node* pop_linkedlist (LinkedList *const list);

// Deinit popped node
int deinit_node (Node *node);

#endif
```
