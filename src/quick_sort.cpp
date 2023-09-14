#include <stdio.h>
#include <assert.h>

void swap(int *data, size_t index1, size_t index2)
{
    int tmp = *(data + index2);
    *(data + index2) = *(data + index1);
    *(data + index1) = tmp;
}

size_t partition(int *data, size_t data_size) // sorts numbers relative to the middle
{
    assert(data != NULL);

    size_t right = data_size - 1;
    size_t left = 0;
    size_t mid = data_size/2;

    while(1)
    {
        right = data_size - 1;
        left = 0;
        mid = data_size/2;

        while((*(data + right) >= *(data + mid)) && right > mid) //getting closer to the middle from the right
        {
            right--;
        }

        while((*(data + left) <= *(data + mid)) && left < mid) // getting closer to the middle from the left
        {
            left++;
        }

        if(left == mid && right == mid) // checks if an arrya is already sorted
        {
            break;
        }

        swap(data, left, right);

        if(right > mid) right--;
        if(left < mid) left++;
    
    }

    return mid;
}

void simpleSort(int *data) // compare two remaining elements of the array
{
    assert(data != NULL);

    if(*(data) > *(data + 1))
    {
        swap(data, 1, 0);
    }
}

int Sort(int *data, size_t data_size)
{
    assert(data != NULL);

    size_t mid = partition(data, data_size);

    if(data_size > 5)
    {
        Sort(data, mid);
        Sort(data + mid + 1, mid - (1 - (data_size % 2))); 
    }

    simpleSort(data);
    simpleSort(data + (data_size%2) + 2);

    return 0;
}

