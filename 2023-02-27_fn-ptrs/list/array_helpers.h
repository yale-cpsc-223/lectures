#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdlib.h>

/*
 * Check if the actual number of items in the array is "too large"; if it is, increase the capacity of the array by a factor of RESIZE_FACTOR.
 */
void **array_expand_if_necessary(void **array, size_t *length, size_t *capacity);

/*
 * Check if the actual number of items in the array is "too small"; if it is, decrease the capacity of the array by a factor of RESIZE_FACTOR.
 */
void **array_contract_if_necessary(void **array, size_t *length, size_t *capacity);

// Returns an int array of length len, with each element having been initalized to def
int *array_with_default(int def, size_t len);

// Prints the first len elements of array arr
void print_arr(int *arr, size_t len);

// Prints the first len elements of array arr with the ISO color string
void print_arr_colors(int *arr, size_t len, char *color);

// Copies the first len elements from array src to dest
void arr_copy(int *dest, int *src, size_t len);

#endif
