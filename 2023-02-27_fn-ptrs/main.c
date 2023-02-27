#include <stdlib.h>
#include <stdio.h>

#include "list/list.h"

int intcmp(void *p1, void *p2)
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

void merge(list *lst, size_t start, size_t mid, size_t end)
{

    // If the direct merge is already sorted
    if (list_compare_items(lst, mid, mid + 1) <= 0)
    {
        return;
    }

    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && mid + 1 <= end)
    {

        // If element 1 is in right place
        if (list_compare_items(lst, start, mid + 1) <= 0)
        {
            start++;
        }
        else
        {
            list_insert(lst, start, list_remove(lst, mid + 1));

            // Update all the indices
            start++;
            mid++;
        }
    }
}

void mergesort(list *lst, size_t start, size_t end)
{
    if (end > start)
    {
        size_t mid = start + (end - start) / 2;
        mergesort(lst, start, mid);
        mergesort(lst, mid + 1, end);
        merge(lst, start, mid, end);
    }
}

int main(int argc, char *argv[])
{
    // Create a list
    list *lst = list_create(intcmp);

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
