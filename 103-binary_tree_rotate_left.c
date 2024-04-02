#include "binary_trees.h"

/**
 * binary_tree_rotate_left -  performs a left-rotation on a binary tree
 * @tree: pointer to binare_tree_t
 * Return: pointer to the new root node of the tree once rotated;
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (tree && tree->right)
	{
		if (tree->parent != NULL)
			if (tree == tree->parent->right)
				tree->parent->right = tree->right;
			else
				tree->parent->right = tree->right;

		tree->right->parent = tree->parent;
		tree->parent = tree->right;
		tree->right = tree->parent->left;
		tree->parent->left = tree;
		return (tree->parent);
	}
	return (NULL);
}
