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
 * heap_extract - Extracts the root node from a Max Binary Heap.
 * @root: Double pointer to the root node of the heap.
 * Return: Value of the root node or 0 on failure.
 */
int heap_extract(heap_t **root)
{
    if (!root || !*root)
        return 0;

    heap_t *current = *root, *last = NULL;
    int value = current->n;

    /* Find the last node using level-order traversal */
    size_t level = 0;
    heap_t **queue = malloc(sizeof(heap_t *) * 1024);
    size_t front = 0, rear = 0;
    if (!queue)
        return 0;

    queue[rear++] = *root;
    while (front < rear)
    {
        current = queue[front++];
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }
    last = current;

    /* Replace root node value with last node value */
    if (last == *root)
    {
        free(*root);
        *root = NULL;
        free(queue);
        return value;
    }

    (*root)->n = last->n;

    /* Remove the last node */
    current = *root;
    front = 0;
    rear = 0;
    queue[rear++] = *root;
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

    /* Rebuild the heap */
    heapify_down(*root);

    free(queue);
    return value;
}
