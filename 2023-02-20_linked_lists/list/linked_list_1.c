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
    list *lst = malloc(sizeof(list));
    lst->head = NULL;
    return lst;
}

int list_length(list *lst)
{
    int length = 0;
    node *n = lst->head;
    while (n->next != NULL)
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
    if (lst->head == NULL)
    {
        lst->head = new;
    }
    else
    {
        node *tail_candidate = lst->head;
        while (tail_candidate->next != NULL)
        {
            tail_candidate = tail_candidate->next;
        }
        tail_candidate->next = new;
    }
}

int list_remove_last(list *lst)
{
    if (/* list is long */ 1)
    {
        node *prev /* TODO */;
        node *n = lst->head;
        while (n->next != NULL)
        {
            n = n->next;
        }
        prev->next = NULL;
        int ans = n->payload;
        free(n);
        return ans;
    }
    else
    {
        node *to_remove = lst->head;
        lst->head = NULL;
        int ans = to_remove->payload;
        free(to_remove);
        return ans;
    }
}

void list_destroy(list *lst)
{
    node *_1 = lst->head;
    while (_1 != NULL)
    {
        node *_2 = _1->next;
        free(_1);
        _1 = _2;
    }
    free(lst);
}

void list_print(list *lst, FILE *out)
{
    fprintf(out, "TODO\n");
}
