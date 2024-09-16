# matelib

<div align="left">
  <img src="https://img.shields.io/badge/std-c99-black?logo=c&logoColor=fff" />
  <img src="https://img.shields.io/badge/license-MIT-orange?logo=github&logoColor=fff" />
</div>

Simple "STUD" lib for C. <br />
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
    const void *value;
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
int _deinit_node(LinkedList *list, Node *node);

// Make linked list
LinkedList* init_linkedlist(size_t value_size);

// Destroy linked list and its contents
int deinit_linkedlist(LinkedList **list);

// Append node to the end (Content gets copied into linked list)
int append_linkedlist(LinkedList *const list, const void *value);

// Insert node as first (Content gets copied into linked list)
int insert_linkedlist(LinkedList *const list, const void *value);

// Get and remove first node
// NOTE: DONT FORGET TO `free (value)` OF RECEIVED NODE!
Node pop_linkedlist(LinkedList *const list);

// Remove last node in linked list
int remove_last_linkedlist(LinkedList *const list);

#endif
```
