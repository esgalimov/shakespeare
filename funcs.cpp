#include "header.h"

char * import_string(FILE * stream)
{
    assert(stream != NULL);

    char str[MAXLEN];
    if (fgets(str, MAXLEN, stream) != NULL)
        return strdup(str);
    return NULL;
}

int import_text(char * text[])
{
    assert(text != NULL);

    FILE * fp = NULL;
    fp = fopen("./hamlet.txt", "r");
    char * string = NULL;
    int i = 0;
    if (fp != NULL)
    {
        string = import_string(fp);
        while (string != NULL && i < MAXSTRINGS)
        {
            text[i++] = string;
            string = import_string(fp);
        }
    }
    fclose(fp);
    return i;
}

void bubble_sort(char * arr[], int len)
{
    assert(arr != NULL);

    int i = 0, j = 0;
    char * change = NULL;
    for (i = 0; i < len; i++)
        for (j = i; j < len; j++)
            if (strcmp(arr[i], arr[j]) > 0)
            {
                change = arr[i];
                arr[i] = arr[j];
                arr[j] = change;
            }
}
