#include "binary_trees.h"

/*
 * binary_tree_t *binary_tree_insert_right - inserts a node as the right-child of a parent
 *
 * @parent: node parent
 * @value: node data
 *
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL || parent == NULL)
		return (NULL);

	new->n = value;
	new->left = NULL;
	new->parent = parent;
	new->right = parent->right;
	parent->right = new;

	return (new);
}
