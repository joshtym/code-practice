#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

std::vector<std::vector<int>> restoreMatrix(std::vector<int>& rowSum, std::vector<int>& colSum) {
  std::vector<std::vector<int>> validMatrix(rowSum.size(), std::vector<int>(colSum.size(), 0));
  
  for (int i = 0; i < validMatrix.size(); ++i) {
    for (int j = 0; j < validMatrix[i].size(); ++j) {
      validMatrix[i][j] = std::min(rowSum[i], colSum[j]);
      rowSum[i] -= validMatrix[i][j];
      colSum[j] -= validMatrix[i][j];
    }
  }

  return validMatrix;
}

int main(int argc, char** argv) {
  std::vector<int> rowSums = { 5, 7, 10 };
  std::vector<int> colSums = { 8, 6, 8 };
  std::vector<std::vector<int>> validMatrix = restoreMatrix(rowSums, colSums);

  // Print results
  for (auto num : validMatrix) {
    for (auto numTwo : num) {
      std::cout << numTwo << ", ";
    }
    std::cout << std::endl;
  }
  
  return 0;
}