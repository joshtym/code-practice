/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

    Each of the digits 1-9 must occur exactly once in each row.
    Each of the digits 1-9 must occur exactly once in each column.
    Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

The '.' character indicates empty cells.

 

Example 1:

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:


 

Constraints:

    board.length == 9
    board[i].length == 9
    board[i][j] is a digit or '.'.
    It is guaranteed that the input board has only one solution.

*/

const solveSudoku = (board: string[][]): void => {
  const rows: boolean[][] = [];
  const columns: boolean[][] = [];
  const grids: boolean[][] = [];

  // Generate grid number for storage
  const getGridNumber = (row: number, column: number) => {
    return Math.floor(row / 3) * 3 + Math.floor(column / 3);
  };

  // The setter for the hash maps that allows us to set the entry to true or false
  const toggleEntry = (row: number, column: number, entry: number) => {
    rows[row][entry] = !rows[row][entry];
    columns[column][entry] = !columns[column][entry];
    grids[getGridNumber(row, column)][entry] =
      !grids[getGridNumber(row, column)][entry];
  };

  // Create the data for the grids for fast lookups
  for (let i = 0; i < board.length; ++i) {
    rows.push([]);
    columns.push([]);
    grids.push([]);

    for (let j = 0; j <= board.length; ++j) {
      rows[i].push(false);
      columns[i].push(false);
      grids[i].push(false);
    }
  }

  // Input the values that are already in the grid
  for (let i = 0; i < board.length; ++i) {
    for (let j = 0; j < board[i].length; ++j) {
      if (board[i][j] !== ".") {
        toggleEntry(i, j, Number(board[i][j]));
      }
    }
  }

  const entryIsValid = (row: number, column: number, entry: number) => {
    return (
      !rows[row][entry] &&
      !columns[column][entry] &&
      !grids[getGridNumber(row, column)][entry]
    );
  };

  const solve = (row: number, column: number): boolean => {
    if (column === 9) {
      column = 0;
      row++;
    }

    if (row === 9) {
      return true;
    }

    if (board[row][column] !== ".") {
      return solve(row, column + 1);
    }

    for (let i = 1; i <= 9; ++i) {
      if (entryIsValid(row, column, i)) {
        board[row][column] = i.toString();
        toggleEntry(row, column, i);

        if (solve(row, column + 1)) {
          return true;
        }

        board[row][column] = ".";
        toggleEntry(row, column, i);
      }
    }

    return false;
  };

  solve(0, 0);
};

solveSudoku([
  ["5", "3", ".", ".", "7", ".", ".", ".", "."],
  ["6", ".", ".", "1", "9", "5", ".", ".", "."],
  [".", "9", "8", ".", ".", ".", ".", "6", "."],
  ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
  ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
  ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
  [".", "6", ".", ".", ".", ".", "2", "8", "."],
  [".", ".", ".", "4", "1", "9", ".", ".", "5"],
  [".", ".", ".", ".", "8", ".", ".", "7", "9"],
]);
