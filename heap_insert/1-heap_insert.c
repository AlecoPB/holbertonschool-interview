#include "binary_trees.h"

/**
 * binary_tree_node - Create a new binary tree node
 * @parent: Pointer to the parent node
 * @value: Value to be stored in the new node
 * Return: Pointer to the new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
    binary_tree_t *new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t));
    if (!new_node)
        return (NULL);

    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

/**
 * swap_values - Swap the values of two nodes
 * @a: First node
 * @b: Second node
 */
void swap_values(binary_tree_t *a, binary_tree_t *b)
{
    int temp = a->n;
    a->n = b->n;
    b->n = temp;
}

/**
 * heapify_up - Ensure the Max Heap property by "bubbling up" the inserted node
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
 * heap_insert - Insert a new value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the new node
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
    if (!root)
        return (NULL);

    /* If root is NULL, create the root node */
    if (!*root)
    {
        *root = binary_tree_node(NULL, value);
        return (*root);
    }

    /* Use a queue for level-order traversal to find the insertion point */
    binary_tree_t **queue = malloc(1024 * sizeof(binary_tree_t *));
    if (!queue)
        return (NULL);

    size_t front = 0, back = 0;
    queue[back++] = *root;

    while (front < back)
    {
        binary_tree_t *node = queue[front++];

        /* Try inserting as the left child */
        if (!node->left)
        {
            node->left = binary_tree_node(node, value);
            free(queue);
            heapify_up(node->left);
            return (node->left);
        }
        queue[back++] = node->left;

        /* Try inserting as the right child */
        if (!node->right)
        {
            node->right = binary_tree_node(node, value);
            free(queue);
            heapify_up(node->right);
            return (node->right);
        }
        queue[back++] = node->right;
    }

    free(queue);
    return (NULL); /* Should not reach here */
}
