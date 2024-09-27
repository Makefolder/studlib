#ifndef stud_strings

#define prints(string) printf("%s\n", string);

#include <stdio.h>

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
utf8_char* str_into_utf8_arr (const string string, size_t *const size);

#endif
