#ifndef __LIST_PRINT_H__
#define __LIST_PRINT_H__

#include "list/list.h"

void print_list(list *lst, void (*print_thing)(void *));

#endif