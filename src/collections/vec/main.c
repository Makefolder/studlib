#include "vec.h"

int main(void) {
  int arr[] = {1, 2, 4};
  size_t size = sizeof(arr) * 3;
  _realloc_vec(arr, sizeof(arr), &size);
  return 0;
}
