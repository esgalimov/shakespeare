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

    fp = fopen("./output.txt", "w");
    if (fp == NULL)
    {
        printf("Can not open file\n");
        return 0;
    }

    //printf("%d", is_without_text(strings[2]));

    my_bubble_sort(strings, len, sizeof(strings[0]), str_start_cmp);

    fputs("START ALPHABET SORTING: \n\n", fp);
    write_into_file(strings, fp);
    fputs("<----------------------------------------------------->", fp);


    my_bubble_sort(strings, len, sizeof(strings[0]), str_end_cmp);

    fputs("END ALPHABET SORTING: \n\n", fp);
    write_into_file(strings, fp);
    fputs("<----------------------------------------------------->", fp);

    fputs("NORMAL TEXT: \n\n", fp);


    fclose(fp);
    free(strings);
    return 0;
}
