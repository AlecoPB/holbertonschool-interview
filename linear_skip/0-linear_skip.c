#include "search.h"

/**
 * linear_skip - Searches for a value in a sorted skip list of integers.
 * @list: Pointer to the head of the skip list.
 * @value: Value to search for.
 * Return: Pointer to the first node where value is located, or NULL if not found.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
    skiplist_t *prev = NULL, *curr = NULL;

    if (!list)
        return (NULL);

    curr = list;
    while (curr->express)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr->express->index, curr->express->n);
        if (curr->express->n >= value)
            break;
        prev = curr;
        curr = curr->express;
    }

    if (!curr->express) /* If end of express lane, set prev to curr */
    {
        prev = curr;
        while (curr->next)
            curr = curr->next;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev->index, curr->index);

    /* Perform linear search in the range */
    curr = prev;
    while (curr)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr->index, curr->n);
        if (curr->n == value)
            return (curr);
        if (curr->n > value)
            break;
        curr = curr->next;
    }

    return (NULL);
}
