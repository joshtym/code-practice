/*
You are given m arrays, where each array is sorted in ascending order.

You can pick up two integers from two different arrays (each array picks one) and calculate the distance. We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.

 

Example 1:

Input: arrays = [[1,2,3],[4,5],[1,2,3]]
Output: 4
Explanation: One way to reach the maximum distance 4 is to pick 1 in the first or third array and pick 5 in the second array.

Example 2:

Input: arrays = [[1],[1]]
Output: 0

 

Constraints:

    m == arrays.length
    2 <= m <= 10^5
    1 <= arrays[i].length <= 500
    -104 <= arrays[i][j] <= 104
    arrays[i] is sorted in ascending order.
    There will be at most 105 integers in all the arrays.

*/

#include <iostream>
#include <vector>

int maxDistance(std::vector<std::vector<int>>& arrays) {
  std::vector<std::pair<int, int>> mins;
  std::vector<std::pair<int, int>> maxs;

  for (int i = 0; i < arrays.size(); ++i) {
    mins.push_back(std::pair(arrays[i][0], i));
    maxs.push_back(std::pair(arrays[i][arrays[i].size() - 1], i));
  }

  std::sort(mins.begin(), mins.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
    return a.first < b.first;
  });
  std::sort(maxs.begin(), maxs.end(), [](std::pair<int, int> a, std::pair<int, int> b) {
    return b.first < a.first;
  });
  
  if (mins[0].second != maxs[0].second)
    return maxs[0].first - mins[0].first;
  
  if (mins[1].first - mins[0].first < maxs[0].first - maxs[1].first)
    return maxs[0].first - mins[1].first;
  
  return maxs[1].first - mins[0].first;
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> arrays = {
    { 1, 5 },
    { 3, 4 }
  };

  std::cout << maxDistance(arrays) << std::endl;
  return 0;
}