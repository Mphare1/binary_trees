#include "binary_trees.h"

/**
 * binary_tree_is_root - int function that checks if a 
 *                       node is a root of a binary tree.
 * @node: A pointer to the node
 *
 * Return: If node is a root - 1.
 *         Otherwise - 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
  
	if (node == NULL || node->parent != NULL)
		return (0);

	return (1);
}
