#include "header.h"

int main(void)
{
    char * hamlet[MAXSTRINGS];
    int len = 0;
    len = import_text(hamlet);
    for (int i = 0; i < len; i++)
        printf("%4d  %s", i, hamlet[i]);
    printf("\n\n");
    bubble_sort(hamlet, len);
    for (int i = 0; i < len; i++)
        printf("%4d  %s", i, hamlet[i]);
    return 0;
}
