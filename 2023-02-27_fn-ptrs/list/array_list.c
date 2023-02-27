#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INITIAL_CAPACITY (25)
#define RESIZE_FACTOR (2)

struct implementation
{
    size_t capacity;
    size_t length;
    void **array;
    int (*itemcmp)(void *, void *);
};

/*
 * Check if the actual number of items in the array is "too large"; if it is, increase the capacity of the array by a factor of RESIZE_FACTOR.
 */
void list_expand_if_necessary(list *lst)
{
    if (lst->length == lst->capacity)
    {
        lst->capacity *= RESIZE_FACTOR;
        size_t cap = lst->capacity;
        void **arr = lst->array;
        void *new = realloc(arr, sizeof(void *) * cap);
        lst->array = (void **)new;
    }
}

/*
 * Check if the actual number of items in the array is "too small"; if it is, decrease the capacity of the array by a factor of RESIZE_FACTOR.
 */
void list_contract_if_necessary(list *lst)
{
    if (lst->capacity >= INITIAL_CAPACITY * RESIZE_FACTOR && lst->length * RESIZE_FACTOR < lst->capacity / RESIZE_FACTOR)
    {
        lst->capacity = lst->capacity / RESIZE_FACTOR;
        lst->array = realloc(lst->array, sizeof(void *) * lst->capacity);
    }
}

list *list_create(int (*cmp)(void *, void *))
{
    list *lst = malloc(sizeof(list));
    if (lst != NULL)
    {
        lst->capacity = INITIAL_CAPACITY;
        lst->length = 0;
        lst->array = calloc(lst->capacity, sizeof(void *));
        lst->itemcmp = cmp;
    }
    return lst;
}

void list_insert(list *lst, size_t idx, void *p)
{
    list_expand_if_necessary(lst);
    for (size_t i = lst->length; i > idx; i--)
    {
        lst->array[i] = lst->array[i - 1];
    }
    lst->array[idx] = p;
    lst->length++;
}

void *list_remove(list *lst, size_t idx)
{
    void *removed = list_access(lst, idx);
    for (; idx < lst->length; idx++)
    {
        lst->array[idx] = lst->array[idx + 1];
    }
    if (removed != NULL)
    {
        lst->length--;
    }
    list_contract_if_necessary(lst);
    return removed;
}

void *list_access(list *lst, size_t idx)
{
    if (idx >= lst->length)
    {
        return NULL;
    }
    else
    {
        return lst->array[idx];
    }
}

size_t list_length(list *lst)
{
    return lst->length;
}

int list_compare_items(list *lst, size_t idxa, size_t idxb)
{
    return lst->itemcmp(list_access(lst, idxa), list_access(lst, idxb));
}

void list_destroy(list *lst)
{
    free(lst->array);
    free(lst);
}
