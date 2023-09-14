#include "quick_sort.h"
#include <assert.h>

size_t partition(int *data, size_t data_size)
{
    assert(data != NULL);

    size_t right = data_size - 1;
    size_t left = 0;
    size_t mid = data_size/2;
    int is_sorted = 0;

    // printf("mid = %zu\n", mid);

    while(left <= right && is_sorted < 2)
    {
        right = data_size - 1;
        left = 0;
        mid = data_size/2;

        while((*(data + right) >= *(data + mid)) && right > mid)
        {
            right--;
        }

        while((*(data + left) <= *(data + mid)) && left < mid)
        {
            left++;
        }

        // printf("left = %zu  right = %zu\n", left, right);

        if((left < right))
        {
            int tmp = *(data + right);
            *(data + right) = *(data + left);
            *(data + left) = tmp;

            (right > mid) ? (right--) : 1;

            (left < mid) ? (left++) : 1;
    
        }

        if(left == right)
        {
            is_sorted++;
        }

        // for(size_t i = 0; i < data_size; i++)
        // {
        //     printf("%d ", data[i]);
        // }
        // printf("\ntttttttttttt mid = %zu ===============\n", right);
    }

    return mid;
}

void simpleSort(int *data)
{
    assert(data != NULL);

    if(*(data) > *(data + 1))
    {
        int tmp = *data;
        *(data) = *(data + 1);
        *(data + 1) = tmp;
    }
}

int Sort(int *data, size_t data_size)
{
    assert(data != NULL);
    
    size_t mid = partition(data, data_size);

    if(mid > 1)
    {
        Sort(data, data_size - mid);
        // puts("here");
        Sort(data + mid + 1, mid - 1);
    }

    // printf("%d %d\n", data[0], data[1]);
    simpleSort(data);

    return 0;
}

// int main()
// {
//     // int data[] = {8, 3, 2, 6, 3, 7, 4, 5};
//     // int data[] = {8, 3, 9, 10, 3, 7, 4, 5};
//     // int data[] = {1, 1, 1, 1, 1, 1, 1, 1};
//     // int data[] = {1, 2, 1, 2, 1, 2, 1, 2};
//     // int data[] = {1, 1, 1, 1, 2, 2, 2, 2};
//     int data[] = {8, 3, 2, 6, 3, 7, 4};
//     size_t data_size = sizeof(data)/sizeof(int);

//     for(size_t i = 0; i < data_size; i++)
//     {
//         printf("%d ", data[i]);
//     }
//     printf("\n-------------------------------------\n");

//     // size_t mid = partition(data, data_size);
//     // for(size_t i = 0; i < data_size; i++)
//     // {
//     //     printf("%d ", data[i]);
//     // }
//     // printf("\n------------\n");
//     // printf("mid = %zu\n", mid);

//     Sort(data, data_size);
//     for(size_t i = 0; i < data_size; i++)
//     {
//         printf("%d ", data[i]);
//     }
//     printf("\n");
    
//     return 0;
// }
