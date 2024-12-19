#include "sandpiles.h"

/**
 * sandpiles_sum - Computes the sum of two sandpiles.
 * @grid1: The first 3x3 grid.
 * @grid2: The second 3x3 grid.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    // Add grid2 to grid1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Stabilize grid1
    while (!is_stable(grid1)) {
        printf("=\n");
        print_grid(grid1);
        topple(grid1);
    }
}

/**
 * print_grid - Prints a 3x3 grid.
 * @grid: The grid to print.
 */
void print_grid(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (j > 0) {
                printf(" ");
            }
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * is_stable - Checks if a sandpile grid is stable.
 * @grid: The grid to check.
 * Return: true if stable, false otherwise.
 */
bool is_stable(int grid[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                return false;
            }
        }
    }
    return true;
}

/**
 * topple - Topples a sandpile grid to stabilize it.
 * @grid: The grid to topple.
 */
void topple(int grid[3][3]) {
    int temp[3][3] = {0};

    // Calculate topple effects
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i][j] > 3) {
                temp[i][j] -= 4;
                if (i > 0) temp[i - 1][j] += 1;  // Top neighbor
                if (i < 2) temp[i + 1][j] += 1;  // Bottom neighbor
                if (j > 0) temp[i][j - 1] += 1;  // Left neighbor
                if (j < 2) temp[i][j + 1] += 1;  // Right neighbor
            }
        }
    }

    // Apply topple effects to the grid
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            grid[i][j] += temp[i][j];
        }
    }
}
