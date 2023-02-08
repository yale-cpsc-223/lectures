#include <stdlib.h>
#include <stdio.h>

#define INITIAL_CAPACITY 2

int main(int argc, char *argv[])
{
    // Create a list of ints
    size_t length = 0;
    int *lst = malloc(2 * sizeof(int));
    int num;
    while (fscanf(stdin, "%d", &num) > 0)
    {
        if (num >= 0)
        {
            // Add a '1' to the end of the list
            lst[length] = 1;
            length++;
        }
        else if (length > 0)
        {
            // Remove the last element of the list
            fprintf(stdout, "Removed %d\n", lst[length - 1]);
            length--;
        }

        // Print the important part of the list
        for (size_t i = 0; i < length; i++)
        {
            fprintf(stdout, "%d", lst[i]);
        }
        fprintf(stdout, "\n");
    }

    free(lst);

    printf("Done.\n");
    return 0;
}
