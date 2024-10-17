#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"
#include "0-binary_tree_node.c"

/**
 * swap_values - Swap the values between two heap nodes
 * @node1: The first node
 * @node2: The second node
 */
void swap_values(heap_t *node1, heap_t *node2)
{
    int temp = node1->n;
    node1->n = node2->n;
    node2->n = temp;
}

/**
 * bubble_up - Maintains the Max Heap property by bubbling up the node
 * @node: The node to bubble up
 */
void bubble_up(heap_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
}

/**
 * find_insertion_point - Find the correct insertion point using level-order traversal
 * @root: The root node of the heap
 *
 * Return: Pointer to the parent node where the new node should be inserted.
 */
heap_t *find_insertion_point(heap_t *root)
{
    heap_t *queue[1024];  // Queue for level-order traversal
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear)
    {
        heap_t *current = queue[front++];

        // Return the first node that has an available child spot
        if (!current->left || !current->right)
            return current;

        // Add children to the queue for traversal
        if (current->left)
            queue[rear++] = current->left;
        if (current->right)
            queue[rear++] = current->right;
    }

    return NULL;
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: The value to insert
 *
 * Return: Pointer to the newly inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (root == NULL)
        return NULL;

    // If the heap is empty, create the root node
    if (*root == NULL)
    {
        *root = binary_tree_node(NULL, value);
        return *root;
    }

    // Find the insertion point
    heap_t *parent = find_insertion_point(*root);

    // Create the new node and attach it as the left or right child
    heap_t *new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return NULL;

    if (parent->left == NULL)
        parent->left = new_node;
    else
        parent->right = new_node;

    // Bubble up to maintain the Max Heap property
    bubble_up(new_node);

    return new_node;
}
