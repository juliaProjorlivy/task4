#include "make_ptr_array.h"
#include "quick_sort_str.h"
#include "print_text.h"
#include "string_compare.h"
#include "myerror.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{

    char *data = get_data_from_file("data.txt"); // free data !!!!!
    if(data == NULL)
    {
        ERROR("cannot get data from file");
        return 1;
    }

    size_t str_count = 0;

    char **ptr_data = make_ptr_array(data, &str_count); //number of string (does not include an emply lines and does not count the last empty string)
    if(ptr_data == NULL)
    {
        free(data);
        ERROR("cannot make an arrauy");
        return 1;
    }

    print_sorted_text(argc, argv, ptr_data, str_count);
    
    free(data);
    free(ptr_data);

    return 0;
}
