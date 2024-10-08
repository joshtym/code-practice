/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:

Input: triangle = [[-10]]
Output: -10

 

Constraints:

    1 <= triangle.length <= 200
    triangle[0].length == 1
    triangle[i].length == triangle[i - 1].length + 1
    -10^4 <= triangle[i][j] <= 10^4

 
Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/

#include <iostream>
#include <string>
#include <vector>

int minimumTotal(std::vector<std::vector<int>>& triangle) {
  std::vector<std::vector<int>> dp(triangle.size(), std::vector<int>(triangle[triangle.size() - 1].size(), INT_MAX));

  for (int i = triangle.size() - 2; i >= 0; --i) {
    for (int j = 0; j < triangle[i].size(); ++j) {
      triangle[i][j] = triangle[i][j] + std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
    }
  }

  return triangle[0][0];
}

int main(int argc, char** argv) {

}