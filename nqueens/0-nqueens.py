#!/usr/bin/python3
import sys

def is_safe(board, row, col, N):
    """
    Check if placing a queen at (row, col) is safe.
    """
    # Check column
    for i in range(row):
        if board[i] == col:
            return False

    # Check diagonals
    for i in range(row):
        if abs(board[i] - col) == abs(i - row):
            return False

    return True

def solve_nqueens(N, row, board, solutions):
    """
    Recursively solve the N queens problem.
    """
    if row == N:
        # Found a solution; add it to the list
        solutions.append([[i, board[i]] for i in range(N)])
        return

    for col in range(N):
        if is_safe(board, row, col, N):
            board[row] = col
            solve_nqueens(N, row + 1, board, solutions)
            # Backtrack: clear the row for the next iteration
            board[row] = -1

def nqueens(N):
    """
    Solve the N queens problem for a given N and print all solutions.
    """
    if not str(N).isdigit():
        print("N must be a number")
        sys.exit(1)

    N = int(N)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    # Initialize the board and solutions
    board = [-1] * N
    solutions = []

    # Solve the problem
    solve_nqueens(N, 0, board, solutions)

    # Print all solutions
    for solution in solutions:
        print(solution)

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    nqueens(sys.argv[1])
