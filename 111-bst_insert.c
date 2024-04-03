#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 *
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node, or NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *ptr = *tree;

	if (tree == NULL)
	{
		bst_t *new = binary_tree_node(ptr, value);

		return (new);
	}
	else
	{
		if (value > ptr->n)
			bst_insert(&ptr->right, value);
		else
			bst_insert(&ptr->left, value);
	}
}
