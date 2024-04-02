#include "binary_trees.h"

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 *
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 if tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (tree)
	{
		leaves += ((tree->left && !tree->right) || (!tree->left && tree->right)) ? 1 : 0;
		leaves += binary_tree_is_full(tree->left);
		leaves += binary_tree_is_full(tree->right);
	}
	else
		return (0);

	return ((leaves > 0) ? 0 : 1);
}
