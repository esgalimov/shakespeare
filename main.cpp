#include "header.h"

int main(void)
{
    FILE * fp;
    fp = fopen("./hamlet.txt", "r");
    if (fp == NULL)
    {
        printf("Can not open file\n");
        return 0;
    }

    char ** strings;
    size_t len = 0;
    strings = import_text(fp, &len);
    fclose(fp);

    my_bubble_sort(strings, len, sizeof(strings[0]), str_start_cmp);
    int i = 0;
    while (strings[i] != NULL)
        printf("%s\n", strings[i++]);

    my_bubble_sort(strings, len, sizeof(strings[0]), str_end_cmp);
    i = 0;
    while (strings[i] != NULL)
        printf("%s\n", strings[i++]);

    free(strings);
    return 0;
}
