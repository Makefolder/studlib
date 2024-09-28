#ifndef stud_strings

#include <stdint.h>
#include <stdio.h>

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
