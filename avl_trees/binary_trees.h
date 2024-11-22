#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>

/* Basic Binary Tree Structure */
typedef struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
} binary_tree_t;

typedef struct binary_tree_s avl_t;

/* Function Prototype */
int binary_tree_is_avl(const binary_tree_t *tree);

#endif /* BINARY_TREES_H */
