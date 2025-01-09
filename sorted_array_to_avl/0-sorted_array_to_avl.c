#include "binary_trees.h"

/**
 * create_node - Creates a new AVL tree node
 *
 * @parent: Pointer to the parent node of the new node
 * @value: Integer value to be stored in the node
 *
 * Return: Pointer to the new node, or NULL on failure
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node = malloc(sizeof(avl_t));

	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * build_avl_tree - Recursive helper function to build the AVL tree
 *
 * @array: Pointer to the first element of the array
 * @start: Starting index of the sub-array
 * @end: Ending index of the sub-array
 * @parent: Pointer to the parent node
 *
 * Return: Pointer to the root node of the tree, or NULL on failure
 */
avl_t *build_avl_tree(int *array, size_t start, size_t end, avl_t *parent)
{
	if (array == NULL || start > end)
		return (NULL);

	/* Find the middle index and create a node containing the middle value */
	size_t mid = (start + end) / 2;
	avl_t *root = create_node(parent, array[mid]);

	if (root == NULL)
		return (NULL);

	/* Avoid unsigned underflow */
	if (mid > start)
		root->left = build_avl_tree(array, start, mid - 1, root);
	if (mid < end)
		root->right = build_avl_tree(array, mid + 1, end, root);

	return (root);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 *
 * @array: Pointer to the first element of the array
 * @size: Number of elements in the array
 *
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);

	return (build_avl_tree(array, 0, size - 1, NULL));
}