#include "quick_sort_str.h"
#include <stdio.h>
#include <assert.h>

static void swap(char **data, size_t index1, size_t index2)
{
    assert(data != NULL);

    char *tmp = *(data + index2);
    *(data + index2) = *(data + index1);
    *(data + index1) = tmp;
}

static void simpleSort(char **data, int (*compare)(const char *, const char *)) // compare two remaining elements of the array
{
    assert(data != NULL);

    if(compare(*data, *(data + 1)) > 0)
    {
        swap(data, 1, 0);
    }
}

static size_t partition(char **data, size_t data_size, int (*compare)(const char *, const char *))
{
    assert(data != NULL);

    size_t left = 0;
    size_t right = data_size - 1;
    size_t mid = data_size / 2;

    while(left < right)
    {
        while(right > mid && (compare(*(data + right), *(data + mid)) >= 0)) //getting closer to the middle from the right
        {
            right--;
        }

        while(left < mid && (compare(*(data + left), *(data + mid)) <= 0)) // getting closer to the middle from the left
        {
            left++;
        }

        // if(left == right)
        // {
        //     break; 
        // }
        
        swap(data, left, right);

        if(right == mid)
        {
            mid = left;
        }
        else if(left == mid)
        {
            mid = right;
        }

    }

    return mid;
}

int Sort(char **data, size_t data_size, int (*compare)(const char *, const char *))
{
    assert(data != NULL);
    
    size_t mid = partition(data, data_size, compare);

    if(data_size > 2)
    {
        if(mid == 0)
        {
            Sort(data + 1, data_size - 1, compare);
        }
        else if(mid == data_size - 1)
        {
            Sort(data, data_size - 1, compare);
        }
        else
        {
            Sort(data, mid, compare);
            Sort(data + mid + 1, data_size - mid - 1, compare);
        }      
    }

    if(data_size == 2)
    {
        simpleSort(data, compare);
    }
    
    return 0;
}
