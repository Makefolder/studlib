#ifndef stud_strings

#define prints(string) printf("%s\n", string);

#include <stdio.h>

// just regular ASCII string
// to get its length use `strlen ()`
// from `#include <strings.h>`
typedef char* string;

// Unicode char
typedef char* unicode;

// string of unicode chars
typedef unicode* unicode_str;

// Let's say you've got some text with diacritics and emojis
// and you wanna have each symbol
//
// We have a program that takes a char and returns it into terminal
// input: å
// output: ?
unicode_str str_into_unicode (string *string, size_t string_size);

#endif
