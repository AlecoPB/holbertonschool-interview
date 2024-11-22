#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>

/**
 * get_height - find tree height
 * @tree: points to tree
 * Description: Find the height of a tree
 * Return: height
 */
int get_height(const binary_tree_t *tree)
{
if (tree == NULL)
return (-1);  /* height of NULL tree is -1 */

int left_height = get_height(tree->left);
int right_height = get_height(tree->right);

return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * is_bst - check if tree is bst
 * @tree: points to head
 * @min: min value
 * @max: max value
 * Description: Check if a tree is bst
 * Return: true or false
 */
int is_bst(const binary_tree_t *tree, int min, int max)
{
if (tree == NULL)
return (1);

/* Node value must be within min and max constraints */
if (tree->n <= min || tree->n >= max)
return (0);

/* Recursively check left and right subtrees */
return (is_bst(tree->left, min, tree->n) &&
is_bst(tree->right, tree->n, max));
}

/**
 * is_avl - check if tree is avl
 * @tree: points to head
 * Description: Check if a tree is avl
 * Return: 1 if avl
 */
int is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (1);

/* Check height difference */
int left_height = get_height(tree->left);
int right_height = get_height(tree->right);

if (abs(left_height - right_height) > 1)
return (0);

/* Recursively check if left and right subtrees are AVL */
return (is_avl(tree->left) && is_avl(tree->right));
}

/**
 * binary_tree_is_avl - main function to check if avl
 * @tree: points to head
 * Description: Check if a tree is valid and avl
 * Return: 1 if avl, 0 if not or invalid
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

/* Check if the tree is both a BST and balanced (AVL) */
if (!is_bst(tree, INT_MIN, INT_MAX))
return (0);

if (!is_avl(tree))
return (0);

return (1);
}
