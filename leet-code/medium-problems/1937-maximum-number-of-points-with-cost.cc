/*
You are given an m x n integer matrix points (0-indexed). Starting with 0 points, you want to maximize the number of points you can get from the matrix.

To gain points, you must pick one cell in each row. Picking the cell at coordinates (r, c) will add points[r][c] to your score.

However, you will lose points if you pick a cell too far from the cell that you picked in the previous row. For every two adjacent rows r and r + 1 (where 0 <= r < m - 1), picking cells at coordinates (r, c1) and (r + 1, c2) will subtract abs(c1 - c2) from your score.

Return the maximum number of points you can achieve.

abs(x) is defined as:

    x for x >= 0.
    -x for x < 0.

 

Example 1:

Input: points = [[1,2,3],[1,5,1],[3,1,1]]
Output: 9
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 2), (1, 1), and (2, 0).
You add 3 + 5 + 3 = 11 to your score.
However, you must subtract abs(2 - 1) + abs(1 - 0) = 2 from your score.
Your final score is 11 - 2 = 9.

Example 2:

Input: points = [[1,5],[2,3],[4,2]]
Output: 11
Explanation:
The blue cells denote the optimal cells to pick, which have coordinates (0, 1), (1, 1), and (2, 0).
You add 5 + 3 + 4 = 12 to your score.
However, you must subtract abs(1 - 1) + abs(1 - 0) = 1 from your score.
Your final score is 12 - 1 = 11.

 

Constraints:

    m == points.length
    n == points[r].length
    1 <= m, n <= 10^5
    1 <= m * n <= 10^5
    0 <= points[r][c] <= 10^5

*/

#include <iostream>
#include <vector>

void maxPointsRecurs(std::vector<std::vector<int>>& points, std::vector<std::vector<long long>>& memo, int x) {
  if (x < 0)
    return;

  if (x == points.size() - 1) {
    for (int i = 0; i < points[x].size(); ++i) {
      memo[x][i] = points[x][i];
    }
  } else {
    for (int i = 0; i < points[x].size(); ++i) {
      long long max = INT_MIN;
      for (int j = 0; j < points[x].size(); ++j) {
        max = std::max(max, memo[x + 1][j] - std::abs(j - i));
      }
      memo[x][i] = max + points[x][i];
    }
  }
  maxPointsRecurs(points, memo, x - 1);
}

long long maxPointsDFS(std::vector<std::vector<int>>& points, std::vector<std::vector<long long>>& memo, int row, int column) {
  if (row >= points.size() || column >= points[row].size())
    return 0;

  if (memo[row][column] != INT_MIN)
    return memo[row][column];

  if (row == points.size() - 1) {
    memo[row][column] = points[row][column];
    return memo[row][column];
  }
  
  long long max = INT_MIN;

  for (int i = 0; i < points[row].size(); ++i) {
    long long maxDfs = maxPointsDFS(points, memo, row + 1, i);
    max = std::max(max, maxDfs - std::abs(column - i));
  }

  memo[row][column] = max + points[row][column];
  return memo[row][column];
}

long long maxPoints(std::vector<std::vector<int>>& points) {
  std::vector<std::vector<long long>> memo(points.size(), std::vector<long long>(points[0].size(), INT_MIN));

  long long max = INT_MIN;

  for (int i = 0; i < points[0].size(); ++i)
    max = std::max(max, maxPointsDFS(points, memo, 0, i));
  
  return max;
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> points = {
    { 1, 2, 3 },
    { 1, 5, 1 },
    { 3, 1, 1 }
  };

  std::cout << maxPoints(points) << std::endl;

  return 0;
}