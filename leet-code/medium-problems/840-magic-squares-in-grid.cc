/*
A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

 

Example 1:

Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1
Explanation: 
The following subgrid is a 3 x 3 magic square:

while this one is not:

In total, there is only one magic square inside the given grid.

Example 2:

Input: grid = [[8]]
Output: 0

 

Constraints:

    row == grid.length
    col == grid[i].length
    1 <= row, col <= 10
    0 <= grid[i][j] <= 15

*/

#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <string>

bool isMagicSquare(std::vector<std::vector<int>>& grid, int x, int y) {
  if (x + 2 >= grid.size() || y + 2 >= grid[0].size() || x < 0 || y < 0)
    throw "Number is not in proper bounds";
  
  // Middle of a magic square of size 3
  if (grid[x + 1][y + 1] != 5)
    return false;

  std::set<int> nums;

  for (int i = 0; i < 3; ++i)
    for (int j = 0; j < 3; ++j) {
      int a = x + i;
      int b = y + j;

      // Invalid number, return
      if (grid[a][b] < 1 || grid[a][b] > 9)
        return false;
      
      // Corner pieces, should be even
      if (i % 2 == 0 && j % 2 == 0 && grid[a][b] % 2 != 0)
        return false;
      
      // All other pieces, should be odd
      if (i % 2 == 1 || j % 2 == 1 && grid[a][b] %2 != 1)
        return false;

      nums.insert(grid[x + i][j + 1]);
    }

  // Distinction verifier
  return nums.size() == 9;
}

bool isMagicSquareWithString(std::vector<std::vector<int>>& grid, int x, int y) {
  std::string order = "2943816729438167";
  std::string reverse = "7618349276183492";
  std::string actual = std::to_string(grid[x][y]) + std::to_string(grid[x][y + 1]) + 
                        std::to_string(grid[x][y + 2]) + std::to_string(grid[x + 1][y + 2]) + 
                        std::to_string(grid[x + 2][y + 2]) + std::to_string(grid[x + 2][y + 1]) + 
                        std::to_string(grid[x + 2][y]) + std::to_string(grid[x + 1][y]);
  
  if (grid[x + 1][y + 1] != 5 || grid[x][y] % 2 != 0 || (order.find(actual) == -1 && reverse.find(actual) == -1))
    return false;
  
  return true;
}

int numMagicSquaresInside(std::vector<std::vector<int>>& grid) {
  if (grid.size() < 3 || grid[0].size() < 3)
    return 0;

  int numSquares = 0;

  for (int i = 0; i < grid.size() - 2; ++i)
    for (int j = 0; j < grid[i].size() - 2; ++j)
      if (isMagicSquareWithString(grid, i, j))
        numSquares++;

  return numSquares;
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> grid = {
    { 4, 3, 8, 4 },
    { 9, 5, 1, 9 },
    { 2, 7, 6, 2 }
  };

  std::cout << numMagicSquaresInside(grid) << std::endl;

  return 0;
}