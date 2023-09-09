#ifndef PTR_ARRAY
#define PTR_ARRAY

#include <stdio.h>

size_t split_line(char *data, size_t data_size, char **ptr_data);

char *get_data_from_file(const char *filename);

#endif