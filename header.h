#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#include <stdio.h>
#include <string.h>
#include <assert.h>

const int MAXSTRINGS = 5000;
const int MAXLEN = 200;

char * import_string(FILE * stream);
int import_text(char * hamlet[]);
void bubble_sort(char * arr[], int len);


#endif
