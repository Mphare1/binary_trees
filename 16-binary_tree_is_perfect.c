#include "binary_trees.h"

/**
 * binary_tree_height - Calculate the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 * Return: The height of the tree.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t left_height = binary_tree_height(tree->left);
	size_t right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_is_perfect - Check if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree.
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = binary_tree_height(tree);
	int result = 1;

	if (tree == NULL)
		return (0);

	/* Helper function to perform level-order traversal */
	void level_order(const binary_tree_t *node, size_t current_level)
	{
		if (node == NULL)
			return;

		if (current_level == height - 1 && (node->left || node->right))
		{
			result = 0;
			return;
		}

		level_order(node->left, current_level + 1);
		level_order(node->right, current_level + 1);
	}

	level_order(tree, 0);

	return result;
}
