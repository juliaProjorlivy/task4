#include "make_ptr_array.h"
#include "print_text.h"
#include "myerror.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    const size_t max_str_count = 200;
    char *data = get_data_from_file("data.txt"); // free data !!!!!
    if(data == NULL)
    {
        ERROR("memory allocation failure");
        return 1;
    }

    char **ptr_data = (char **)calloc(sizeof(char*), max_str_count);
    if(ptr_data == NULL)
    {
        ERROR("memory allocation failure");
        return 1;
    }

    size_t str_count = make_ptr_array(data, ptr_data); //number of string (does not include an emply lines and does not count the last empty string)
    
    print_simple_text(ptr_data, str_count);

    print_sorted_text_lr(ptr_data, str_count);

    print_sorted_text_rl(ptr_data, str_count);
    
    free(data);
    free(ptr_data);

    return 0;
}

