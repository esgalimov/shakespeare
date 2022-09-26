#ifndef MY_HEADER_FILE_H
#define MY_HEADER_FILE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

//! @brief Struct that consist of variables for text processing
//!
//! @var strings - pointer to array with pointers to strings
//! @var buffer - pointer to buffer for text
//! @var len - number of strings
//! @var filesize - size of buffer in bytes

struct Text
{
    char ** strings;
    char * buffer;
    size_t len;
    size_t filesize;
};

//! @brief Function that import text from file and write it into the buffer
//! in allocated memory with calloc
//!
//! @param [out] book - pointer to struct with variables for text processing
//! @param [in] stream - pointer to the file with text
//!
//! @return Pointer to array with pointers to string
//! @note Function use get_ptrs to make array with pointers to strings

char ** import_text(struct Text * book, FILE * stream);

//! @brief Function for counting number of particular symbol
//!
//! @param [in] ch - symbol that is counting
//! @param [in] string - pointer to string where we want to count
//! @param [in] filesize - size of string in bytes
//!
//! @return Number of symbol ch

size_t count_symbol(char ch, char * string, size_t filesize);

//! @brief Function that swap "\n" to "\0" in buffer and make array of pointers to strings in buffer
//!
//! @param [in] strings - pointer to buffer
//! @param [in] n_strings - number of strings
//! @param [in] filesize - size of file in bytes
//!
//! @return pointer to array with pointers to stings
char ** get_ptrs(char * strings, size_t n_strings, size_t filesize);

//! @brief Comparator for alphabet sorting
//!
//! @param [in] - 1st string
//! @param [in] - 2nd string
//! @return Difference bettween first pair of not similar simbols

int str_start_cmp(const void * s1, const void * s2);

//! @brief Comparator for rhyme sorting (starts from end of string)
//!
//! @param [in] - 1st string
//! @param [in] - 2nd string
//! @return Difference bettween first pair of not similar simbols

int str_end_cmp(const void * s1, const void * s2);

//! @brief My bubble sort
//!
//! @param [out] strings - pointer to array to sort
//! @param [in] n_strings - number of strings
//! @param [in] elem_size - size of array's element
//! @param [in] comp_func - comparator that used for sorting

void my_bubble_sort(void * strings, size_t n_strings, size_t elem_size,
             int(*comp_func)(const void * a, const void * b));

//! @brief Function for checking if string consists of blank symbol only
//! @param [in] str - pointer to string for checking
//! @return 1 - if only blank symbols, else - 0

int is_without_text(const char * str);

//! @brief Function for writing string into file
//! @param [in] strings - array of pointers to strings
//! @param [in] stream - pointer to file for writing

void write_into_file(char ** strings, FILE * stream);

//! @brief Constructor for Text
//!
//! @param [out] book - pointer to struct with variables for text processing
//! @param [in] stream - pointer to file with text
//!
//! @note Initialize struct fields, use import_text, close file stream

void construct(struct Text * book, FILE * strem);

//! @brief Destruct for Text
//! @param [out] book - pointer to struct with variables for text processing

void destruct(struct Text * book);


#endif
