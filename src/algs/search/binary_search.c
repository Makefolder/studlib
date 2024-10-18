#include "./binary_seach.h"

int binary_search(const int arr[], int low, int high, int target) {
  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
      return mid;

    if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }

  return -1;
}
