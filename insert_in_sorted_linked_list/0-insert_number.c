#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * instert_node - instert a node on a sorted linked list
 * @head: points to head
 * @number: value of node
 * Description: Add a node
 * Return: added node
 */
listint_t *insert_node(listint_t **head, int number)
{
    listint_t *searchNode = malloc(sizeof(listint_t));
    if (!searchNode){
        return NULL;
    }
    searchNode->n = number;
    searchNode->next = NULL;

    if (*head == NULL || (*head)->n >= number){
        searchNode->next = *head;
        *head = searchNode;
        return searchNode;
    }

    listint_t *current = *head;
    while (current->next != NULL && current->next->n < number)
    {
        current = current->next;
    }

    searchNode->next = current->next;
    current->next = searchNode;

    return searchNode;
}