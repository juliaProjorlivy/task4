#include "quick_sort_str.h"
#include <assert.h>

static void swap(void *data1, size_t index1, size_t index2, size_t el_size) // swaps two pointers
{
    assert(data1 != NULL);

    char *data = (char *)data1;
    char tmp = *(data + index2*el_size);
    *(data + index2*el_size) = *(data + index1*el_size);
    *(data + index1*el_size) = tmp;
}


static void simpleSort(void *data1, size_t el_size, int (*compare)(const void *, const void *)) // compare two remaining elements of the array
{
    assert(data1 != NULL);

    char *data = (char *)data1;

    if(compare((data), (data + el_size)) > 0)
    {
        swap(data1, 1, 0, el_size);
    }
}

static size_t partition(void *data1, size_t data_size, size_t el_size, int (*compare)(const void *, const void *))
{
    assert(data1 != NULL);

    char *data = (char *)data1;

    size_t left = 0;
    size_t right = data_size - 1;
    size_t mid = data_size / 2;

    while(left < right)
    {
        while(right > mid && (compare((data + right*el_size), (data + mid*el_size)) >= 0)) //getting closer to the middle from the right
        {
            right--;
        }

        while(left < mid && (compare((data + left*el_size), (data + mid*el_size)) <= 0)) // getting closer to the middle from the left
        {
            left++;
        }
        
        swap(data1, left, right, el_size);

        if(right == mid)
        {
            mid = left;
        }
        else if(left == mid)
        {
            mid = left;
        }

    }

    return mid;
}


int Sort2(void *data1, size_t data_size, size_t el_size, int (*compare)(const void *, const void *))
{
    assert(data1 != NULL);

    char *data = (char *)data1;

    size_t mid = partition(data1, data_size, el_size, compare);

    if(data_size > 2)
    {
        
        if(mid == 0)
        {
            Sort2((void *)(data + 1*el_size), data_size - 1, el_size, compare);
        }
        else if(mid == data_size - 1)
        {
            Sort2((void *)data, data_size - 1, el_size, compare);
        }
        else
        {
            Sort2((void *)data, mid, el_size, compare);
            Sort2((void *)(data + (mid + 1)*el_size), data_size - mid - 1, el_size, compare);
        }      

    }

    if(data_size == 2)
    {
        simpleSort((void *)data, el_size, compare);
    }
    
    return 0;
}

