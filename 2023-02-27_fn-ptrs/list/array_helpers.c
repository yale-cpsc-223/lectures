#ifndef _ARRAY_HELPERS_C
#define _ARRAY_HELPERS_C

#include <stdio.h>
#include "array_helpers.h"

#define INITIAL_CAPACITY (25)
#define RESIZE_FACTOR (2)

int intcmp(const void *p, const void *q)
{
    int a = *(int *)p, b = *(int *)q;
    if (a == b)
    {
        return 0;
    }
    else if (a < b)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}

void **array_expand_if_necessary(void **array, size_t *length, size_t *capacity)

{
    if (*length == *capacity)
    {
        *capacity *= RESIZE_FACTOR;
        return realloc(array, sizeof(void *) * *capacity);
    }
    else
    {
        return array;
    }
}

void **array_contract_if_necessary(void **array, size_t *length, size_t *capacity)
{
    if (*capacity >= INITIAL_CAPACITY * RESIZE_FACTOR && *length * RESIZE_FACTOR < *capacity / RESIZE_FACTOR)
    {
        *capacity = *capacity / RESIZE_FACTOR;
        return realloc(array, sizeof(void *) * *capacity);
    }
    else
    {
        return array;
    }
}

void print_arr(int *arr, size_t len)
{
    printf("%p->[ ", (void *)arr);
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void print_arr_colors(int *arr, size_t len, char *color)
{
    printf("\033[%sm%p->{ ", color, (void *)arr);
    for (size_t i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("}\033[0m\n");
}

int *array_with_default(int def, size_t len)
{
    int *arr = calloc(len, sizeof(int));
    for (size_t i = 0; i < len; i++)
    {
        arr[i] = def;
    }
    return arr;
}

void arr_copy(int *dest, int *src, size_t len)
{
    for (size_t i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
}

#endif
