#include "make_ptr_array.h"
#include "string_compare.h"
#include "myerror.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>




int main()
{
    const size_t max_str_count = 100;
    char *data = get_data_from_file("data.txt"); // free data !!!!!
    char **ptr_data = (char **)calloc(sizeof(char*), max_str_count);
    size_t str_count = make_ptr_array(data, ptr_data); //number of string (does not include an emply lines and does not count the last empty string)
    printf("%zu\n", str_count);
    printf("%s\n", *(ptr_data  + 11));
    // printf("%d\n", strcmp("abcd abc", "abcd aaa"));
    qsort(ptr_data, str_count, sizeof(char*), string_compare);
    printf("%s\n", *(ptr_data + 3));
    // for(size_t i = 0; i < 5; i++)
    // {
    //     printf("%s\n", *(ptr_data + i));
    // }

    // printf("n = %zu\n", strlen(data));
    return 0;
}