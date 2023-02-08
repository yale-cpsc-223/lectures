#include "list.h"
#include "array_helpers.h"

#define INITIAL_CAPACITY 2
#define RESIZE_RATIO 2

struct list
{
    size_t capacity;
    size_t length;
    int *array;
};

list *create_list()
{
    list *lst = malloc(sizeof(list));
    lst->capacity = INITIAL_CAPACITY;
    lst->length = 0;
    lst->array = calloc(lst->capacity, sizeof(int));
    return lst;
}

int length(list *lst)
{
    return lst->length;
}

void append(list *lst, int val)
{
    if (lst->length >= lst->capacity)
    {
        lst->capacity *= RESIZE_RATIO;
        lst->array = realloc(lst->array, lst->capacity * sizeof(int));
    }
    lst->array[lst->length] = val;
    lst->length++;
}

int remove_last(list *lst)
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

void destroy_list(list *lst)
{
    free(lst->array);
    free(lst);
}

void print_list(list *lst)
{
    print_arr(lst->array, lst->length);
}
