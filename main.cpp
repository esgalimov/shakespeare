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
    char * text;
    size_t len = 0, filesize = 0;
    strings = import_text(fp, &len, &filesize, &text);
    fclose(fp);

    fp = fopen("./output.txt", "w");
    if (fp == NULL)
    {
        printf("Can not open file\n");
        return 0;
    }

    my_bubble_sort(strings, len, sizeof(strings[0]), str_start_cmp);

    fputs("START ALPHABET SORTING: \n\n", fp);
    write_into_file(strings, fp);
    fputs("<----------------------------------------------------->\n\n", fp);


    my_bubble_sort(strings, len, sizeof(strings[0]), str_end_cmp);

    fputs("END ALPHABET SORTING: \n\n", fp);
    write_into_file(strings, fp);
    fputs("<----------------------------------------------------->\n\n", fp);

    fputs("NORMAL TEXT: \n\n", fp);
    for (int i = 0; i < (int) filesize; i++)
        if (text[i] == '\0')
            text[i] = '\n';
    fputs(text, fp);



    fclose(fp);
    free(strings);
    free(text);
    return 0;
}
