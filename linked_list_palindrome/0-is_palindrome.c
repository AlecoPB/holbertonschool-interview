#include "lists.h"
#include <stdbool.h>


/**
 * reverse_list - reverse a linked list
 * @head: points to the head of the list
 * Description: Function that reverses a linked list
 * Returns: Reversed linked list
 */
listint_t *reverse_list(listint_t *head)
{
    listint_t *prev = NULL, *next = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

/**
 * is_palindrome - check if list is a palindrome
 * 
 */
int is_palindrome(listint_t **head)
{
    /* If empty, it's a palindrome */
    if (head == NULL || *head == NULL)
    {
        return (1);
    }

    /* Slow and fast pointer usage */
    listint_t *slow = *head, *fast = *head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
listint_t *second_half = reverse_list(slow);
listint_t *first_half = *head;
int t_palindrome = 1;
while (second_half != NULL)
{
    if (first_half->n != second_half->n)
    {
        t_palindrome = 0;
        break;
    }
    first_half = first_half->next;
    second_half = second_half->next;
}

return t_palindrome;

}