#include "header.h"

char ** import_text(struct Text * book, FILE * stream)
{
    assert(stream != NULL);
    assert(book != NULL);

    fseek(stream, 0L, SEEK_END);
    book->filesize = (size_t) ftell(stream);
    rewind(stream);

    book->buffer = (char *) calloc(book->filesize + 1, sizeof(char));
    fread(book->buffer, sizeof(char), book->filesize, stream);
    *(book->buffer + book->filesize) = '\0';

    book->len = count_symbol('\n', book->buffer, book->filesize);

    return get_ptrs(book->buffer, book->len, book->filesize);

}


size_t count_symbol(char ch, char * string, size_t filesize)
{
    assert(string != NULL);

    int cnt_strings = 0;
    for (size_t i = 0; i < filesize; i++)
        if (string[i] == ch)
            cnt_strings++;
    return cnt_strings;
}


char ** get_ptrs(char * strings, size_t n_strings, size_t filesize)
{
    assert(strings != NULL);
    char ** strptr = (char **) calloc((size_t) (n_strings + 1), sizeof(char *));

    if (strptr == NULL)
        return NULL;

    strptr[0] = &strings[0];
    size_t index = 1;
    for (size_t i = 1; i < filesize; i++)
        if (strings[i] == '\n')
        {
            if (index < n_strings)
            {
                strings[i] = '\0';
                strptr[index] = &strings[i + 1];
                index++;
            }
        }
    strptr[index] = NULL;

    return strptr;
}


int str_start_cmp(const void * s1, const void * s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    const char * str1 = *(const char **) s1;
    const char * str2 = *(const char **) s2;

    int i = 0, j = 0;
    int size1 = (int) strlen(str1);
    int size2 = (int) strlen(str2);

    while (i < size1 && !isalpha(str1[i])) i++;
    while (j < size2 && !isalpha(str2[j])) j++;

    while (i < size1 && j < size2 && tolower(str1[i]) == tolower(str2[j])
             && str1[i] != '\0' && str2[j] != '\0')
    {
        i++;
        j++;
        while (i < size1 && !isalpha(str1[i])) i++;
        while (j < size2 && !isalpha(str2[j])) j++;
    }
    return (int) tolower(str1[i]) - (int) tolower(str2[j]);
}


int str_end_cmp(const void * s1, const void * s2)
{
    assert(s1 != NULL);
    assert(s2 != NULL);

    const char * str1 = *(const char **) s1;
    const char * str2 = *(const char **) s2;

    int i = (int) strlen(str1);
    int j = (int) strlen(str2);

    while (i > 0 && !isalpha(str1[i])) i--;
    while (j > 0 && !isalpha(str2[j])) j--;

    while (i > 0 && j > 0 && tolower(str1[i]) == tolower(str2[j]))
    {
        i--;
        j--;
        while (i > 0 && !isalpha(str1[i])) i--;
        while (j > 0 && !isalpha(str2[j])) j--;
    }
    return (int) tolower(str1[i]) - (int) tolower(str2[j]);
}

void my_bubble_sort(void * data, size_t n_strings, size_t elem_size,
             int(*comp_func)(const void * a, const void * b))
{
    assert(data != NULL);
    assert(comp_func != NULL);
    char * change = NULL;

    size_t i = 0, j = 0;
    for (i = 0; i < n_strings; i++)
        for (j = i; j < n_strings; j++)
            if ((*comp_func)((const char *) data + i * elem_size,
                             (const char *) data + j * elem_size) > 0) {
                change = *((char**)(data) + i);
                *((char**)(data) + i) = *((char**)(data) + j);
                *((char**)(data) + j) = change;
            }
}

int is_without_text(const char * str)
{
    assert(str != NULL);
    int flag = 1;
    int len = (int) strlen(str);
    for (int i = 0; i < len; i++)
        if (!isblank(str[i]))
        {
            flag = 0;
            break;
        }
    return flag;
}

void write_into_file(char ** strings, FILE * stream)
{
    assert(strings != NULL);
    assert(stream != NULL);

    int i = 0;
    while (strings[i] != NULL)
    {
        if (is_without_text(strings[i]))
        {
            i++;
            continue;
        }
        else
        {
            fputs(strings[i++], stream);
            fputs("\n", stream);
        }
    }
}

void construct(struct Text * book, FILE * stream)
{
    assert(book != NULL);
    assert(stream != NULL);

    book->strings = NULL;
    book->buffer = NULL;
    book->len = 0;
    book->filesize = 0;

    book->strings = import_text(book, stream);
    fclose(stream);
}

void destruct(struct Text * book)
{
    assert(book != NULL);

    book->len = 0;
    book->filesize = 0;
    free(book->buffer);
    free(book->strings);
    book->strings = NULL;
    book->buffer = NULL;
}
