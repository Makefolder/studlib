#ifndef STRING_H

#define STRING_H

#include <stddef.h>

typedef char *str_t;

typedef struct {
  size_t len;
  size_t capacity;
  char *value;
} string_t;

string_t *init_string();
int deinit_string(string_t *str);

int append_string(string_t *str, char *src);
int clean_string(string_t *str);

#endif
