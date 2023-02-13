#ifndef _ARRAY_HELPERS_C
#define _ARRAY_HELPERS_C

#include <stdio.h>
#include "array_helpers.h"

void print_arr_colors(int *arr, size_t len, char *color);

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
