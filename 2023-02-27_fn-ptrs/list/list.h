#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>

// Type of a list
typedef struct implementation list;

/*
 * Allocate memory for a new list and return a pointer to it.
 */
list *list_create(int (*cmp)(void *, void *));

/*
 * Insert p into the list at index idx by copying the pointer, shifting the latter part of the list one “slot” to the right.
 */
void list_insert(list *lst, size_t idx, void *p);

/*
 * Remove and return the item from the list at index idx.
 */
void *list_remove(list *lst, size_t idx);

/*
 * Return a pointer to the item pointed to by index idx in the list, or NULL if idx is not a valid index (i.e., it is >= the length of the list).
 */
void *list_access(list *lst, size_t idx);

/*
 * Returns the comparison of two items in the list.
 */
int list_compare_items(list *lst, size_t idxa, size_t idxb);

/*
 * Return the number of items in the list.
 */
size_t list_length(list *lst);

/*
 * Free all memory associated with the list, but leave the memory associated with the items in the list untouched.
 */
void list_destroy(list *lst);

#endif
