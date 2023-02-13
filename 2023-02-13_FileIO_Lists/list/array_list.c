#include "list.h"
#include "array_helpers.h"
#include <stdio.h>

#define INITIAL_CAPACITY 2
#define RESIZE_RATIO 2

list *list_create()
{
    list *lst = malloc(sizeof(list));
    lst->capacity = INITIAL_CAPACITY;
    lst->length = 0;
    lst->array = calloc(lst->capacity, sizeof(int));
    return lst;
}

int list_length(list *lst)
{
    return lst->length;
}

void list_append(list *lst, int val)
{
    if (lst->length >= lst->capacity)
    {
        lst->capacity *= RESIZE_RATIO;
        lst->array = realloc(lst->array, lst->capacity * sizeof(int));
    }
    lst->array[lst->length] = val;
    lst->length++;
}

int list_remove_last(list *lst)
{
    lst->length--;
    int last = lst->array[lst->length];
    if (lst->length * RESIZE_RATIO < lst->capacity / RESIZE_RATIO)
    {
        lst->capacity /= RESIZE_RATIO;
        lst->array = realloc(lst->array, lst->capacity * sizeof(int));
    }
    return last;
}

void list_destroy(list *lst)
{
    free(lst->array);
    free(lst);
}

void list_print(list *lst)
{
    printf("Capacity %-4zu ", lst->capacity);
    print_arr(lst->array, lst->length);
}
