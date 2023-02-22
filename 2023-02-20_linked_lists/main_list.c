#include <stdio.h>
#include "list/list.h"

int main(int argv, char **argc)
{
    FILE *infile = fopen("numbers.in", "r");
    list *lst = list_create();
    int num = 0;
    while (fscanf(infile, "%d", &num) > 0)
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
        list_print(lst, stdout);
    }
    fprintf(stdout, "Done.\n");
    list_destroy(lst);
    fclose(infile);
}
