#include <stdlib.h>
#include <stdio.h>

#define INITIAL_CAPACITY (2)
#define ELEMENT_SIZE (sizeof(int))

typedef struct
{
    size_t length;
    size_t capacity;
    int *array;
} list;

list create_list()
{
    list lst;
    lst.length = 0;
    lst.capacity = INITIAL_CAPACITY;
    lst.array = malloc(lst.capacity * ELEMENT_SIZE);
    return lst;
}
void append(list lst, int x)
{
    if (lst.length == lst.capacity)
    {
        lst.capacity = lst.capacity * 2;
        lst.array = realloc(lst.array, lst.capacity * ELEMENT_SIZE);
    }
    lst.array[lst.length] = x;
    lst.length++;
}

void remove_last(list lst)
{
    fprintf(stdout, "Removed %d\n", lst.array[lst.length - 1]);
    lst.length--;
    if (lst.length < lst.capacity / 2)
    {
        lst.capacity = lst.capacity / 2;
        lst.array = realloc(lst.array, lst.capacity * ELEMENT_SIZE);
    }
}

void print_list(list lst)
{
    for (size_t i = 0; i < lst.capacity; i++)
    {
        fprintf(stdout, "%d ", lst.array[i]);
    }
    fprintf(stdout, "\n");
}

int main(int argc, char *argv[])
{
    // Create a list of ints
    list lst = create_list();
    int num;
    while (fscanf(stdin, "%d", &num) > 0)
    {
        if (num >= 0)
        {
            // Add a '1' to the end of the list
            append(lst, 1);
        }
        else if (lst.length > 0)
        {
            // Remove the last element of the list
            remove_last(lst);
        }

        // Print the list
        print_list(lst);
    }

    printf("Done.\n");
    return 0;
}
