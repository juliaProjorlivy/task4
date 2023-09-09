#include "make_ptr_array.h"
#include "myerror.h"
#include <assert.h>
#include <stdio.h>



int main()
{
    const char *data = get_data_from_file("data.txt"); // free data !!!!!
    printf("%s", data);
    return 0;
}