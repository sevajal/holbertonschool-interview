#include "slide_line.h"

/**
 * slide_line - Slide and merge an array of integers to the left or right
 * @line: Pointer to an array of integers
 * @size: Size of the array
 * @direction: Direction to slide and merge the array (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	int i, j, k, last_merged;

	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	last_merged = 0;
	for (i = 0; i < (int)size; i++)
	{
		if (line[i] == 0)
			continue;
		if (last_merged)
			last_merged = 0;
		for (j = i + 1; j < (int)size; j++)
		{
			if (line[j] == 0)
				continue;
			if (line[j] != line[i])
				break;
			line[i] *= 2;
			line[j] = 0;
			last_merged = 1;
			break;
		}
	}
	if (direction == SLIDE_LEFT)
	{
		k = 0;
		for (i = 0; i < (int)size; i++)
		{
			if (line[i] == 0)
				continue;
			if (k != i)
			{
				line[k] = line[i];
				line[i] = 0;
			}
			k++;
			if (last_merged && k < (int)size)
				last_merged = 0;
		}
	}
	else
	{
		k = (int)size - 1;
		for (i = (int)size - 1; i >= 0; i--)
		{
			if (line[i] == 0)
				continue;
			if (k != i)
			{
				line[k] = line[i];
				line[i] = 0;
			}
			k--;
			if (last_merged && k >= 0)
				last_merged = 0;
		}
	}
	return (1);
}
