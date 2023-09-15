#include "string_compare.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

static char *reverse_line(const char *line)
{
    size_t len = strlen(line);
    char *reversed_line = (char *)calloc(sizeof(char), len);

    for(size_t i = 0; i < len; i++)
    {
        *(reversed_line + i) = *(line + len - i - 1);
    }
    
    return reversed_line;
}

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

    char *reversed_line1 = reverse_line(line11);
    char *reversed_line2 = reverse_line(line22);

    int res = strcmp((const char *)reversed_line1, (const char *)reversed_line2);

    free(reversed_line1);
    free(reversed_line2);

    return res;
}

int string_compare_left_right_qs(const char *line1, const char *line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    return strcmp(line1, line2);
}

int string_compare_right_left_qs(const char *line1, const char *line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    char *reversed_line1 = reverse_line(line1);
    char *reversed_line2 = reverse_line(line2);

    int res = strcmp((const char *)reversed_line1, (const char *)reversed_line2);

    free(reversed_line1);
    free(reversed_line2);

    return res;
}
