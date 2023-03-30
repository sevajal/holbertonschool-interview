#include "binary_trees.h"

/**
 * avl - builds an AVL tree recursively
 * @array: pointer to the first element of the array
 * @start: starting index of the array
 * @end: ending index of the array
 * @parent: pointer to the parent node.
 * Return: pointer to the root or null.
 */
avl_t *avl(int *array, int start, int end, avl_t *parent)
{
	int middle;
	avl_t *root;

	if (start > end)
		return (NULL);

	middle = (start + end) / 2;
	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);
	root->n = array[middle];
	root->parent = parent;
	root->left = avl(array, start, middle - 1, root);
	root->right = avl(array, middle + 1, end, root);
	return (root);
}


/**
 * sorted_array_to_avl - builds an AVL tree from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: number of elements in an array.
 * Return: pointer to the root of the created AVL tree, or NULL on failure.
 */

avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (avl(array, 0, size - 1, NULL));
}
