#ifndef STRING_CMP_H
#define STRING_CMP_H

int string_compare_left_right(const void *line1, const void *line2);

int string_compare_right_left(const void *line1, const void *line2);

int string_compare_left_right_qs(const char *line1, const char *line2);

int string_compare_right_left_qs(const char *line1, const char *line2);

int compare_n(const void *line1, const void *line2);

#endif
