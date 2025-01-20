#!/usr/bin/python3
"""
This is some documentation
"""


def pascal_triangle(n):
    """pascal triangle

    n (int): int to build the triangle
    return: list representing a pascal triangle
    """
    if n <= 0:
        return []

    triangle = []

    for i in range(n):
        # Create a new row with `i + 1` elements initialized to 0
        row = [0] * (i + 1)
        row[0] = 1  # The first element is always 1
        row[-1] = 1  # The last element is always 1

        # Fill in the values for the current row
        for j in range(1, i):
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]

        triangle.append(row)

    return triangle
