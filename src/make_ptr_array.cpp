#include "myerror.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

size_t split_line(char *data, size_t data_size, char **ptr_data)
{
    assert(data != NULL);
    assert(ptr_data != NULL);

    size_t str_count = 0;
    size_t i = 0;
    *ptr_data = data;

    for(; i < data_size; i++)
    {
        if(data[i] == '\n')
        {
            data[i] = '\0';
            str_count++;
            ptr_data[str_count] = data + i + 1;
        }
    }
    return str_count;
}

char *get_data_from_file(const char *filename)
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
        char *data = (char *)calloc(sizeof(char), data_size);
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