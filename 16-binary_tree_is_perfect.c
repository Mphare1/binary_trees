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
    if (tree == NULL)
        return (0);

    /* Calculate the height of the left and right subtrees */
    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    /* Check if it's a leaf node (perfect by definition) */
    if (tree->left == NULL && tree->right == NULL)
        return (1);

    /* Check if internal node has two children and their heights match */
    if (tree->left != NULL && tree->right != NULL &&
        left_height == right_height)
    {
        /* Recursively check left and right subtrees */
        int left_perfect = binary_tree_is_perfect(tree->left);
        int right_perfect = binary_tree_is_perfect(tree->right);

        return (left_perfect && right_perfect);
    }

    return (0); /* Not perfect if any condition fails */
}
