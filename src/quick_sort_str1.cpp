#include "quick_sort_str.h"
#include <assert.h>

void swap(void *data1, size_t index1, size_t index2, size_t el_size) // swaps two pointers
{
    char *data = (char *)data1;
    char tmp = *(data + index2*el_size);
    *(data + index2*el_size) = *(data + index1*el_size);
    *(data + index1*el_size) = tmp;
}


static void simpleSort(void *data1, size_t el_size, int (*compare)(const void *, const void *)) // compare two remaining elements of the array
{
    assert(data1 != NULL);

    char *data = (char *)data1;

    if(compare((const void *)(data), (const void *)(data + el_size)) > 0)
    {
        swap(data1, 1, 0, el_size);
    }
}

static size_t partition(void *data1, size_t data_size, size_t el_size, int (*compare)(const void *, const void *))
{
    char *data = (char *)data1;
    char **data2 = (char **)data;
    size_t left = 0;
    size_t right = data_size - 1;
    size_t mid = data_size / 2;

    while(1)
    {
        while(right > mid && (compare((const void *)(data + right*el_size), (const void *)(data + mid*el_size)) >= 0)) //getting closer to the middle from the right
        {
            right--;
        }

        while(left < mid && (compare((const void *)(data + left*el_size), (const void *)(data + mid*el_size)) <= 0)) // getting closer to the middle from the left
        {
            left++;
        }
        printf("left = %zu, right = %zu\n", left, right);
        if(left == right)
        {
            break; 
        }
        printf("l1 = %s, l2 = %s\n", data2[left], data2[right]);
        swap(data1, left, right, el_size);

        if(right == mid)
        {
            mid = left;
        }
        else if(left == mid)
        {
            left = right;
            mid = left;
        }

    }

    return mid;
}


int Sort(void *data1, size_t data_size, size_t el_size, int (*compare)(const void *, const void *))
{
    char *data = (char *)data1;
    char **data2 = (char **)data1;
    printf("data1 = %s, data_size = %zu, el_szie = %zu\n" , data2[0], data_size, el_size);

    size_t mid = partition(data1, data_size, el_size, compare);
    // size_t mid = data_size/2;

    if(data_size > 2)
    {
        
        if(mid == 0)
        {
            Sort((void *)(data + 1*el_size), data_size - 1, el_size, compare);
        }
        else if(mid == data_size - 1)
        {
            Sort((void *)data, data_size - 1, el_size, compare);
        }
        else
        {
            Sort((void *)data, mid, el_size, compare);
            Sort((void *)(data + (mid + 1)*el_size), data_size - mid - 1, el_size, compare);
        }      

    }

    if(data_size == 2)
    {
        simpleSort((void *)data, el_size, compare);
    }
    
    return 0;
}

