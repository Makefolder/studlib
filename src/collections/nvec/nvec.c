#include "nvec.h"
#include "../../errors/studerror.h"
#include <stdlib.h>

#define INITIAL_NVEC_CAPACITY 16

/*int main(void) {*/
/*  enum type_e type = INT;*/
/*  nvec_t *nvec = init_nvec(type);*/
/*  deinit_nvec(&nvec);*/
/*  return 0;*/
/*}*/

nvec_t *init_nvec(enum type_e type) {
  nvec_t *nvec = malloc(sizeof(nvec_t));
  if (!nvec) {
    print_error("Failed to initialize natural vector.");
    return NULL;
  }
  nvec->size = 0;
  nvec->capacity = INITIAL_NVEC_CAPACITY;

  // alloc initial array for `nvec`
  switch (type) {
  case INT:
    nvec->arr = malloc(sizeof(int) * nvec->capacity);
    if (!nvec->arr) {
      print_error("Failed to initialize natural vector (int).");
      return NULL;
    }
    break;
  case UINT:
    nvec->arr = malloc(sizeof(unsigned) * nvec->capacity);
    if (!nvec->arr) {
      print_error("Failed to initialize natural vector (unsigned).");
      return NULL;
    }
    break;
  case ULONG:
    nvec->arr = malloc(sizeof(unsigned long) * nvec->capacity);
    if (!nvec->arr) {
      print_error("Failed to initialize natural vector (unsigned long).");
      return NULL;
    }
    break;
  case ULLONG:
    nvec->arr = malloc(sizeof(unsigned long long) * nvec->capacity);
    if (!nvec->arr) {
      print_error("Failed to initialize natural vector (unsigned long long).");
      return NULL;
    }
    break;
  case LONG:
    nvec->arr = malloc(sizeof(long) * nvec->capacity);
    if (!nvec->arr) {
      print_error("Failed to initialize natural vector (long).");
      return NULL;
    }
    break;
  case LLONG:
    nvec->arr = malloc(sizeof(long long) * nvec->capacity);
    if (!nvec->arr) {
      print_error("Failed to initialize natural vector (long long).");
      return NULL;
    }
    break;
  case CHAR:
    nvec->arr = malloc(sizeof(char) * nvec->capacity);
    if (!nvec->arr) {
      print_error("Failed to initialize natural vector (char).");
      return NULL;
    }
    break;
  default:
    return NULL;
  }

  return nvec;
}

int deinit_nvec(nvec_t **const nvec) {
  if (!nvec || !*nvec) {
    print_error("Failed to deinitialize natural vector.");
    return -1;
  }
  free((*nvec)->arr);
  free(*nvec);
  *nvec = NULL;
  return 0;
}
