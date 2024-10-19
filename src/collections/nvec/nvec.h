#ifndef NVEC_H

#define NVEC_H

#include <stddef.h>

enum type_e { INT, UINT, ULONG, ULLONG, LONG, LLONG, CHAR };

typedef struct {
  size_t size;
  size_t capacity;
  void *arr;
} nvec_t;

nvec_t *init_nvec(enum type_e type);

int deinit_nvec(nvec_t **const nvec);

#endif
