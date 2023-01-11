#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void print_grid2(int grid[3][3]);
int stable_sandpile(int grid[3][3]);
void toppling(int grid[3][3]);

#endif
