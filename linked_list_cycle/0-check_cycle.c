#include "lists.h"

/**
 * check_cycle - Checks if a singly linked list has a cycle.
 * @list: Pointer to the head of the linked list.
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list)
{
    listint_t *slow = list, *fast = list;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;         /* Move slow pointer one step */
        fast = fast->next->next;   /* Move fast pointer two steps */

        if (slow == fast)
            return (1);            /* Cycle detected */
    }

    return (0);                    /* No cycle */
}
