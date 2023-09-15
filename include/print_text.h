#ifndef PRINT_TEXT_H
#define PRINT_TEXT_H

#include <stdio.h>

void print_simple_text(char **ptr_data, size_t str_count);

void print_sorted_text_lr(char **ptr_data, size_t str_count);

void print_sorted_text_rl(char **ptr_data, size_t str_count);

void print_sorted_text_lr_qs(char **ptr_data, size_t str_count);

void print_sorted_text_rl_qs(char **ptr_data, size_t str_count);

// void print_sorted_text(int argc, const char *argv[]);

#endif
