#include "binary_trees.h"

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: If tree is NULL or not perfect, 0.
 *         Otherwise, 1.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int left_height = 0, right_height = 0;
	const binary_tree_t *current = tree;

	while (current != NULL)
	{
		left_height++;
		current = current->left;
	}

	current = tree;

	while (current != NULL)
	{
		right_height++;
		current = current->right;
	}

	if (left_height == right_height)
		return (1);

	return (0);
}
