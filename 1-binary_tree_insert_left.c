#include "binary_trees.h"

/*
 * binary_tree_t *binary_tree_insert_left - inserts a node as the left-child of a parent
 *
 * @parent: node parent
 * @value: node data
 *
 * Return: pointer to the created node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL || parent == NULL)
		return (NULL);

	new->n = value;
	new->right = NULL;
	new->parent = parent;
	new->left = parent->left;
	parent->left = new;

	return (new);
}
