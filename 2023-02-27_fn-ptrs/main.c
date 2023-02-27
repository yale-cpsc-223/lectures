#include <stdlib.h>
#include <stdio.h>

#include "list/list.h"
#include "mergesort.h"

int main(int argc, char *argv[])
{
    // Create a list
    list *lst = list_create();

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

    while (list_length(lst) > 0)
    {
        int *n = list_remove(lst, 0);
        printf("%d\n", *n);
        free(n);
    }
    list_destroy(lst);

    printf("Done.\n");
    return 0;
}
