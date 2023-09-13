#ifndef PTR_ARRAY
#define PTR_ARRAY

#include <stdio.h>

size_t split_line(char *data, char **ptr_data);

char *get_data_from_file(const char *filename);

size_t make_ptr_array(char *data, char **ptr_data); // returns the number of strings in data

#endif
