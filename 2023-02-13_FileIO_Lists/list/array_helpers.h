#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdlib.h>
#include <stdio.h>

// Returns an int array of length len, with each element having been initalized to def
int *array_with_default(int def, size_t len);

// Prints the first len elements of array arr
void print_arr(FILE *out, int *arr, size_t len);

// Copies the first len elements from array src to dest
void arr_copy(int *dest, int *src, size_t len);

#endif
