#include "binary_trees.h"

/**
 * binary_tree_height - height of a binary tree.
 * @tree: A pointer
 *
 * Return: If tree  NULL return 0, else return height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree)
    {
        size_t x = 0, y = 0;
        if (tree->left)
        {
            x = 1 + binary_tree_height(tree->left);
        }
        if (tree->right)
        {
            y = 1 + binary_tree_height(tree->right);
        }
        return (x > y) ? x : y;
    }
    return 0;
}
