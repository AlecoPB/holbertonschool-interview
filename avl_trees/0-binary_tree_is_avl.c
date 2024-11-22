#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>

/* Helper function to get the height of a tree */
int get_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return -1;  /* height of NULL tree is -1 */
    
    int left_height = get_height(tree->left);
    int right_height = get_height(tree->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

/* Helper function to check if a binary tree is a BST */
int is_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return 1;

    /* Node value must be within min and max constraints */
    if (tree->n <= min || tree->n >= max)
        return 0;

    /* Recursively check left and right subtrees */
    return is_bst(tree->left, min, tree->n) &&
           is_bst(tree->right, tree->n, max);
}

/* Helper function to check if a binary tree is balanced (AVL) */
int is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 1;

    /* Check height difference */
    int left_height = get_height(tree->left);
    int right_height = get_height(tree->right);

    if (abs(left_height - right_height) > 1)
        return 0;

    /* Recursively check if left and right subtrees are AVL */
    return is_avl(tree->left) && is_avl(tree->right);
}

/* Main function to check if a binary tree is a valid AVL Tree */
int binary_tree_is_avl(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    /* Check if the tree is both a BST and balanced (AVL) */
    if (!is_bst(tree, INT_MIN, INT_MAX))
        return 0;

    if (!is_avl(tree))
        return 0;

    return 1;
}
