#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * heapify_down - Restores the Max Heap property by sifting a node down.
 * @node: Pointer to the current node.
 */
void heapify_down(heap_t *node)
{
heap_t *largest = node;
heap_t *left = node->left;
heap_t *right = node->right;

/* Find the largest value among the node, left, and right */
if (left && left->n > largest->n)
largest = left;
if (right && right->n > largest->n)
largest = right;

/* If the largest is not the current node, swap and continue */
if (largest != node)
{
int temp = node->n;
node->n = largest->n;
largest->n = temp;
heapify_down(largest);
}
}

/**
 * find_last_node - Finds the last node
 * @root: Pointer to the root of the heap.
 * Return: Pointer to the last node.
 */
heap_t *find_last_node(heap_t *root)
{
heap_t *current = root;
heap_t **queue = malloc(sizeof(heap_t *) * 1024);
size_t front = 0, rear = 0;

if (!queue)
return (NULL);

queue[rear++] = root;
while (front < rear)
{
current = queue[front++];
if (current->left)
queue[rear++] = current->left;
if (current->right)
queue[rear++] = current->right;
}
free(queue);
return (current);
}

/**
 * delete_last_node - Deletes the last node from the heap.
 * @root: Pointer to the root of the heap.
 * @last: Pointer to the last node.
 */
void delete_last_node(heap_t *root, heap_t *last)
{
heap_t *current = root;
heap_t **queue = malloc(sizeof(heap_t *) * 1024);
size_t front = 0, rear = 0;

if (!queue)
return;

queue[rear++] = root;
while (front < rear)
{
current = queue[front++];
if (current->left)
{
if (current->left == last)
{
free(last);
current->left = NULL;
break;
}
queue[rear++] = current->left;
}
if (current->right)
{
if (current->right == last)
{
free(last);
current->right = NULL;
break;
}
queue[rear++] = current->right;
}
}
free(queue);
}

/**
 * heap_extract - Extracts the root node from a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: Value of the root node or 0 on failure.
 */
int heap_extract(heap_t **root)
{
if (!root || !*root)
return (0);

heap_t *last = find_last_node(*root);
int value = (*root)->n;

if (last == *root) /* Single node case */
{
free(*root);
*root = NULL;
return (value);
}

/* Replace root with the last node's value */
(*root)->n = last->n;

/* Delete the last node and rebuild the heap */
delete_last_node(*root, last);
heapify_down(*root);

return (value);
}
