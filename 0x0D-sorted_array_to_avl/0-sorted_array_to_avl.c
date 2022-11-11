#include "binary_trees.h"

/**
 * create_node - Create a node
 * @parent: Pointer to parent tree
 * @value: Value to insert
 *
 * Return: A new node
 */
avl_t *create_node(avl_t *parent, int value)
{
	avl_t *node = NULL;

	node = malloc(sizeof(avl_t));
	if (node == NULL)
	{
		fprintf(stderr, "Can't malloc\n");
		exit(1);
	}
	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

/**
 * insert_node - Insert a new node recursively
 * @root: Pointer to root of tree
 * @start: Array start value
 * @end: Array end value
 * @array: array with values to insert
 *
 * return: Nothing
 */
void insert_node(avl_t **root, int start, int end, int *array)
{
	avl_t *node = NULL;
	int mid = 0;

	if (end - start > 1)
	{
		mid = (end - start) / 2 + start;
		node = create_node((*root), array[mid]);
		if (array[mid] > (*root)->n)
			(*root)->right = node;
		else if (array[mid] < (*root)->n)
			(*root)->left = node;
		insert_node(&node, start, mid, array);
		insert_node(&node, mid, end, array);
	}
}

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: Is a pointer to the first element of the array to be converted
 * @size: Is the number of element in the array
 *
 * Return: A pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int mid = (size - 1) / 2;

	if (!array)
		return (NULL);
	root = create_node(NULL, array[mid]);
	insert_node(&root, -1, mid, array);
	insert_node(&root, mid, size, array);
	return (root);
}
