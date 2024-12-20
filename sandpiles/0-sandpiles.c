#include "sandpiles.h"

/**
 * is_stable - check stability
 * @grid: grid (3x3 by default)
 * Description: Function to check if a sandpile is stable
 * Return: bool indicating stability
 */
static bool is_stable(int grid[3][3])
{
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
{
return (false);
}
}
}
return (true);
}

/**
 * print_grid - print grid
 * @grid: grid (3x3 by default)
 * Description: Function to print a grid
 * Return: void
 */
static void print_grid(int grid[3][3])
{
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (j != 0)
{
printf(" ");
}
printf("%d", grid[i][j]);
}
printf("\n");
}
}

/**
 * topple - topple sandpile
 * @grid: grid (3x3 by default)
 * Description: Function to topple sandpile
 * Return: void
 */
static void topple(int grid[3][3])
{
int temp[3][3] = {0};

for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
{
temp[i][j] -= 4;
if (i > 0)
temp[i - 1][j]++;
if (i < 2)
temp[i + 1][j]++;
if (j > 0)
temp[i][j - 1]++;
if (j < 2)
temp[i][j + 1]++;
}
}
}

/* Update the grid */
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
grid[i][j] += temp[i][j];
}
}
}

/**
 * sandpiles_sum - sum two sandpiles
 * @grid1: grid (3x3 by default)
 * @grid2: grid (3x3 by default)
 * Description: Function to sum two sandpiles
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
/* Add the two grids */
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
grid1[i][j] += grid2[i][j];
}
}

/* Topple the sandpile until it is stable */
while (!is_stable(grid1))
{
printf("=\n");
print_grid(grid1);
topple(grid1);
}
}
