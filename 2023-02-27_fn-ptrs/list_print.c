#include "list_print.h"

void print_list(list *lst, void (*print_thing)(void *))
{
    while (list_length(lst) > 0)
    {
        void *n = list_remove(lst, 0);
        print_thing(n);
        free(n);
    }
}