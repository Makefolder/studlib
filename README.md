# studlib

<div align="left">
  <img src="https://img.shields.io/badge/std-c99-black?logo=c&logoColor=fff" />
  <img src="https://img.shields.io/badge/license-MIT-orange?logo=github&logoColor=fff" />
</div>

Simple "STD" lib for C. <br />
Basically all functions return -1 if fail and 0 if success.

### Navigation
- [Algorithms](#algorithms)
  - [Bubble sorting](#bubble-sorting)
  - [Merge sorting](#merge-sorting)
- [Collections](#collections)
  - [Linked Lists](#linked-lists)
  - [Stacks](#stacks)
- [Strings (WIP)](#strings)

## Algorithms

### Bubble sorting

Note: mutates the passed array.

```C
int bubble_sort(int *const arr, size_t size);
```

### Merge sorting

Usage:

```C
int main (void)
{
    int arr[] = {10, 2, 5, 1, 0, 2, 5, 10, 2, 5, 1, 0, 45, 45, 821, 1, 9, 51, 6, 8};
    size_t len = sizeof (arr) / sizeof (arr[0]);

    merge_sort(arr, 0, len - 1); // arr[] gets sorted
    ...
    return 0;
}
```

Header file:

```C
void merge_sort(int arr[], int l, int r);
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
int push_linkedlist (LinkedList *const list, const void *value);

// Remove last node in linked list
int remove_last_linkedlist (LinkedList *const list);

// Get and remove first node
Node* pop_linkedlist (LinkedList *const list);

// Deinit popped node
int deinit_node (Node **node);

#endif
```

### Stacks

Initial stack capacity is `sizeof (void *)` * 32.
Header file for Stack:

```C
#ifndef stack

typedef struct {
    size_t stack_capacity;
    size_t stack_size;
    void **stack_values; // array of values
} Stack;

Stack* init_stack (void);

// pushes an item in front of entire array (stack_values)
// copies passed value
int push_stack (Stack *const stack, const void *const src, size_t src_size);

// get the first item in stack
void* pop_stack (Stack *const stack);

#endif
```

## Strings

### WORK IN PROCESS! THIS IS ONLY NOTED IDEA!

### Supporting unicode

The blessed header file for strings:

```C
#ifndef stud_strings

#define prints(string) printf("%s\n", string);

// just regular ASCII string
// to get its length use `strlen ()`
// from `#include <strings.h>`
typedef char* string;

// Unicode char
typedef char* unicode;

// string of unicode chars
typedef unicode* unicode_str;

// We have a program that takes a char and returns it into terminal
// input: å
// output: ?
//
// in the standart C, `char` supports only ASCII.
unicode_str str_into_unicode (string *string, size_t string_size);

#endif
```

### But how to use it?

TODO EXAMPLES OF ITS USAGE

## PS

If anyone uses this library, please report any bugs or memory leaks.

<div align="center">
  <a href="https://choosealicense.com/licenses/mit/">
    <b>MIT</b>
  <a/>
<div/>
