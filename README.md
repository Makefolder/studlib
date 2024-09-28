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
- [Strings](#strings)

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
int append_linkedlist (linkedlist_t *const list, void *const value);

// Insert value in the beginning
int push_linkedlist (linkedlist_t *const list, void *const value);

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
    int *n1 = (int *) malloc (sizeof (int));
    *n1 = 24;

    int *n2 = (int *) malloc (sizeof (int));
    *n2 = 17;

    linkedlist_t *list = init_linkedlist (sizeof (int));
    if (!list)
    {
        puts ("Failed to initialize linked list.");
        return -1;
    }

    if (push_linkedlist (list, n1) != 0)
    {
        puts ("Failed to push into the list.");
        return -1;
    }
    push_linkedlist (list, n2);

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

Initial stack capacity is `sizeof (void *)` ×16. <br/>
Capacity grows/shrinks exponentially P0×e^(±2t) <br/>
Header file for Stack:

```C
#ifndef stack

#define _INITIAL_STACK_SIZE 16

typedef struct {
    size_t capacity;
    size_t size;
    // array of pointer to the values
    void **values;
} mstack_t;

mstack_t* init_stack (void);

int deinit_stack (mstack_t **stack);

// pushes an item in front of entire array (stack->values)
int push_stack (mstack_t *const stack, void *const src);

// get the first item in stack
// NOTE: don't forget to free the returned value!
void* pop_stack (mstack_t *const stack);

#endif
```

#### Example usage

```C
int main (void)
{
    int *n1 = (int *) malloc (sizeof (int));
    *n1 = 24;

    int *n2 = (int *) malloc (sizeof (int));
    *n2 = 17;

    mstack_t *stack = init_stack ();
    if (!stack)
    {
        puts ("Failed to initialize stack.");
        return -1;
    }

    int result = push_stack (stack, n1);
    if (result != 0)
    {
        puts ("Failed to push into stack.");
        deinit_stack (&stack);
        return -1;
    }

    push_stack (stack, n2);

    int *popped = (int *) pop_stack (stack);
    if (!popped)
    {
        puts ("Failed to pop.");
        deinit_stack (&stack);
        return -1;
    }
    printf ("value: %d\n", *popped);
    free (popped);

    int *popped2 = (int *) pop_stack (stack);
    printf ("value: %d\n", *popped);
    free (popped2);

    int *popped3 = (int *) pop_stack (stack);
    if (!popped3)
    {
        puts ("nothing was to pop");
        deinit_stack (&stack);
        return -1;
    }

    deinit_stack (&stack);
    return 0;
}
```

## Strings

### Supporting UTF-8 

The blessed header file for strings:

```C
#ifndef stud_strings

typedef struct {
    uint32_t *codepoints; // Array of unicode code points
    size_t length;        // length of array
} utf8arr_t;

// just regular ASCII string
// to get its length use `strlen ()`
// from `#include <strings.h>`
typedef char* string_t;

// Function to count the number of bytes in a UTF-8 character
int utf8_byte_count (char ch);

// Function to extract a UTF-8 code point from the string
uint32_t utf8_to_codepoint (const string_t str, int *char_len);

// Function to parse UTF-8 string into an array of Unicode code points
utf8arr_t parse_utf8_string (const string_t str);

// Function to free the memory allocated for codepoints
void free_utf8_arr (utf8arr_t *result);

#endif
```

#### Example usage

```C
int main (void) {
    const string_t utf8_str = "Hello, 世界! 👋"; // Sample UTF-8 encoded string
    puts (utf8_str);

    // Parse UTF-8 string
    utf8arr_t result = parse_utf8_string(utf8_str);
    
    // Iterate and print code points
    printf("Parsed %lu UTF-8 characters:\n", result.length);
    for (size_t i = 0; i < result.length; i++)
        printf("Character %lu: U+%04X\n", i + 1, result.codepoints[i]);
    free_utf8_arr (&result);

    string_t string = "My string";
    size_t str_len = strlen (string);

    puts (string);
    printf ("length of string is %lu\n", str_len);
    return 0;
}
```

## PS

If anyone uses this library, please report any bugs or memory leaks!

<div align="center">
  <a href="https://choosealicense.com/licenses/mit/">
    <b>MIT</b>
  <a/>
<div/>
