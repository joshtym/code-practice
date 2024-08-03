/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

Example 1:

Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:

Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

 

Constraints:

    m == grid.length
    n == grid[i].length
    1 <= m, n <= 300
    grid[i][j] is '0' or '1'.


*/

#include <iostream>
#include <queue>
#include <vector>

int numIslands(std::vector<std::vector<char>>& grid) {
  std::queue<std::pair<int, int>> queue;
  int islands = 0;

  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] == '1') {
        islands++;
        queue.push(std::pair(i, j));

        while (!queue.empty()) {
          std::pair<int, int> coordinates = queue.front();
          int first = coordinates.first;
          int second = coordinates.second;

          queue.pop();

          grid[first][second] = '0';

          if (first - 1 >= 0 && grid[first - 1][second] == '1')
            queue.push(std::pair(first - 1, second));

          if (first + 1 < grid.size() && grid[first + 1][second] == '1')
            queue.push(std::pair(first + 1, second));
         
          if (second - 1 >= 0 && grid[first][second - 1] == '1')
            queue.push(std::pair(first, second - 1));

          if (second + 1 < grid[0].size() && grid[first][second + 1] == '1')
            queue.push(std::pair(first, second + 1));
        }
      }
    }
  }
  
  return islands;
}

int main(int argc, char** argv) {
  // std::vector<std::vector<char>> grid = {
  //   { '1', '1', '1', '1', '0' },
  //   { '1', '1', '0', '1', '0' },
  //   { '1', '1', '0', '0', '0' },
  //   { '0', '0', '0', '0', '0' }
  // };
  // std::vector<std::vector<char>> grid = {
  //   { '1', '1', '0', '0', '0' },
  //   { '1', '1', '0', '0', '0' },
  //   { '0', '0', '1', '0', '0' },
  //   { '0', '0', '0', '1', '1' }
  // };
  std::vector<std::vector<char>> grid = {
    { '1', '1', '1' },
    { '0', '1', '0' },
    { '1', '1', '1' }
  };

  std::cout << numIslands(grid) << std::endl;
  return 0;
}