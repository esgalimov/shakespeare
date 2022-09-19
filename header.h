#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

char ** import_text(FILE * stream, size_t * n_strings);
int count_symbol(char ch, char * string, size_t filesize);
void bubble_sort(char * arr[], int len);
char ** get_ptrs(char * strings, int n_strings, size_t filesize);
int str_start_cmp(const void * s1, const void * s2);
int str_end_cmp(const void * s1, const void * s2);
void my_bubble_sort(void * strings, size_t n_strings, size_t elem_size,
             int(*comp_func)(const void * a, const void * b));


#endif
