#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

int string_compare_left_right(const void *line1, const void *line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    const char *line11 = (const char *)(*((char**)(line1)));
    const char *line22 = (const char *)(*((char**)(line2)));

    return strcmp(line11, line22);
}

int string_compare_right_left_version2(const void *line1, const void *line2)
{
    const char *line11 = (const char *)(*((char **)line1));
    const char *line22 = (const char *)(*((char **)line2));

    puts("here");

    size_t len1 = strlen(line11) - 1;
    size_t len2 = strlen(line22) - 1;
    puts("here2");
    size_t i = 0;

    while(*(line11 + len1 - i) && *(line22 + len2 - i))
    {
        // puts("here2");
        if(*(line11 + len1 - i) != *(line22 + len2 - i))
        {
            break;
        }

        i++;
        // line11++;
        // line22++;
    }

    return *(const unsigned char *)(line11 + len1 - i) - *(const unsigned char *)(line22 + len2 - i);
}


const char *reverse_string(const char *line1, char *reverse_line)
{
    assert(line1 != NULL);
    assert(reverse_line != NULL);

    size_t line_size = strlen(line1);

    for(size_t i = 0; i < line_size; i++)
    {
        reverse_line[i] = line1[line_size - i - 1];
    }

    return (const char *)reverse_line;
}

int string_compare_right_left(const void *line1, const void *line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    char *line11 = (char *)(*((char**)(line1)));
    char *line22 = (char *)(*((char**)(line2)));

    char *reverse_line1 = (char *)calloc(strlen(line11), sizeof(char)); // free!!!
    char *reverse_line2 = (char *)calloc(strlen(line22), sizeof(char)); // free !!!

    return strcmp(reverse_string(line11, reverse_line1), reverse_string(line22, reverse_line2));
}
