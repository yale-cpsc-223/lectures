#include <stdlib.h>
#include <stdio.h>

#include "list/list.h"
#include "list_print.h"
#include "mergesort.h"

int mainintcmp(void *p1, void *p2)
{
    int i1 = *(int *)p1, i2 = *(int *)p2;
    if (i1 < i2)
    {
        return -1;
    }
    else if (i1 > i2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void simple_int_print(void *item)
{
    printf("%d\n", *(int *)item);
}

void int_print(void *item)
{
    printf("The item is: %d\n", *(int *)item);
}

int main(int argc, char *argv[])
{
    // Create a list
    list *lst = list_create(mainintcmp);

    FILE *infile = fopen(argv[1], "r");
    int n;
    while (fscanf(infile, "%d", &n) == 1)
    {
        int *item = malloc(sizeof(int));
        *item = n;
        list_insert(lst, list_length(lst), item);
    }
    fclose(infile);

    mergesort(lst, 0, list_length(lst) - 1);

    print_list(lst, int_print);

    list_destroy(lst);

    printf("Done.\n");
    return 0;
}
