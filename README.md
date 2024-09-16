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
```
