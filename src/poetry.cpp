#include "make_ptr_array.h"
#include "string_compare.h"
#include "myerror.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>




int main()
{
    const size_t max_str_count = 200;
    char *data = get_data_from_file("data.txt"); // free data !!!!!
    char **ptr_data = (char **)calloc(sizeof(char*), max_str_count);
    size_t str_count = make_ptr_array(data, ptr_data); //number of string (does not include an emply lines and does not count the last empty string)
    puts("------------------------------------------");
    for(size_t i = 0; i < str_count; i++)
    {
        printf("%s\n", *(ptr_data + i));
    }
    puts("------------------------------------------");

    printf("%d\n", strcmp("Was in fact a fine estate,", "Beside a river. On every side,"));
    qsort(ptr_data, str_count, sizeof(char*), string_compare);

    for(size_t i = 0; i < str_count; i++)
    {
        printf("%s\n", *(ptr_data + i));
    }

    return 0;
}