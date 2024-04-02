#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree.
 *@tree: pointer to the node to measure the depth.
 * Return: if tree is NULL, function must return 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first node
 * @second: second node
 * Return: lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	size_t dep_f = binary_tree_depth(first), dep_s = binary_tree_depth(second);
	const binary_tree_t *tmp = NULL;

	if (dep_f && dep_s)
	{
	if (dep_f > dep_s)
	{
		tmp = first;
		first = second;
		second = tmp;
	}
	while (first)
	{
		tmp = second;
		while (tmp)
		{
			if (tmp == first)
				return ((binary_tree_t *)first);
			tmp = tmp->parent;
		}
		first = first->parent;
	}
	}
	else
		return (NULL);
	return (NULL);
}
