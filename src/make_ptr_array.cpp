#include "make_ptr_array.h"
#include "myerror.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

size_t split_line(char *data, char **ptr_data)
{
    assert(data != NULL);
    assert(ptr_data != NULL);

    size_t str_count = 0;
    size_t i = 0;
    size_t data_size = strlen(data);
    size_t strlen = 0; // the lenght of each string

    for(; i < data_size; i++)
    {
        strlen++;
        if(data[i] == '\n')
        {
            data[i] = '\0';

            if(strlen > 1) // if it is not an empty line
            {
                data[i] = '\0';
                *(ptr_data + str_count) = data + i - strlen + 1;
                str_count++;
            }
            strlen = 0;
        }
    }

    return str_count;
}

char **make_ptr_array(char *data, size_t *str_count) // returns the number of strings in data
{
    assert(data != NULL);
    assert(str_count != NULL);

    const size_t max_str_count = 200;

    char **ptr_data = (char **)calloc(sizeof(char **), max_str_count);
    *str_count = split_line(data, ptr_data);
    ptr_data = (char **)realloc(ptr_data, ((*str_count) + 1) * sizeof(char*));

    return ptr_data;
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
        char *data = (char *)calloc(sizeof(char), data_size + 1); // free data!
        if(data == NULL)
        {
            fclose(file);
            ERROR("memory allocation failure");
            return NULL;
        }

        if(!fread(data, sizeof(char), data_size, file))
        {
            fclose(file);
            ERROR("can not read the file");
            return NULL;
        }

        fclose(file);
        return data;
    }

    fclose(file);
    ERROR("unable to stat");
    return NULL;
}
