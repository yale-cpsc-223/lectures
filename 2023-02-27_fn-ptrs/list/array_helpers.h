#ifndef _ARRAY_HELPERS_H
#define _ARRAY_HELPERS_H

#include <stdlib.h>

// Returns an int array of length len, with each element having been initalized to def
int* array_with_default(int def, size_t len);

// Returns the median of the first len elements of array nums
int median_of_ints(int* nums, size_t len);

// Prints the first len elements of array arr
void print_arr(int* arr, size_t len);

// Prints the first len elements of array arr with the ISO color string
void print_arr_colors(int* arr, size_t len, char* color);

// Copies the first len elements from array src to dest
void arr_copy(int* dest, int* src, size_t len);

#endif
