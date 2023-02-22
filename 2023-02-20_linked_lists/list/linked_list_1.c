#include "list.h"

#include <assert.h>

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
    list *lst = malloc(sizeof(list));
    lst->head = NULL;
    return lst;
}

int list_length(list *lst)
{
    int length = 0;
    node *n = lst->head;
    while (n != NULL)
    {
        n = n->next;
        length++;
    }
    return length;
}

void list_append(list *lst, int val)
{
    node *new = malloc(sizeof(node));
    new->payload = val;
    new->next = NULL;
    if (lst->head != NULL)
    {
        node *tail = lst->head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        tail->next = new;
    }
    else
    {
        lst->head = new;
    }
}

int list_remove_last(list *lst)
{
    assert(lst->head != NULL);
    int val = 0;
    if (lst->head->next != NULL)
    {
        node *prev /* TOOD */;
        node *tail = prev->next;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }
        val = tail->payload;
        free(tail);
        prev->next = NULL;
    }
    else
    {
        node *tail = lst->head;
        val = tail->payload;
        free(tail);
        lst->head = NULL;
    }
    return val;
}

void list_destroy(list *lst)
{
    node *n = lst->head;
    while (n != NULL)
    {
        node *killed = n;
        n = n->next;
        free(killed);
    }
    free(lst);
}

void list_print(list *lst, FILE *out)
{
    node *n = lst->head;
    fprintf(out, "%p -> [ ", (void *)lst);
    while (n != NULL)
    {
        fprintf(out, "%d ", n->payload);
        n = n->next;
    }
    fprintf(out, "]\n");
}
