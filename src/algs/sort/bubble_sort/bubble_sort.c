#include "bubble_sort.h"

int bubble_sort(int *const arr, size_t size)
{
    for (size_t i = 0; i < size-1; i++)
    {
        int swapped = 0;
        for (size_t j = 0; j < size-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
    return 0;
}
