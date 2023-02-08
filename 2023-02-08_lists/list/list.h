#ifndef _LIST_H
#define _LIST_H

#include <stdlib.h>

// Type of a list (of ints) that can be appended to and removed from
typedef struct list list;

// Create a List
list *create_list();

// Returns the number of elements in lst
int length(list *lst);

// Adds val to the (right) end of lst
void append(list *lst, int val);

// Removes an element from the (right) end of lst and returns it
int remove_last(list *lst);

// Frees the memory allocated by lst
void destroy_list(list *lst);

// Prints the list
void print_list(list *lst);

#endif
