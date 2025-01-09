#include <stdlib.h>
#include <stddef.h>

// Define the structure of the AVL tree node
typedef struct avl_s {
    int value;
    struct avl_s *left;
    struct avl_s *right;
} avl_t;

/**
 * Creates a new AVL node with the given value.
 * Returns a pointer to the new node, or NULL on failure.
 */
avl_t *create_node(int value) {
    avl_t *node = malloc(sizeof(avl_t));
    if (!node)
        return NULL;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/**
 * Helper function to recursively build the AVL tree from the sorted array.
 * Returns a pointer to the root node of the subtree.
 */
avl_t *build_tree(int *array, size_t start, size_t end) {
    if (start > end)
        return NULL;

    size_t mid = start + (end - start) / 2; // Calculate the middle index
    avl_t *node = create_node(array[mid]); // Create a node for the middle element
    if (!node)
        return NULL;

    // Recursively build the left and right subtrees
    node->left = build_tree(array, start, mid - 1);
    node->right = build_tree(array, mid + 1, end);

    return node;
}

/**
 * Converts a sorted array to an AVL tree.
 * @param array: Pointer to the first element of the array to be converted
 * @param size: Number of elements in the array
 * @return Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size) {
    if (!array || size == 0)
        return NULL;
    return build_tree(array, 0, size - 1);
}
