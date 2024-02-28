#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * binary_tree_inorder - Goes through a binary tree using in-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	const binary_tree_t *current = tree;
	binary_tree_t *stack[1000];
	int top = -1;

	while (current != NULL || top != -1)
	{
		while (current != NULL)
		{
			stack[++top] = (binary_tree_t *)current;
			current = current->left;
		}

		current = stack[top--];
		func(current->n);
		current = current->right;
	}
}
