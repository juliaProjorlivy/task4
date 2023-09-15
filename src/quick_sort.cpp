#include <stdio.h>
#include <assert.h>

void swap(int *data, size_t index1, size_t index2)
{
    int tmp = *(data + index2);
    *(data + index2) = *(data + index1);
    *(data + index1) = tmp;
}

void simpleSort(int *data) // compare two remaining elements of the array
{
    assert(data != NULL);

    if(*(data) > *(data + 1))
    {
        swap(data, 1, 0);
    }
}

size_t partition(int *data, size_t data_size)
{
    assert(data != NULL);

    size_t left = 0;
    size_t right = data_size - 1;
    size_t mid = data_size / 2;

    while(1)
    {

        while((*(data + right) >= *(data + mid)) && right > mid) //getting closer to the middle from the right
        {
            right--;
        }

        while((*(data + left) <= *(data + mid)) && left < mid) // getting closer to the middle from the left
        {
            left++;
        }

        if(left == right)
        {
            break; 
        }
        
        swap(data, left, right);

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


int Sort(int *data, size_t data_size)
{
    size_t mid = partition(data, data_size);

    if(data_size > 2)
    {
        if(mid == 0)
        {
            Sort(data + 1, data_size - 1);
        }
        else if(mid == data_size - 1)
        {
            Sort(data, data_size - 1);
        }
        else
        {
            Sort(data, mid);
            Sort(data + mid + 1, data_size - mid - 1);
        }      
    }

    if(data_size == 2)
    {
        simpleSort(data);
    }
    
    return 0;
}

