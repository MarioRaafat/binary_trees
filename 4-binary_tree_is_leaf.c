#include "binary_trees.h"

/**
 * int binary_tree_is_leaf - function that checks if a node is a leaf
 *
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL || node->left != NULL || node->right != NULL)
		return (0);

	return (1);
}
