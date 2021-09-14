#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * root: the root node of the heap
 *
 * Return: value of the root node, 0 upon failure
 **/
int heap_extract(heap_t** root)
{
	int res, height;
	heap_t* last;

	if (root == NULL)
		return (0);

	if (*root == NULL)
		return (0);

	res = (*root)->n;
	height = check_height(*root, 1);

	if (height == 1)
	{
		last = *root;
		*root = NULL;
	}
	else
	{
		last = get_last(*root, height, 1);

		(*root)->n = last->n;

		if (last->parent->right == last)
			last->parent->right = NULL;
		else
			last->parent->left = NULL;

		heapify(*root);
	}

	free(last);

	return (res);
}

/**
 * check_height - calculates the height of the heap
 * @node: node to start from
 * @height: known height of start
 *
 * Return: calculated height
 **/
int check_height(heap_t* node, int height)
{
	int l, r;

	if (node == NULL)
		return (height - 1);

	height++;

	l = check_height(node->left, height);
	r = check_height(node->right, height);

	if (l > r)
		return (l);
	else
		return (r);
}

/**
 * get_last - returns the last node using level order
 * @node: node to start from
 * @height: height of the heap
 * @node_height: known height of the starting node
 *
 * Return: last node in the heap
 **/
heap_t* get_last(heap_t* node, int height, int node_height)
{
	heap_t* tmp;

	if (node_height >= height - 1)
	{
		if (node->right != NULL)
			return (node->right);
		else
			return (node->left);
	}

	tmp = get_last(node->right, height, node_height + 1);

	if (tmp != NULL)
		return (tmp);

	return (get_last(node->left, height, node_height + 1));
}

/**
 * heapify - heapifies a heap
 * @node: node to start from
 **/
void heapify(heap_t* node)
{
	int tmp;
	heap_t* max = node;

	if (node->left != NULL && node->left->n >= max->n)
		max = node->left;

	if (node->right != NULL)
	{
		if (max == node->left && node->right->n > max->n)
			max = node->right;
		else if (node->right->n >= max->n)
			max = node->right;
	}

	if (max != node)
	{
		tmp = node->n;
		node->n = max->n;
		max->n = tmp;
		heapify(max);
	}
}