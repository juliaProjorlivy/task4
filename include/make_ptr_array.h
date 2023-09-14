#ifndef PTR_ARRAY
#define PTR_ARRAY

#include <stdio.h>

size_t split_line(char *data, char **ptr_data);

char *get_data_from_file(const char *filename);

char **make_ptr_array(char *data, size_t *str_count); // returns the number of strings in data

#endif
