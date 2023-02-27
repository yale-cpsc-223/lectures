#include "mergesort.h"

void merge(list *lst, size_t start, size_t mid, size_t end)
{

    // If the direct merge is already sorted
    if (*(int *)list_access(lst, mid) <= *(int *)list_access(lst, mid + 1))
    {
        return;
    }

    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && mid + 1 <= end)
    {

        // If element 1 is in right place
        if (*(int *)list_access(lst, start) <= *(int *)list_access(lst, mid + 1))
        {
            start++;
        }
        else
        {
            list_insert(lst, start, list_remove(lst, mid + 1));

            // Update all the indices
            start++;
            mid++;
        }
    }
}

void mergesort(list *lst, size_t start, size_t end)
{
    if (end > start)
    {
        size_t mid = start + (end - start) / 2;
        mergesort(lst, start, mid);
        mergesort(lst, mid + 1, end);
        merge(lst, start, mid, end);
    }
}
