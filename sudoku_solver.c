/*
 * CSC A48 - Exercise 11 - Sudoku Solver
 * 
 * Your goal in this exercise is to practice recursion and
 * to see how a properly written recursive solution can
 * take care of fairly complicated tasks with a few lines
 * of (well thought out) code.
 * 
 * We will be solving Sudoku puzzles. In case you have never
 * solved or seen a Sudoku, you can learn more about them
 * here:
 * 
 * https://en.wikipedia.org/wiki/Sudoku
 * 
 * Your task if to write a function that takes an input
 * Sudoku in the form of a 9x9 array of integers. the
 * array will have a few entries filled with numbers in
 * [1, 9], and the remaining entries set to zero.
 * 
 * For the example in the wiki, the input array will
 * be
 * 
 * 5 3 0 0 7 0 0 0 0
 * 6 0 0 1 9 5 0 0 0
 * 0 9 8 0 0 0 0 6 0
 * 8 0 0 0 6 0 0 0 3
 * 4 0 0 8 0 3 0 0 1
 * 7 0 0 0 2 0 0 0 6
 * 0 6 0 0 0 0 2 8 0 
 * 0 0 0 4 1 9 0 0 5
 * 0 0 0 0 8 0 0 7 9
 * 
 * Your code should find the values that correctly
 * complete the Sudoku. 
 * 
 * As a brief reminder, a correctly solved Sudoku is
 * one in which there are no repeated digits in any
 * row, any column, or any of the 3x3 sub-arrays that
 * make up the large 9x9 grid. Another way to think
 * about it is, every row, column, and 3x3 subgrid
 * uses all of the different digits.
 * 
 * How to solve this?
 * 
 * * RECURSIVELY!
 * 
 * (hint) - Solving a Sudoku with N unknown values
 * may involve trying something, then solving an
 * easier Sudoku problem.
 * 
 * * How to approach this?
 * 
 * - As noted in class:
 * 	a) Determine the base case(s)
 * 	b) Figure out the recursive case
 * 	c) Determine what needs to happen to
 * 	   the solution for the entire problem
 * 	   is returned once the recursion hits
 * 	   the base case(s)
 * 
 * - Conditions on the input Sudoku
 * 	- It will have AT LEAST ONE DIGIT in each
 * 	  3x3 subgrid. Likely there will be several
 * 	  3x3 subgrids with several digits already
 * 	  set to some value.
 * 
 * - Conditions on your solution
 * 	- It should return a solution if there
 * 	  exists one.
 * 	- If no solution can be found, return the
 * 	  original input array
 * 	- If multiple solutions exist, any one of
 *        them is valid
 * 
 * - Can I use helper functions?
 * 	- Yes, by all means!
 * 
 * - Can I add extra libraries?
 * 	- No, they won't be needed.
 * 
 * - Can I change the 'print_sudoku()' function?
 * 	- Please don't, we may need it for testing!
 * 
 * (c) F. Estrada, March 2022
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_sudoku(int sudoku[9][9])
{
  printf("The Sudoku contains:\n");
  for (int j=0; j<9; j++)
  {
    for (int i=0; i<9;i++)
    {
      printf("%d  ",sudoku[j][i]);
    }
    printf("\n");
  }
}

int check_sudoku(int sudoku[9][9])
{
  /*
   *  This function checks whether a Sudoku is properly
   * solved. That means that each row, column, and
   * 3x3 subgrid uses each digit only once.
   * 
   *  If *ignores* zeros, so you can use it to check
   * that a partial solution is valid
   */
  
  /*****
   * TO DO:
   * Complete this function
   *   -- BUT ONLY IF YOU WANT TO!
   * Our testing script only checks your Sudoku
   * solution, if you want to solve it without
   * using this function, or if you want to write
   * your own helper functions, that's ok!
   * *****/
   
   int seen[9];

    // Checking rows!
    for (int row = 0; row < 9; row++) 
	{
        for (int i = 0; i < 9; i++) seen[i] = 0;

        for (int col = 0; col < 9; col++) 
		{
            int num = sudoku[row][col];
            if (num != 0) 
			{
                if (seen[num - 1]) return 0;
                seen[num - 1] = 1;
            }
        }
    }

    // Checking columns!
    for (int col = 0; col < 9; col++) 
	{
        for (int i = 0; i < 9; i++) seen[i] = 0;

        for (int row = 0; row < 9; row++) 
		{
            int num = sudoku[row][col];
            if (num != 0) 
			{
                if (seen[num - 1]) return 0;
                seen[num - 1] = 1;
            }
        }
    }

    // Checking 3x3 subgrids!
    for (int sudokuRow = 0; sudokuRow < 9; sudokuRow += 3) 
	{
        for (int sudokuCol = 0; sudokuCol < 9; sudokuCol += 3) 
		{
            for (int i = 0; i < 9; i++) seen[i] = 0;

            for (int row = 0; row < 3; row++) 
			{
                for (int col = 0; col < 3; col++) 
				{
                    int num = sudoku[sudokuRow + row][sudokuCol + col];
                    if (num != 0) 
					{
                        if (seen[num - 1]) return 0;
                        seen[num - 1] = 1;
                    }
                }
            }
        }
    }

    return 1;
}

