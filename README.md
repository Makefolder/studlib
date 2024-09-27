# studlib

<div align="left">
  <img src="https://img.shields.io/badge/std-c99-black?logo=c&logoColor=fff" />
  <img src="https://img.shields.io/badge/license-MIT-orange?logo=github&logoColor=fff" />
</div>

Simple "STD" lib for C. <br />
Basically all functions return -1 if fail and 0 if success.

### Navigation
- [Algorithms](#algorithms)
  - [Search](#searching)
    - [Linear search](#linear-search)
  - [Sorting](#sorting)
    - [Bubble sorting](#bubble-sorting)
    - [Merge sorting](#merge-sorting)
- [Collections](#collections)
  - [Linked Lists](#linked-lists)
  - [Stacks](#stacks)
- [Strings (WIP)](#strings)

## Algorithms

## Searching

### Linear sorting

Header file:

```C
// Returns index of the target in arr. If fails to find, returns -1
int linear_search (const int arr[], size_t len, int target);
```

## Sorting

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

// Deinit popped node
int deinit_node (node_t **node);

// Make linked list
linkedlist_t* init_linkedlist (size_t value_size);

// Destroy list and its contents
int deinit_linkedlist (linkedlist_t **const list);

// Append value to the end
int append_linkedlist (linkedlist_t *const list, void *value);

// Insert value in the beginning
int push_linkedlist (linkedlist_t *const list, void *value);

// Pop the first node from list 
node_t* pop_linkedlist (linkedlist_t *const list);

// Remove last node in the list
int remove_last_linkedlist (linkedlist_t *const list);

#endif
```

#### Example usage

```C
int main (void)
{
    linkedlist_t *list = init_linkedlist (sizeof (int));
    if (!list)
    {
        puts ("Failed to initialize linked list.");
        return -1;
    }

    int *n = (int *) malloc (sizeof (int));
    *n = 24;

    int *i = (int *) malloc (sizeof (int));
    *i = 17;

    if (push_linkedlist (list, n) != 0)
    {
        puts ("Failed to push into the list.");
        return -1;
    }
    push_linkedlist (list, i);

    /* first node */
    node_t *node = pop_linkedlist (list);
    if (!node)
    {
        puts ("Failed to pop.");
        return -1;
    }

    printf ("%d\n", *(int *) node->value); // 17
    deinit_node (&node);

    node_t *node2 = pop_linkedlist (list);
    deinit_node (&node2);

    /* popping node that doesn't exist */
    node_t *node3 = pop_linkedlist (list);
    int result = deinit_node (&node3);
    printf("%d\n", result); // -1

    deinit_linkedlist (&list);
    return 0;
}
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

// UTF-8 encoded char
typedef char* utf8_char;

// Let's say you've got some text with diacritics and emojis
// and you wanna have each symbol
//
// We have a program that takes a char and returns it into terminal
// input: å
// output: ?
//
// -- this is utf8_char array.
// |                  and this becomes the array's size -----.
// v                                                         v
utf8_char* str_into_utf8_arr (const string string, size_t *const size);

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
