#include <cstdio>
#include <iostream>
#include <ctime>

// A Backtracking program in C++ to solve Sudoku problem
#include <stdio.h>

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for size of Sudoku grid. Size will be NxN
#define N 9

/* Takes a partially filled-in grid and attempts to assign values to
all unassigned locations in such a way to meet the requirements
for Sudoku solution (non-duplication across rows, columns, and boxes) */

bool FindUnassignedLocation(int grid[N][N], int &row, int &col)
{
	#pragma omp parallel for collapse(2)
	for (row = 0; row < N; row++)
		for (col = 0; col < N; col++)
			if (grid[row][col] == UNASSIGNED)
				return true;
	return false;
}

/* Returns a boolean which indicates whether any assigned entry
in the specified row matches the given number. */
bool UsedInRow(int grid[N][N], int row, int num)
{
	#pragma omp parallel for
	for (int col = 0; col < N; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates whether any assigned entry
in the specified column matches the given number. */
bool UsedInCol(int grid[N][N], int col, int num)
{
	#pragma omp parallel for
	for (int row = 0; row < N; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}

/* Returns a boolean which indicates whether any assigned entry
within the specified 3x3 box matches the given number. */
bool UsedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num)
{
	#pragma omp parallel for collapse(2)
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row+boxStartRow][col+boxStartCol] == num)
				return true;
	return false; 
}

/* Returns a boolean which indicates whether it will be legal to assign
num to the given row,col location. */
bool isSafe(int grid[N][N], int row, int col, int num)
{
	/* Check if 'num' is not already placed in current row,
	current column and current 3x3 box */
	return !UsedInRow(grid, row, num) &&
		!UsedInCol(grid, col, num) &&
		!UsedInBox(grid, row - row%3 , col - col%3, num);
}

/* A utility function to print grid */
void printGrid(int grid[N][N])
{
	#pragma omp parallel for collapse(2)
	for (int row = 0; row < N; row++)
	{
	for (int col = 0; col < N; col++)
			printf("%2d", grid[row][col]);
		printf("\n");
	}
}