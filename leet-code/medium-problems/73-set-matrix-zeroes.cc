/*
Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

 

Example 1:

Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

 

Constraints:

    m == matrix.length
    n == matrix[0].length
    1 <= m, n <= 200
    -2^31 <= matrix[i][j] <= 2^31 - 1

 

Follow up:

    A straightforward solution using O(mn) space is probably a bad idea.
    A simple improvement uses O(m + n) space, but still not the best solution.
    Could you devise a constant space solution?

*/

/*
  To answer the third question, the answer would be to set an index inside of the og matrix to 0 which we reference later
*/
#include <iostream>
#include <vector>


void setZeroes(std::vector<std::vector<int>>& matrix) {
  std::vector<bool> rowZeroes(matrix.size(), false);
  std::vector<bool> columnZeroes(matrix[0].size(), false);

  for (int i = 0; i < matrix.size(); ++i)
    for (int j = 0; j < matrix[i].size(); ++j)
      if (matrix[i][j] == 0) {
        rowZeroes[i] = true;
        columnZeroes[j] = true;
      }

  for (int i = 0; i < rowZeroes.size(); ++i)
    if (rowZeroes[i])
      for (int j = 0; j < matrix[i].size(); ++j)
        matrix[i][j] = 0;
  
  for (int i = 0; i < columnZeroes.size(); ++i)
    if (columnZeroes[i])
      for (int j = 0; j < matrix.size(); ++j)
        matrix[j][i] = 0;
}

int main(int argc, char** argv) {
  // std::vector<std::vector<int>> matrix = {
  //   { 1, 1, 1 },
  //   { 1, 0, 1 },
  //   { 1, 1, 1 }
  // };
  std::vector<std::vector<int>> matrix = {
    { 0, 1, 2, 0 },
    { 3, 4, 5, 2 },
    { 1, 3, 1, 5 }
  };

  setZeroes(matrix);

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[0].size(); ++j)
      std::cout << matrix[i][j] << ", ";
    std::cout << std::endl;
  }

  return 0;
}