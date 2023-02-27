#include "list.h"
#include "array_helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INITIAL_CAPACITY (25)

struct implementation
{
    size_t capacity;
    size_t length;
    void **array;
    int (*cmp)(void *, void *);
};

list *list_create(int (*cmp)(void *, void *))
{
    list *lst = malloc(sizeof(list));
    if (lst != NULL)
    {
        lst->capacity = INITIAL_CAPACITY;
        lst->length = 0;
        lst->array = calloc(lst->capacity, sizeof(void *));
        lst->cmp = cmp;
    }
    return lst;
}

void list_insert(list *lst, size_t idx, void *p)
{
    lst->array = array_expand_if_necessary(lst->array, &(lst->length), &(lst->capacity));
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
    lst->array = array_contract_if_necessary(lst->array, &(lst->length), &(lst->capacity));
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

int list_compare_items(list *lst, size_t idxa, size_t idxb)
{
    void *itema = list_access(lst, idxa);
    void *itemb = list_access(lst, idxb);
    return lst->cmp(itema, itemb);
}

size_t list_length(list *lst)
{
    return lst->length;
}

void list_destroy(list *lst)
{
    free(lst->array);
    free(lst);
}
