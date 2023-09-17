#include "string_compare.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

int string_compare_left_right(const void *line1, const void *line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    const char *line11 = (const char *)(*((char**)(line1)));
    const char *line22 = (const char *)(*((char**)(line2)));

    return strcmp(line11, line22);
}


int string_compare_right_left(const void *line1, const void *line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    const char *line11 = *((const char **)line1);
    const char *line22 = *((const char **)line2);

    size_t len1 = strlen(line11) - 1;
    size_t len2 = strlen(line22) - 1;

    const char *l1 = line11 + len1;
    const char *l2 = line22 + len2;

    while((*l1) && (*l2))
    {
        while(!isalpha(*l1)) *l1--;
        while(!isalpha(*l2)) *l2--;

        if(*l1 != *l2)
        {
            return *l1 - *l2;
        }

        *l1--;
        *l2--;
    }


    return 0;
}

int string_compare_left_right_qs(const char *line1, const char *line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    return strcmp(line1, line2);
}

int string_compare_right_left_qs(const char *line11, const char *line22)
{
    assert(line11 != NULL);
    assert(line22 != NULL);

    size_t len1 = strlen(line11) - 1;
    size_t len2 = strlen(line22) - 1;

    const char *l1 = line11 + len1;
    const char *l2 = line22 + len2;

    while((*l1) && (*l2))
    {
        while(!isalpha(*l1)) *l1--;
        while(!isalpha(*l2)) *l2--;

        if(*l1 != *l2)
        {
            return *l1 - *l2;
        }

        *l1--;
        *l2--;
    }

    return 0;
}
