#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  performs a rigth-rotation on a binary tree
 * @tree: pointer to binare_tree_t
 * Return: pointer to the new root node of the tree once rotated;
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	if (tree && tree->left)
	{
		if (tree->parent)
		{
			if (tree == tree->parent->right)
				tree->parent->right = tree->left;
			else
				tree->parent->left = tree->left;
		}
		tree->left->parent = tree->parent;
		tree->parent = tree->left;
		tree->left = tree->parent->right;
		tree->parent->right = tree;
		return (tree->parent);
	}
	return (NULL);
}
