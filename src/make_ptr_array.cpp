#include "myerror.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

size_t split_line(char *data, char **ptr_data) // fills the array of pointers (have to know string count)
{
    assert(data != NULL);
    assert(ptr_data != NULL);

    size_t str_count = 0;
    size_t i = 0;
    size_t data_size = strlen(data);

    *ptr_data = data;

    for(; i < data_size; i++)
    {
        if(data[i] == '\n')
        {
            data[i] = '\0';

            if((i < (data_size - 1)) && data[i + 1] == '\n')
            {
                str_count++;
            }
            else if((i > 0) && data[i - 1] == '\0')
            {
                ptr_data[str_count] = data + i + 1;
            }
            else
            {
                str_count++;
                ptr_data[str_count] = data + i + 1;   
            }
        }
    }
    return str_count;
}

size_t make_ptr_array(char *data, char **ptr_data) // returns the number of strings in data
{
    assert(data != NULL);
    assert(ptr_data != NULL);

    size_t str_count = split_line(data, ptr_data);
    ptr_data = (char **)realloc(ptr_data, sizeof(char*)*(str_count + 1));
    return str_count;
} 

char *get_data_from_file(const char *filename) // collect data from file to the array data
{
    assert(filename != NULL);

    FILE *file = fopen(filename, "r");
    if(file == NULL)
    {
        ERROR("failed to open the file");
        return NULL;
    }

    struct stat buf;
    if(!stat(filename, &buf))
    {
        size_t data_size = buf.st_size; 
        char *data = (char *)calloc(sizeof(char), data_size + 1);
        if(data == NULL)
        {
            ERROR("memory allocation failure");
            return NULL;
        }

        if(data_size != fread(data, sizeof(char), data_size, file))
        {
            ERROR("can not read the file");
            return NULL;
        }

        return data;
    }
    else
    {
        ERROR("unable to stat");
        return NULL;
    }

    return NULL;
}