/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.

 

Example 1:

Input: grid = [" /","/ "]
Output: 2

Example 2:

Input: grid = [" /","  "]
Output: 1

Example 3:

Input: grid = ["/\\","\\/"]
Output: 5
Explanation: Recall that because \ characters are escaped, "\\/" refers to \/, and "/\\" refers to /\.

 

Constraints:

    n == grid.length == grid[i].length
    1 <= n <= 30
    grid[i][j] is either '/', '\', or ' '.

*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

int regionsBfs(std::pair<int, int> startCoord, std::vector<std::string>& grid, std::unordered_map<std::string, bool>& visited) {
  int regions = 0;
  std::queue<std::pair<int, int>> queue;
  queue.push(std::pair(0, 0));
  // std::cout << "Starting with " << startCoord.first << " and " << startCoord.second << std::endl;

  while (!queue.empty()) {
    std::pair<int, int> xyCoords = queue.front();
    queue.pop();
    std::string coords = std::to_string(xyCoords.first) + "," + std::to_string(xyCoords.second);
    // std::cout << "Popped " << xyCoords.first << " and " << xyCoords.second << std::endl;

    if (visited[coords] == true) {
      // std::cout << "I've been here" << std::endl;
      regions++;
    } else if (visited[coords] == false) {
      visited[coords] = true;
      std::vector<std::pair<int, int>> pointsPushed;
      
      if ((xyCoords.first == 0 || xyCoords.first == grid.size()) && xyCoords.second < grid[0].size()) {
        queue.push(std::pair(xyCoords.first, xyCoords.second + 1));
        pointsPushed.push_back(std::pair(xyCoords.first, xyCoords.second + 1));
      }

      if ((xyCoords.second == 0 || xyCoords.second == grid[0].size()) && xyCoords.first < grid.size()) {
        queue.push(std::pair(xyCoords.first + 1, xyCoords.second));
        pointsPushed.push_back(std::pair(xyCoords.first + 1, xyCoords.second));
      }

      if (xyCoords.first < grid.size() && xyCoords.second < grid[0].size()) {
        char ch = grid[xyCoords.first][xyCoords.second];

        switch (ch) {
          case ' ':
            break;
          case '/':
            if (pointsPushed.size() == 2) {
              regions++;
              grid[xyCoords.first][xyCoords.second] = ' ';
             } else if (pointsPushed.size() == 1) {
              if (pointsPushed.size() == 1) {
                if (pointsPushed[0].first == xyCoords.first)
                  queue.push(std::pair(xyCoords.first + 1, xyCoords.second));
                else
                  queue.push(std::pair(xyCoords.first, xyCoords.second + 1));
                
                grid[xyCoords.first][xyCoords.second] = ' ';
              }
            }
            break;
          case '\\':
            queue.push(std::pair(xyCoords.first + 1, xyCoords.second + 1));
            grid[xyCoords.first][xyCoords.second] = ' ';
            break;
          default:
            break;
        }
      }
    }
  }

  return regions;
}

int regionsBySlashes(std::vector<std::string>& grid) {
  std::unordered_map<std::string, bool> visited;
  int regions = regionsBfs(std::pair(0, 0), grid, visited);

  for (int i = 0; i < grid.size(); ++i) {
    for (int j = 0; j < grid[0].size(); ++j) {
      if (grid[i][j] != ' ') {
        regions += regionsBfs(std::pair(i, j), grid, visited);
      }
    }
  }

  return regions;
}

int main(int argc, char** argv) {
  std::vector<std::string> grid = { "/\\" , "\\/" };
  std::cout << regionsBySlashes(grid) << std::endl;
  return 0;
}