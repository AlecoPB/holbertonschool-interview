#include "binary_trees.h"

/**
 * swap_values - Swap the values of two nodes
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_values(binary_tree_t *a, binary_tree_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify_up - Adjusts the node upwards to maintain Max Heap property
 * @node: Pointer to the newly inserted node
 */
void heapify_up(binary_tree_t *node)
{
    while (node->parent && node->n > node->parent->n)
    {
        swap_values(node, node->parent);
        node = node->parent;
    }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the heap
 * @value: Value to be inserted
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    binary_tree_t **queue;
    binary_tree_t *node, *new_node;
    size_t front = 0, back = 0;

    if (!root)
        return (NULL);

    /* Create root node if tree is empty */
    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    /* Allocate memory for level-order traversal queue */
    queue = malloc(1024 * sizeof(binary_tree_t *));
    if (!queue)
        return (NULL);

    queue[back++] = *root;

    /* Perform level-order traversal to find insertion point */
    while (front < back)
    {
        node = queue[front++];

        /* Insert new node as left child if possible */
        if (!node->left)
        {
            new_node = binary_tree_node(node, value);
            node->left = new_node;
            heapify_up(new_node);
            free(queue);
            return (new_node);
        }
        queue[back++] = node->left;

        /* Insert new node as right child if possible */
        if (!node->right)
        {
            new_node = binary_tree_node(node, value);
            node->right = new_node;
            heapify_up(new_node);
            free(queue);
            return (new_node);
        }
        queue[back++] = node->right;
    }

    /* Cleanup and return NULL if insertion fails */
    free(queue);
    return (NULL);
}
