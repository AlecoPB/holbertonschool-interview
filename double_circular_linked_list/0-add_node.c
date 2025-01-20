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

new_node->next = new_node;
new_node->prev = new_node;

if (*list == NULL)
{
*list = new_node;
}
else
{
last = (*list)->prev;
last->next = new_node;
new_node->prev = last;
new_node->next = *list;
(*list)->prev = new_node;
}

return (new_node);
}

/**
 * add_node_begin - Adds a new node at the beginning
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

new_node->next = new_node;
new_node->prev = new_node;

if (*list == NULL)
{
*list = new_node;
}
else
{
new_node->next = *list;
new_node->prev = (*list)->prev;
(*list)->prev->next = new_node;
(*list)->prev = new_node;
}

*list = new_node;

return (new_node);
}
