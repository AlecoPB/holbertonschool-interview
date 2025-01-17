#!/usr/bin/python3
"""
This is some documentation
"""


def island_perimeter(grid):
    """island perimeter

    Args:
        grid: a grid representing the island
    """
    if not grid:
        return 0

    perimeter = 0
    rows = len(grid)
    cols = len(grid[0])

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:  # If the cell is land
                # Check the four sides
                # Up
                if i == 0 or grid[i - 1][j] == 0:
                    perimeter += 1
                # Down
                if i == rows - 1 or grid[i + 1][j] == 0:
                    perimeter += 1
                # Left
                if j == 0 or grid[i][j - 1] == 0:
                    perimeter += 1
                # Right
                if j == cols - 1 or grid[i][j + 1] == 0:
                    perimeter += 1

    return perimeter
