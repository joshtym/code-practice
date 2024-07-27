#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

std::vector<int> luckyNumsDiff(std::vector<std::vector<int>>& matrix) {
  for (int i = 0; i < matrix.size(); ++i) {
    int colIndexOfNum = -1;
    int rowMin = INT_MAX;
    int colMax = INT_MIN;

    for (int j = 0; j < matrix[i].size(); ++j) {
      int tmpMin = std::min(rowMin, matrix[i][j]);
      if (tmpMin != rowMin) {
        colIndexOfNum = j;
        rowMin = tmpMin;
      }
    }

    for (int j = 0; j < matrix.size(); ++j) {
      colMax = std::max(colMax, matrix[j][colIndexOfNum]);
    }

    if (colMax == rowMin) {
      return { colMax };
    }
  }

  return {};
}

std::vector<int> smartLuckyNumbers(std::vector<std::vector<int>>& matrix) {
  int rowMinMax = INT_MIN;
  int colMaxMin = INT_MAX;

  for (int i = 0; i < matrix.size(); ++i) {
    int tmpMin = INT_MAX;
    for (int j = 0; j < matrix[i].size(); ++j) {
      tmpMin = std::min(tmpMin, matrix[i][j]);
    }
    rowMinMax = std::max(rowMinMax, tmpMin);
  }

  for (int i = 0; i < matrix[0].size(); ++i) {
    int tmpMax = INT_MIN;
    for (int j = 0; j < matrix.size(); ++j) {
      tmpMax = std::max(tmpMax, matrix[j][i]);
    }
    colMaxMin = std::min(colMaxMin, tmpMax);
  }

  return rowMinMax == colMaxMin ? std::vector<int>{ rowMinMax } : std::vector<int>{};
}

std::vector<int> luckyNumbers(std::vector<std::vector<int>>& matrix) {
  std::vector<int> rowMins(50, 100000000);
  std::vector<int> colMaxs(50, -1);

  std::vector<int> luckyNums;

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      rowMins[i] = std::min(rowMins[i], matrix[i][j]);
      colMaxs[j] = std::max(colMaxs[j], matrix[i][j]);
    }
  }

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      if (matrix[i][j] == rowMins[i] && matrix[i][j] == colMaxs[j]) {
        luckyNums.push_back(matrix[i][j]);
      }
    }
  }

  int min = std::min(matrix.size(), matrix[0].size());

  return luckyNums;
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> matrix = { {3,7,8}, {9,11,13}, {15,16,17} };
  std::vector<int> nums = smartLuckyNumbers(matrix);

  for (auto num : nums) {
    std::cout << num << " ";
  }

  std::cout << std::endl;
  
  return 0;
}