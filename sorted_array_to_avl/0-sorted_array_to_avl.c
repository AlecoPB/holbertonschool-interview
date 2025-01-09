#include <stdlib.h>
#include "binary_trees.h"

/**
 * create_avl_node - Creates a new AVL tree node
 * @value: The value to store in the node
 * @parent: Pointer to the parent node
 * 
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_avl_node(int value, avl_t *parent) {
    avl_t *new_node = malloc(sizeof(avl_t));
    if (!new_node) {
        return NULL;
    }
    new_node->n = value;
    new_node->parent = parent;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/**
 * sorted_array_to_avl_helper - Helper function to build AVL tree recursively
 * @array: Pointer to the first element of the array
 * @start: Starting index of the subarray
 * @end: Ending index of the subarray
 * @parent: Pointer to the parent node
 * 
 * Return: Pointer to the root node of the AVL tree
 */
avl_t *sorted_array_to_avl_helper(int *array, int start, int end, avl_t *parent) {
    if (start > end) {
        return NULL;
    }

    int mid = start + (end - start) / 2;
    avl_t *node = create_avl_node(array[mid], parent);
    if (!node) {
        return NULL;
    }

    node->left = sorted_array_to_avl_helper(array, start, mid - 1, node);
    node->right = sorted_array_to_avl_helper(array, mid + 1, end, node);

    return node;
}

/**
 * sorted_array_to_avl - Converts a sorted array to an AVL tree
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 * 
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size) {
    if (array == NULL || size == 0) {
        return NULL;
    }
    return sorted_array_to_avl_helper(array, 0, size - 1, NULL);
}