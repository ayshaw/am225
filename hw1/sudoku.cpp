#include <cstdio>
#include <iostream>
#include <ctime>
#include "sudoku.h"
using namespace std;
// A Backtracking program in C++ to solve Sudoku problem
#include <stdio.h>

// UNASSIGNED is used for empty cells in sudoku grid
#define UNASSIGNED 0

// N is used for size of Sudoku grid. Size will be NxN
#define N 9


bool SolveSudoku(int grid[N][N])
{
	int row, col;

	// If there is no unassigned location, we are done
	if (!FindUnassignedLocation(grid, row, col))
	return true; // success!
	
	// consider digits 1 to 9
	for (int num = 1; num <= 9; num++)
	{
		// if looks promising
		if (isSafe(grid, row, col, num))
		{
			// make tentative assignment
			grid[row][col] = num;

			// return, if success, yay!
			if (SolveSudoku(grid))
				return true;

			// failure, unmake & try again
			grid[row][col] = UNASSIGNED;
		}
	}
	return false; // this triggers backtracking
}




/* Driver Program to test above functions */
int main()
{
	clock_t time_req;
	time_req=clock();
	int runs=100;

	// 0 means unassigned cells
	int grid[N][N] = {{1, 0, 0, 9, 0, 7, 0, 0, 3},
					{0, 8, 0, 0, 0, 0, 0, 7, 0},
					{0, 0, 9, 0, 0, 0, 6, 0, 0},
					{0, 0, 7, 2, 0, 9, 4, 0, 0},
					{4, 1, 0, 0, 0, 0, 0, 9, 5},
					{0, 0, 8, 5, 0, 4, 3, 0, 0},
					{0, 0, 3, 0, 0, 0, 7, 0, 0},
					{0, 5, 0, 0, 0, 0, 0, 4, 0},
					{2, 0, 0, 8, 0, 6, 0, 0, 9}};

	for (int i=1; i<runs; i++)
	{printf("run %d\n",i);

			if (SolveSudoku(grid) == true)
				{printGrid(grid);}
			else
				printf("No solution exists");
		
			

	}

	time_req = clock() - time_req;
	float realtime=(float)time_req/CLOCKS_PER_SEC/100;
	printf("it took %e seconds per stupid ass fucking run",realtime);
	return 0;
}


// fuck everything now
