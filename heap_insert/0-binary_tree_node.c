#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"

/**
 * binary_tree_s - build a binary tree
 * @parent: parent node
 * @value: value to be assigned to the node
 * Description: Adds a new node
 * Return: new node
 */
struct binary_tree_s *binary_tree_node(struct binary_tree_s *parent, int value)
{
// Allocate memory
struct binary_tree_s *new_node = (struct binary_tree_s *)malloc(sizeof(struct binary_tree_s));
if (new_node == NULL) return NULL;

// Initialize node
new_node->n = value;
new_node->parent = parent;
new_node->left = NULL;
new_node->right = NULL;

return new_node;
}
