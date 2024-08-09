/*
You start at the cell (rStart, cStart) of an rows x cols grid facing east. The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.

 

Example 1:

Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]

Example 2:

Input: rows = 5, cols = 6, rStart = 1, cStart = 4
Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]

 

Constraints:

    1 <= rows, cols <= 100
    0 <= rStart < rows
    0 <= cStart < cols

*/

#include <iostream>
#include <vector>

// Needs to be simplified to use just num of moves since if we want to maintain spiraling, we could just incr num of steps for each time
std::vector<std::vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
  std::vector<std::vector<int>> coords;
  std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

  int numVisited = 1;
  int x = rStart;
  int y = cStart;

  enum TravelDirection {
    NORTH,
    EAST,
    SOUTH,
    WEST
  };

  TravelDirection dir = TravelDirection::EAST;

  coords.push_back({ x, y });
  visited[x][y] = true;

  while (numVisited < rows * cols) {
    switch (dir) {
      case TravelDirection::EAST:
        while (++y < cols) {
          if (x >= 0 && x < rows) {
            numVisited++;
            visited[x][y] = true;
            coords.push_back({ x, y });
          }

          if (x + 1 == rows || !visited[x + 1][y])
            break;
        }
        dir = TravelDirection::SOUTH;
        break;
      case TravelDirection::SOUTH:
        while (++x < rows) {
          if (y >= 0 && y < cols) {
            numVisited++;
            visited[x][y] = true;
            coords.push_back({ x, y });
          }

          if (y - 1 < 0 || !visited[x][y - 1])
            break;
        }
        dir = TravelDirection::WEST;
        break;
      case TravelDirection::WEST:
        while (--y >= 0) {
          if (x >= 0 && x < rows) {
            numVisited++;
            visited[x][y] = true;
            coords.push_back({ x, y });
          }

          if (x - 1 < 0 || !visited[x - 1][y])
            break;
        }
        dir = TravelDirection::NORTH;
        break;
      case TravelDirection::NORTH:
        while (--x >= 0) {
          if (y >= 0 && y < cols) {
            numVisited++;
            visited[x][y] = true;
            coords.push_back({ x, y });
          }

          if (y + 1 == cols || !visited[x][y + 1])
            break;
        }
        dir = TravelDirection::EAST;
        break;
      default:
        break;
    }
  }

  return coords;
}

int main(int argc, char** argv) {
  int rows = 5;
  int cols = 6;
  int startRow = 1;
  int startCol = 4;

  auto result = spiralMatrixIII(rows, cols, startRow, startCol);

  for (int i = 0; i < result.size(); ++i) {
    std::cout << "[" << result[i][0] << "," << result[i][1] << "]" << std::endl;
  }

  return 0;
}