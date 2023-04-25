#include "sort.h"
/**
 * heapify - function to create subtree rooted with node i
 * @array: array to sort
 * @j: an aux of size
 * @i: reference to the nodes
 * @n: size of the array
 * Return: nothing
 */

void heapify(int *array, int j, int i, size_t n)
{
	int largest = i, aux = 0;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < j && array[left] > array[largest])

		largest = left;
	if (right < j && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		aux = array[i];
		array[i] = array[largest];
		array[largest] = aux;
		print_array(array, n);
		heapify(array, j, largest, n);
	}
}
/**
 * heap_sort - Function to do heap sort
 * @array: array to sort
 * @size: size of the array
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int i, aux = 0;
	size_t j = size;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, j, i,  size);

	for (i = j - 1; i >= 1; i--)
	{
		aux = array[0];
		array[0] = array[i];
		array[i] = aux;
		print_array(array, size);
		heapify(array, i, 0, size);
	}
}
