#include "binary_trees.h"

/**
 * binary_tree_node  - function that creates a binary tree node
 *
 * @parent: node parent
 * @value: node data
 *
 * Return: new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = new->right = NULL;

	return (new);
}
