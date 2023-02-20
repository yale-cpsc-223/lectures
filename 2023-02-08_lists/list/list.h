#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

// Type of a list (of ints) that can be appended to and removed from
typedef struct
{
    size_t length;
    size_t capacity;
    int *array;
} list;

// Create a List
list *list_create();

// Returns the number of elements in lst
int list_length(list *lst);

// Adds val to the (right) end of lst
void list_append(list *lst, int val);

// Removes an element from the (right) end of lst and returns it
int list_remove_last(list *lst);

// Frees the memory allocated by lst
void list_destroy(list *lst);

// Prints the list
void list_print(list *lst);

#endif
