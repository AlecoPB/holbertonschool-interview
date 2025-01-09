#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_node - Creates a new AVL tree node.
 * @parent: Pointer to the parent node.
 * @value: Value to store in the node.
 * Return: Pointer to the created node, or NULL on failure.
 */
avl_t *create_node(avl_t *parent, int value)
{
    avl_t *node = malloc(sizeof(avl_t));
    if (!node)
        return (NULL);

    node->n = value;
    node->parent = parent;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

/**
 * build_tree - Recursively builds the AVL tree.
 * @array: Pointer to the array of integers.
 * @start: Starting index of the current subarray.
 * @end: Ending index of the current subarray.
 * @parent: Pointer to the parent node.
 * Return: Pointer to the root of the subtree, or NULL on failure.
 */
avl_t *build_tree(int *array, int start, int end, avl_t *parent)
{
    if (start > end)
        return (NULL);

    int mid = (start + end) / 2;
    avl_t *node = create_node(parent, array[mid]);
    if (!node)
        return (NULL);

    node->left = build_tree(array, start, mid - 1, node);
    node->right = build_tree(array, mid + 1, end, node);

    return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array.
 * @array: Pointer to the first element of the array.
 * @size: Number of elements in the array.
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
    if (!array || size == 0)
        return (NULL);

    return (build_tree(array, 0, size - 1, NULL));
}
