#include "mergesort.h"

void merge(list *lst, size_t start, size_t mid, size_t end)
{

    // If the direct merge is already sorted
    if (list_compare_items(lst, mid, mid + 1) <= 0)
    {
        return;
    }

    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && mid + 1 <= end)
    {

        // If element 1 is in right place
        if (list_compare_items(lst, start, mid + 1) <= 0)
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
