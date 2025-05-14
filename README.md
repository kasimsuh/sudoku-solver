# Sudoku Solver  
Note: This piece of work was a partially solved c program that was given as an exercise in CSCA48 at UofT Scarborough.  
I am not claiming that every line of code in this program is my work (however, the function definitions are my own work).

## Breakdown of algorithm  
Note: The input sudoku has 0s which are the digits that are supposed to be filled in.
check_sudoku() 
---  
This function uses an array of 9 integers in order to track whether a number has appeared more than once in a row, column, or 3x3 subgrid.  
If the number has appeared more than once, the function returns 0, meaning the sudoku puzzle is not properly solved. Otherwise, it sets the corresponding entry in the array to 1, and continues iterating using nested for loops.  
Note that this function ignores zeroes in its checks, so it can be used to check for partial solutions.
---  
solved()  
---  
This function works very similarly to the check_sudoku function, except it checks for complete solutions, and does not ignore zeroes. It uses an array to keep track of numbers that may appear more than once,  
and uses nested for loops to iterate through rows, columns, and 3x3 subgrids. It returns 1 if the sudoku is correctly solved, and 0 if it is not.  
---  
solve_sudoku()  
---  
This function uses recursion in order to solve a given sudoku puzzle. The solution uses nested for loops to iterate through each entry in the input sudoku until it finds a 0.  
It then iterates through the numbers 1 to 9 and attempts to fill in the entry with the 0. It uses the helper function check_sudoku to see if the partial solution is correct,  
then it recursively calls itself and repeats the process until it reaches the base case: when the solved function returns a 1. If the sudoku puzzle is unsolvable, it backtracks  
and returns the puzzle to its original state with the 0s, then the function returns.

