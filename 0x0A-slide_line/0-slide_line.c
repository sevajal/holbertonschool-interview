#include "slide_line.h"

/**
 * slide_left - Given an lineay of integers, we want to be able to slide
 * & merge it to the left.
 * @line: Pointer to an lineay of integer containing size elements.
 * @size: The size of the lineay.
 * Return: 1 if success or 0 if failure.
 */

int slide_left(int *line, size_t size)
{
	size_t i, j, k;
    /* Slide non-zero elements to the left */
	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
			line[j++] = line[i];
	}
	/* Merge contiguous or separated identical numbers */
	for (i = 0; i < j; i = k)
	{
		k = i + 1;
		while (k < j && line[k] == line[i])
		{
			line[i] *= 2;
			line[k++] = 0;
		}
	}
	/* Slide merged elements to the left */
	for (i = 0, j = 0; i < j || j < size; )
	{
		while (i < size && line[i] == 0)
			i++;
		while (j < size && line[j] != 0)
			j++;
		if (i < j && j < size)
			line[i++] = line[j++];
	}
	/* Fill the rest with zeros */
	while (i < size)
		line[i++] = 0;
	return (1);
}

/**
 * slide_right - Given an lineay of integers, we want to be able to slide
 * & merge it to the right.
 * @line: Pointer to an lineay of integer containing size elements.
 * @size: The size of the lineay.
 * Return: 1 if success or 0 if failure.
 */

int slide_right(int *line, size_t size)
{
	size_t i, j, k;
    /* Slide non-zero elements to the right */
	for (i = size - 1, j = size - 1; i < size; i--)
	{
		if (line[i] != 0)
			line[j--] = line[i];
	}
	/* Merge contiguous or separated identical numbers */
	for (i = size - 1; i < size; i = k)
	{
		k = i - 1;
		while (line[k] == line[i])
		{
			line[i] *= 2;
			line[k--] = 0;
		}
	}
	/* Slide merged elements to the right */
	for (i = size - 1, j = size - 1; i > j; )
	{
		while (line[i] == 0)
			i--;
		while (line[j] != 0)
			j--;
		if (i > j)
			line[j--] = line[i--];
	}
	/* Fill the rest with zeros */
	while (j < i)
		line[j--] = 0;
	return (1);
}

/**
 * slide_line - Given an lineay of integers, we want to be able to slide
 * & merge it to the left or to the right.
 * @line: Pointer to an lineay of integer containing size elements.
 * @size: The size of the lineay.
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 if success or 0 if failure.
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_RIGHT || direction != SLIDE_LEFT)
		return (0);
	if (direction == SLIDE_RIGHT)
		return (slide_right(line, size));
	return (slide_left(line, size));
}
