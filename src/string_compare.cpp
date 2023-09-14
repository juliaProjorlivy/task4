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

    const char *line11 = (const char *)(*((char **)line1));
    const char *line22 = (const char *)(*((char **)line2));

    size_t len1 = strlen(line11) - 1;
    size_t len2 = strlen(line22) - 1;
    size_t i = 0;

    while((i <= len1) && (i <= len2))
    {
        const char *l1 = line11 + len1 - i;
        const char *l2 = line22 + len2 - i;
        if((*l1 != *l2) && isalpha(*l1) && isalpha(*l2))
        {
            return *(const unsigned char *)(line11 + len1 - i) - *(const unsigned char *)(line22 + len2 - i);
        }

        i++;
    }

    return 0;
}
