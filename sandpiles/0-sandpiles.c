#include "sandpiles.h"

/* Function to check if a sandpile is stable */
static bool is_stable(int grid[3][3])
{
for (int i = 0; i < 3; i++)
{
for (int j = 0; j < 3; j++)
{
if (grid[i][j] > 3)
{
return false;
}
}
}
return true;
}

/* Function to print a 3x3 grid */
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

/* Function to topple the sandpile */
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
if (i > 0) temp[i - 1][j]++;
if (i < 2) temp[i + 1][j]++;
if (j > 0) temp[i][j - 1]++;
if (j < 2) temp[i][j + 1]++;
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

/* Function to sum two sandpiles */
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
