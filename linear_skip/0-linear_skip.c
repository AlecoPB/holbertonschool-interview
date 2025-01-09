#include "search.h"
#include <math.h>

/**
 * linear_skip - Searches for a value in a sorted skip list
 * @head: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located, or NULL if not found
 */
skiplist_t *linear_skip(skiplist_t *head, int value)
{
    skiplist_t *current = head;
    skiplist_t *express = head;

    if (!head)
        return NULL;

    // Calculate the step size (sqrt of the list size)
    size_t step = 0;
    while (express)
    {
        // Print the value being compared
        printf("Value checked at index [%lu] = [%d]\n", express->index, express->n);
        
        // If we found the value
        if (express->n == value)
            return express;

        // If the next express node is greater than the value, we need to search linearly
        if (express->n >= value || !express->express)
            break;

        // Move to the next express node
        express = express->express;
    }

    // Now we need to search linearly in the block
    current = express->next; // Start from the next node after the express node
    printf("Value found between indexes [%lu] and [%lu]\n", express->index, express->next ? express->next->index : express->index);

    while (current)
    {
        // Print the value being compared
        printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);
        
        if (current->n == value)
            return current;

        // If we exceed the value, we can stop
        if (current->n > value)
            break;

        current = current->next;
    }

    // If we reach here, the value was not found
    return NULL;
}
