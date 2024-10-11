#include "lists.h"

listint_t *find_listint_loop(listint_t *head)
/**
 * find_listing_loop - find loop
 * @head: points to head
 * Description: Find a loop on a single linked list
 * Return: node of looping
 */
{
listint_t *slow = head, *fast = head;

while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;

/* If the slow pointer meets the fast pointer, there is a loop*/
if (slow == fast)
{
slow = head;

/* Move both pointers one step at a time*/
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
/* Return the node where the loop starts*/
return (slow);
}
}
/* No loop found*/
return (NULL);
}
