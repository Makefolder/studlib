#include <stdio.h>
#include "linear_search.h"

int linear_search (const int arr[], size_t len, int target)
{
    for (size_t i = 0; i < len; i++)
        if (arr[i] == target)
            return i;
    return -1;
}