int solved(int sudoku[9][9])
{
  /*
   * This function checks whether a given Sudoku is
   * completely solved (it has no zeros, all digits
   * are used once per row, column, and sub-grid.
   * It returns 1 if the Sudoku is solved, zero
   * otherwise
   */
  
  /*****
   * TO DO
   * Complete this function
   * BUT ONLY IF YOU WANT TO!
   *   You can solve the Sudoku without using this function,
   * or you can write a different helper function, whatever
   * makes more sense to yoU! our checker won't look at this
   * function, 
   * ****/
   
   int seen[9];
   
   for (int row = 0; row < 9; row++) 
	{
        for (int i = 0; i < 9; i++) seen[i] = 0;

        for (int col = 0; col < 9; col++) 
		{
            int num = sudoku[row][col];
			if (num == 0) return 0;
            if (num != 0) 
			{
                if (seen[num - 1]) return 0;
                seen[num - 1] = 1;
            }
        }
    }

    // Checking columns!
    for (int col = 0; col < 9; col++) 
	{
        for (int i = 0; i < 9; i++) seen[i] = 0;

        for (int row = 0; row < 9; row++) 
		{
            int num = sudoku[row][col];
			if (num == 0) return 0;
            if (num != 0) 
			{
                if (seen[num - 1]) return 0;
                seen[num - 1] = 1;
            }
        }
    }

    // Checking 3x3 subgrids!
    for (int sudokuRow = 0; sudokuRow < 9; sudokuRow += 3) 
	{
        for (int sudokuCol = 0; sudokuCol < 9; sudokuCol += 3) 
		{
            for (int i = 0; i < 9; i++) seen[i] = 0;

            for (int row = 0; row < 3; row++) 
			{
                for (int col = 0; col < 3; col++) 
				{
                    int num = sudoku[sudokuRow + row][sudokuCol + col];
					if (num == 0) return 0;
                    if (num != 0) 
					{
                        if (seen[num - 1]) return 0;
                        seen[num - 1] = 1;
                    }
                }
            }
        }
    }

    return 1;
}

void solve_sudoku(int sudoku[9][9], int depth)
{
  /*
   * This function solves an input Sudoku, the
   * input has a value of 0 for any entries that
   * are not yet decided. If no solution exists
   * the function returns the input array *exactly
   * as it was* when the function was called.
   * 
   * The 'depth' parameter is provided in case you
   * want to use it to help debug and trace your
   * code. You do not need to use it if you don't
   * want to, and the problem can be solved without
   * using the depth value at all. 
   * 
   * The automated checker won't look at the depth
   * either.
   */
  
  /*****
   * TO DO:
   * Complete this function
   *****/  
    for (int row = 0; row < 9; row++) 
	{
        for (int col = 0; col < 9; col++) 
		{
            if (sudoku[row][col] == 0) 
			{
                for (int num = 1; num <= 9; num++) 
				{
                    sudoku[row][col] = num;

                    if (check_sudoku(sudoku)) 
					{
                        solve_sudoku(sudoku, depth + 1);
                        if (solved(sudoku)) return; // Fully solved! (This is the base case)
                    }

                    sudoku[row][col] = 0; // Backtrack :(
                }
                return; // No valid number fits here :( 
            }
        }
    }
}

#ifndef __testing

int main()
{
   // We'll provide you with the same test case
   // from the Wiki, so you can check your output.
   // But as always, be aware we will test your
   // solution on different Sudoku puzzles.
  
/*   int Sudoku[9][9]={{5, 3, 0, 0, 7, 0, 0, 0, 0},
		     {6, 0, 0, 1, 9, 5, 0, 0, 0},
		     {0, 9, 8, 0, 0, 0, 0, 6, 0},
		     {8, 0, 0, 0, 6, 0, 0, 0, 3},
		     {4, 0, 0, 8, 0, 3, 0, 0, 1},
		     {7, 0, 0, 0, 2, 0, 0, 0, 6},
		     {0, 6, 0, 0, 0, 0, 2, 8, 0},
		     {0, 0, 0, 4, 1, 9, 0, 0, 5},
		     {0, 0, 0, 0, 8, 0, 0, 7, 9}};
*/
int Sudoku[9][9]={{0,0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,3,0,8,5},
                      {0,0,1,0,2,0,0,0,0},
                      {0,0,0,5,0,7,0,0,0},
                      {0,0,4,0,0,0,1,0,0},
                      {0,9,0,0,0,0,0,0,0},
                      {5,0,0,0,0,0,0,7,3},
                      {0,0,2,0,1,0,0,0,0},
                      {0,0,0,0,4,0,0,0,9}};
					  
  printf("Input puzzle is:\n");
  print_sudoku(Sudoku);
  
  solve_sudoku(Sudoku,0);
  
  printf("Solution is:\n");
  print_sudoku(Sudoku);
  
}

#endif