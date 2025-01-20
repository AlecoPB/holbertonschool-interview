#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * add_node_end - Adds a new node at the end of a doubly circular linked list
 * @list: Double pointer to the list to modify
 * @str: The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
    List *new_node;
    List *last;

    if (str == NULL)
        return (NULL);

    new_node = malloc(sizeof(List));
    if (new_node == NULL)
        return (NULL);

    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->next = new_node; // Point to itself
    new_node->prev = new_node; // Point to itself

    if (*list == NULL)
    {
        *list = new_node; // If the list is empty, set the new node as the head
    }
    else
    {
        last = (*list)->prev; // Get the last node
        last->next = new_node; // Link the last node to the new node
        new_node->prev = last; // Link the new node back to the last node
        new_node->next = *list; // Link the new node to the head
        (*list)->prev = new_node; // Link the head back to the new node
    }

    return (new_node);
}

/**
 * add_node_begin - Adds a new node at the beginning of a doubly circular linked list
 * @list: Double pointer to the list to modify
 * @str: The string to copy into the new node
 *
 * Return: Address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
    List *new_node;

    if (str == NULL)
        return (NULL);

    new_node = malloc(sizeof(List));
    if (new_node == NULL)
        return (NULL);

    new_node->str = strdup(str);
    if (new_node->str == NULL)
    {
        free(new_node);
        return (NULL);
    }

    new_node->next = new_node; // Point to itself
    new_node->prev = new_node; // Point to itself

    if (*list == NULL)
    {
        *list = new_node; // If the list is empty, set the new node as the head
    }
    else
    {
        new_node->next = *list; // Link the new node to the head
        new_node->prev = (*list)->prev; // Link the new node to the last node
        (*list)->prev->next = new_node; // Link the last node to the new node
        (*list)->prev = new_node; // Link the head back to the new node
    }

    *list = new_node; // Set the new node as the head

    return (new_node);
}
