/*
Given an m x n matrix, return all elements of the matrix in spiral order.

 

Example 1:

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

 

Constraints:

    m == matrix.length
    n == matrix[i].length
    1 <= m, n <= 10
    -100 <= matrix[i][j] <= 100

*/

#include <iostream>
#include <vector>

// Code can be cleaned up
std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
  int horizontalSteps = matrix[0].size();
  int verticalSteps = matrix.size() - 1;
  std::vector<int> order;
  int dirIndex = 0;
  int x = 0;
  int y = 0;

  // One way is to use a hash map to store visited. Wasted space tho
  while (horizontalSteps != 0 || verticalSteps != 0) {
    int tmp = 0;
    switch (dirIndex) {
      case 0:
        while (tmp++ < horizontalSteps) {
          order.push_back(matrix[x][y++]);
        }

        if (horizontalSteps != 0) {
          y--;
          x++;
          horizontalSteps = verticalSteps == 0 ? 0 : horizontalSteps - 1;
        }
        dirIndex++;
        break;
      case 1:
        while (tmp++ < verticalSteps) {
          order.push_back(matrix[x++][y]);
        }

        if (verticalSteps != 0) {
          x--;
          y--;
          verticalSteps = horizontalSteps == 0 ? 0 : verticalSteps - 1;
        }
        dirIndex++;
        break;
      case 2:
        while (tmp++ < horizontalSteps) {
          order.push_back(matrix[x][y--]);
        }

        if (horizontalSteps != 0) {
          y++;
          x--;
          horizontalSteps = verticalSteps == 0 ? 0 : horizontalSteps - 1;
        }
        dirIndex++;
        break;
      case 3:
        while (tmp++ < verticalSteps) {
          order.push_back(matrix[x--][y]);
        }

        if (verticalSteps != 0) {
          x++;
          y++;
          verticalSteps = horizontalSteps == 0 ? 0 : verticalSteps - 1;
        }
        dirIndex = 0;
        break;
      default:
        break;
    }
  }
  return order;
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> matrix = {
    { 1, 2, 3, 4 },
    { 5, 6, 7, 8 },
    { 9, 10, 11, 12 }
  };
  auto result = spiralOrder(matrix);

  for (int num : result)
    std::cout << num << ",";

  std::cout << std::endl;
  return 0;
}