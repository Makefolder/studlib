#ifndef stud_strings

#include <stdio.h>

// Let's say you've got some text with diacritics and emojis
// and you wanna have each symbol
//
// We have a program that takes a char and returns it into terminal
// input: å
// output: ?
char* str_into_utf8(char *string, size_t string_size);

#endif
