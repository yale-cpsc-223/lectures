#include <stdio.h>
#include "list/list.h"

int main(int argv, char **argc)
{
    list *lst = create_list();
    int num = 0;
    while (fscanf(stdin, "%d", &num) > 0)
    {
        if (num >= 0)
        {
            // Add a '1' to the end of the list
            append(lst, 1);
        }
        else if (length(lst) > 0)
        {
            // Remove the last element of the list
            remove_last(lst);
        }

        // Print the important part of the list
        print_list(lst);
    }
    printf("Done.\n");
    destroy_list(lst);
}
