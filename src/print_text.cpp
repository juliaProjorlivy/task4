#include "print_text.h"
#include "string_compare.h"
#include <assert.h>
#include <stdlib.h>

void print_simple_text(char **ptr_data, size_t str_count)
{
    assert(ptr_data != NULL);

    puts("this is just a text");
    puts("------------------------------------------");
    for(size_t i = 0; i < str_count; i++)
    {
        printf("%s\n", *(ptr_data + i));
    }
    puts("------------------------------------------");

}

void print_sorted_text_lr(char **ptr_data, size_t str_count)
{
    assert(ptr_data != NULL);

    puts("this is a text sorted form left to right");
    puts("------------------------------------------");

    qsort(ptr_data, str_count, sizeof(char*), string_compare_left_right);

    for(size_t i = 0; i < str_count; i++)
    {
        printf("%s\n", *(ptr_data + i));
    }
    puts("------------------------------------------");

}

void print_sorted_text_rl(char **ptr_data, size_t str_count)
{
    assert(ptr_data != NULL);

    puts("this is a text sorted form right to left");
    puts("------------------------------------------");

    qsort(ptr_data, str_count, sizeof(char*), string_compare_right_left);

    for(size_t i = 0; i < str_count; i++)
    {
        printf("%s\n", *(ptr_data + i));
    }
    puts("------------------------------------------");

}
