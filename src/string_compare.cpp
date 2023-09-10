#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

int string_compare(const void *line1, const void *line2)
{
    assert(line1 != NULL);
    assert(line2 != NULL);

    const char *line11 = (const char *)(*((char**)(line1)));
    const char *line22 = (const char *)(*((char**)(line2)));
    // while(line11 != '\0' || line22 != '\0')
    printf("line1 = %s\n line2 = %s\n", line11, line22);

    return strcmp(line11, line22);
}