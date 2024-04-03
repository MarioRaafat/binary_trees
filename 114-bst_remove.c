#include "binary_trees.h"

/**
 * min - return the minimum val in the sub tree.
 *
 * Return: min node.
 */
bst_t *min(bst_t *node)
{
	if (node->left == NULL)
		return (node);
	return (min(node->left));
}

/**
 * rec_bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
void rec_bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return;
	if (root->n < value)
		rec_bst_remove(root->right, value);
	else if (root->n > value)
		rec_bst_remove(root->left, value);

	if (root->left == NULL && root->right == NULL)
	{
		if (root == root->parent->left)
			root->parent->left = NULL;
		else
			root->parent->right = NULL;
		free(root);
	}
	else if (root->left != NULL && root->right == NULL)
	{
		if (root == root->parent->left)
			root->parent->left = root->left;
		else
			root->parent->right = root->left;
		free(root);
	}
	else if (root->left == NULL && root->right != NULL)
	{
		if (root == root->parent->left)
			root->parent->left = root->right;
		else
			root->parent->right = root->right;
		free(root);
	}
	else
	{
		bst_t *Min = min(root->left);

		root->n = Min->n;
		if (Min->right)
		{
			bst_t *del = Min->right;

			Min->n = Min->right->n;
			Min->left = Min->right->left;
			Min->right = Min->right->right;

			free(del);
		}
		else
		{
			Min->left = Min->right = NULL;
			free(Min);
		}
	}

}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	rec_bst_remove(root, value);
	return (root);
}
