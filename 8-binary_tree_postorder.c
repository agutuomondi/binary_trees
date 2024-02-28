#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	const binary_tree_t *stack1[1000];
	const binary_tree_t *stack2[1000];

	int top1 = -1, top2 = -1;

	stack1[++top1] = tree;

	while (top1 != -1)
	{
		const binary_tree_t *node = stack1[top1--];

		stack2[++top2] = node;

		if (node->left)
			stack1[++top1] = node->left;
		if (node->right)
			stack1[++top1] = node->right;
	}

	while (top2 != -1)
	{
		const binary_tree_t *node = stack2[top2--];

		func(node->n);
	}
}

