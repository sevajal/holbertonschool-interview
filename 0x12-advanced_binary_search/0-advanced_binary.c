#include "search_algos.h"

/**
 * print_array - print the array
 * @array: Array to make search
 * @start: Position to start printing
 * @end: Position to end printing
 * Return: void
 */
void print_array(int *array, int start, int end)
{
	int i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		if (i != start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}

/**
 * binary_search - binary search
 * @array: pointer to first element of array
 * @start: first index in array
 * @end: last index in array
 * @value: value tu search for.
 * Return: printed sorted array or -1
 */
int binary_search(int *array, int start, int end, int value)
{
	int middle;

	middle = (start + end) / 2;
	if (start > end)
		return (-1);
	print_array(array, start, end);
	if (array[middle] < value)
		return (binary_search(array, middle + 1, end, value));
	if (array[middle] >= value)
		end = middle;
	if (array[start] == value && start == middle)
		return (start);
	return (binary_search(array, start, end, value));
}

/**
 * advanced_binary - searches for a value in a sorted array of integers.
 * @array: pointer to the first element of the array to search in.
 * @size: number of elements in the array
 * @value: value to search for
 * Return: index where value is located, if no value or NULL, return -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	int start = 0;
	int end = size - 1;

	if (!array || size == 0)
		return (-1);

	return (binary_search(array, start, end, value));
}
