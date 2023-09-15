#ifndef QUICK_SORT_STR_H
#define QUICK_SORT_STR_H

#include <stdio.h>

int Sort(char **data, size_t data_size, int (*compare)(const char *, const char *));

int Sort2(void *data1, size_t data_size, size_t el_size, int (*compare)(const void *, const void *));

#endif
