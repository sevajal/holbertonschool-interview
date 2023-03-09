#include "menger.h"
#include <stdio.h>
#include <math.h>

/**
 * menger - draws a 2D Menger Sponge.
 * @level: level of the Menger Sponge to draw.
 * Return: void
 */

void menger(int level)
{
	int size = pow(3, level), row, column, pound;
	int divisor = pow(3, 0), row_remain = 0, col_remain = 0;

	if (level < 0)
		return;
	if (level == 0)
		printf("#\n");
	if (level > 0)
	{
		for (row = 0; row < size; row++)
		{
			for (column = 0; column < size; column++)
			{
				pound = 1;
				for (divisor = 1; divisor < size; divisor *= 3)
				{
					row_remain = ((row / divisor) % 3) == 1;
					col_remain = ((column / divisor) % 3) == 1;
					if (row_remain && col_remain && pound)
						pound = 0;
				}
				if (pound)
					printf("#");
				else
					printf(" ");
			}
			printf("\n");
		}
	}
}
