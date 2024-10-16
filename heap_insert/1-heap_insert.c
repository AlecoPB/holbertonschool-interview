#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - Create a binary tree node
 * @parent: Parent node
 * @value: Value to be assigned to the node
 * 
 * Description: Adds a new node to the binary tree.
 * Return: Pointer to the new node, or NULL on failure.
 */
struct binary_tree_s *binary_tree_node(struct binary_tree_s *parent, int value)
{
/* Allocate memory for the new node*/
struct binary_tree_s *new_node = (struct binary_tree_s *)malloc(sizeof(struct binary_tree_s));
if (new_node == NULL) return NULL;

/* Initialize the new node*/
new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;
new_node->right = NULL;

return new_node;
}
