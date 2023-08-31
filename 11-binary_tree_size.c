#include "binary_trees.h"

/**
 * binary_tree_size size of binary tree
 * @tree: A pointer to the root node
 *
 * Return: size of tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t sz = 0;

	if (tree)
	{
		sz += 1;
		sz += binary_tree_size(tree->left);
		sz += binary_tree_size(tree->right);
	}
	return (sz);
}
