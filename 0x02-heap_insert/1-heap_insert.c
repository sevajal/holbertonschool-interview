#include "binary_trees.h"

/**
 * length - length of the binary tree.
 * @root: double pointer to the root.
 * Return: the length of the binary tree.
 */
int length(heap_t **root)
{
	if (!root || !*root)
		return (0);

	return (length(&((*root)->left)) + length(&((*root)->right)) + 1);
}

/**
 * find_parent - Get the parent node.
 * @root: the root node of the binary tree.
 * @i: the index.
 */
void find_parent(heap_t **root, int i)
{
	int parent = (i - 1) / 2;

	if (!root || i == 0)
		return;

	find_parent(root, parent);
	if (parent > 0 && parent % 2)
		(*root) = (*root)->left;
	if (parent > 0 && !(parent % 2))
		(*root) = (*root)->right;
}

/**
 * swap - swap nodes.
 * @a: a node.
 * @b: b node.
 */
void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}


/**
 * insert_to - insert a new node to the given parent.
 * @parent: the parent node.
 * @node: the node to insert into the binary tree-
 */
void insert_to(heap_t *parent, heap_t *node)
{
	if (!parent || node->n < parent->n)
		return;

	swap(&parent->n, &node->n);
	insert_to(node->parent, node);

	while (parent->parent && parent->parent->n < node->parent->n)
		swap(&parent->parent->n, &node->parent->n);
}

/**
 * heap_insert - insert a node into the max heap.
 * @root: the root node.
 * @value: the value to insert.
 * Return: the node inserted or null.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	heap_t *parent = *root;
	int index = length(root);

	if (!root)
		return (NULL);
	new_node = malloc(sizeof(heap_t));
	if (!new_node)
		return (NULL);
	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	find_parent(&parent, index);
	new_node->parent = parent;
	if (!parent->left)
		parent->left = new_node;
	else
		parent->right = new_node;
	insert_to(parent, new_node);
	return (new_node);
}
