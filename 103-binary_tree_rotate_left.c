#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	if (!tree || !tree->right)
		return NULL;
	binary_tree_t *pivot = tree->right;
	tree->right = pivot->left;
	if (pivot->left)
		pivot->left->parent = tree;
	pivot->left = tree;
	pivot->parent = tree->parent;
	tree->parent = pivot;

	if (pivot->parent)
	{
		if (pivot->parent->left == tree)
			pivot->parent->left = pivot;
		else
			pivot->parent->right = pivot;
	}

	return pivot;
}
