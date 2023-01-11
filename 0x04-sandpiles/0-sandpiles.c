#include "sandpiles.h"
#include <stddef.h>


/**
 * print_grid2 - Print 3x3 grid
 * @grid: 3x3 grid
 */

void print_grid2(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * stable_sandpile - Define if a sandpile is stable.
 * @grid: grid.
 * Return: 1 if stable, 0 if not.
 */

int stable_sandpile(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * toppling - toppling a sandpile
 * @grid: grid
 */

void toppling(int grid[3][3])
{
	int i, j;
	int grid2[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid2[i][j] = grid[i][j];
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid2[i][j] > 3)
			{
				grid[i][j] = grid[i][j] - 4;
				if (i == 0)
					grid[i + 1][j] = grid[i + 1][j] + 1;
				if (i == 1)
				{
					grid[i - 1][j] = grid[i - 1][j] + 1;
					grid[i + 1][j] = grid[i + 1][j] + 1;
				}
				if (i == 2)
					grid[i - 1][j] = grid[i - 1][j] + 1;
				if (j == 0)
					grid[i][j + 1] = grid[i][j + 1] + 1;
				if (j == 1)
				{
					grid[i][j + 1] = grid[i][j + 1] + 1;
					grid[i][j - 1] = grid[i][j - 1] + 1;
				}
				if (j == 2)
					grid[i][j - 1] = grid[i][j - 1] + 1;
			}
		}
	}
}

/**
 * sandpiles_sum - function that computes the sum of two sandpiles.
 * @grid1: stable grid 1.
 * @grid2: stable grid 2.
 * Result: Void
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
		}
	}
	while (stable_sandpile(grid1) == 0)
	{
		printf("=\n");
		print_grid2(grid1);
		toppling(grid1);
	}
}
