#include "binary_trees.h"

/**
 * binary_tree_is_bst - check if ist a correctly bst tree
 * @tree: tre to check
 * Return: 1 if is bst 0 if not
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->right == NULL)
	{
		if (tree->left == NULL)
			return (1);
		return (binary_tree_is_bst(tree->left));
	}
	else
	{
		if (tree->left == NULL)
			return (binary_tree_is_bst(tree->right));
		if (tree->right->n > tree->left->n)
			return (binary_tree_is_bst(tree->right) && binary_tree_is_bst(tree->left));
		return (0);
	}
}
