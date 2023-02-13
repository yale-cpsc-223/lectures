#include <stdio.h>
#include "list/list.h"

int main(int argv, char **argc)
{
    list *lst = list_create();
    int num = 0;
    while (fscanf(stdin, "%d", &num) > 0)
    {
        if (num >= 0)
        {
            // Add a '1' to the end of the list
            list_append(lst, 1);
        }
        else if (list_length(lst) > 0)
        {
            // Remove the last element of the list
            list_remove_last(lst);
        }

        // Print the important part of the list
        list_print(lst);
    }
    printf("Done.\n");
    list_destroy(lst);
}
