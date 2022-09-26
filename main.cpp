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

    struct Text my_text;
    construct(&my_text, fp);

    fp = fopen("./output.txt", "w");
    if (fp == NULL)
    {
        printf("Can not open file\n");
        return 0;
    }

    my_bubble_sort(my_text.strings, my_text.len, sizeof(my_text.strings[0]), str_start_cmp);

    fputs("START ALPHABET SORTING: \n\n", fp);
    write_into_file(my_text.strings, fp);
    fputs("<----------------------------------------------------->\n\n", fp);


    my_bubble_sort(my_text.strings, my_text.len, sizeof(my_text.strings[0]), str_end_cmp);

    fputs("END ALPHABET SORTING: \n\n", fp);
    write_into_file(my_text.strings, fp);
    fputs("<----------------------------------------------------->\n\n", fp);

    fputs("NORMAL TEXT: \n\n", fp);
    for (int i = 0; i < (int) my_text.filesize; i++)
        if (my_text.buffer[i] == '\0')
            my_text.buffer[i] = '\n';
    fputs(my_text.buffer, fp);

    fclose(fp);

    destruct(&my_text);

    return 0;
}
