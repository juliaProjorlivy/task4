#include "print_text.h"
#include "quick_sort_str.h"
#include "string_compare.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

static void print(size_t str_count, char **ptr_data)
{
    puts("------------------------------------------");
    for(size_t i = 0; i < str_count; i++)
    {
        printf("%s\n", *(ptr_data + i));
    }
    puts("------------------------------------------");   
}

void print_simple_text(char **ptr_data, size_t str_count)
{
    assert(ptr_data != NULL);

    puts("this is just a text");

    print(str_count, ptr_data);

}

void print_sorted_text_lr(char **ptr_data, size_t str_count)
{
    assert(ptr_data != NULL);

    puts("this is a text sorted form left to right");

    qsort(ptr_data, str_count, sizeof(char*), string_compare_left_right);

    print(str_count, ptr_data);

}

void print_sorted_text_rl(char **ptr_data, size_t str_count)
{
    assert(ptr_data != NULL);

    puts("this is a text sorted form right to left");

    qsort(ptr_data, str_count, sizeof(char*), string_compare_right_left);

    print(str_count, ptr_data);

}

void print_sorted_text_lr_qs(char **ptr_data, size_t str_count)
{
    assert(ptr_data != NULL);

    puts("this is a text sorted form left to right with the quick sort function");

    Sort(ptr_data, str_count, string_compare_left_right_qs);

    print(str_count, ptr_data);
}

void print_sorted_text_rl_qs(char **ptr_data, size_t str_count)
{
    assert(ptr_data != NULL);

    puts("this is a text sorted form right to left with the quick sort function");

    Sort(ptr_data, str_count, string_compare_right_left_qs);

    print(str_count, ptr_data);
}

void print_sorted_text_lr_qs2(char **ptr_data, size_t str_count)
{
    assert(ptr_data != NULL);

    puts("this is a text sorted form left to right using Sort2 function");

    Sort2(ptr_data, str_count, sizeof(char*), string_compare_left_right);

    print(str_count, ptr_data);

}

void print_sorted_text_rl_qs2(char **ptr_data, size_t str_count)
{
    assert(ptr_data != NULL);

    puts("this is a text sorted form right to left using Sort2 function");

    Sort2(ptr_data, str_count, sizeof(char*), string_compare_right_left);

    print(str_count, ptr_data);

}

void print_sorted_text(int argc, const char *argv[], char **ptr_data, size_t str_count)
{
    assert(argv != NULL);

    if(argc >= 2)
    {
        if (!strcmp(argv[1], "-st")) // st - simple text
        {
            print_simple_text(ptr_data, str_count);
        }
        else if(!strcmp(argv[1], "-l")) // sorted from left to right
        {
            print_sorted_text_lr_qs(ptr_data, str_count);
            print_sorted_text_lr(ptr_data, str_count);
            print_sorted_text_lr_qs2(ptr_data, str_count);
        }
        else if(!strcmp(argv[1], "-r")) // sorted from right to left
        {
            print_sorted_text_rl_qs(ptr_data, str_count);
            print_sorted_text_rl(ptr_data, str_count);
            print_sorted_text_rl_qs2(ptr_data, str_count);
        }
    }
}
