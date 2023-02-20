#include "list.h"

typedef struct list_node node;

struct list_node
{
    int payload;
    node *next;
};

struct implementation
{
    node *head;
};

list *list_create()
{
    return NULL;
}

int list_length(list *lst)
{
    return 0;
}

void list_append(list *lst, int val)
{
}

int list_remove_last(list *lst)
{
    return 0;
}

void list_destroy(list *lst)
{
}

void list_print(list *lst, FILE *out)
{
    fprintf(out, "TODO\n");
}
