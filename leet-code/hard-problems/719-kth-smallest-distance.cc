/*
The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.

 

Example 1:

Input: nums = [1,3,1], k = 1
Output: 0
Explanation: Here are all the pairs:
(1,3) -> 2
(1,1) -> 0
(3,1) -> 2
Then the 1st smallest distance pair is (1,1), and its distance is 0.

Example 2:

Input: nums = [1,1,1], k = 2
Output: 0

Example 3:

Input: nums = [1,6,1], k = 3
Output: 5

 

Constraints:

    n == nums.length
    2 <= n <= 10^4
    0 <= nums[i] <= 10^6
    1 <= k <= n * (n - 1) / 2

*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

int smallestDistancePairBrute(std::vector<int>& nums, int k) {
  std::vector<int> distances;

  for (int i = 0; i < nums.size() - 1; ++i)
    for (int j = i + 1; j < nums.size(); ++j)
      distances.push_back(std::abs(nums[i] - nums[j]));

  std::sort(distances.begin(), distances.end());

  return distances[k - 1];
}

int smallestDistancePair(std::vector<int>& nums, int k) {
  // We can sort this way because the absolute distance is the same regardless of which number you take in front of the other
  std::sort(nums.begin(), nums.end());

  int left = 0;

  // The absolute largest distance between two numbers. We will binary search between 0 and this until we get to k amount of pairs
  int right = nums.back() - nums.front();

  while (left < right) {
    int mid = (left + right) / 2;

    // Because we want to find kth smallest distance, we use binary search to limit down to the kth distance (which is just the amount of pairs)
    if (countPairs(nums, mid) >= k)
      right = mid;
    else
      left = mid + 1;
  }

  return left;
}

int countPairs(const std::vector<int>& nums, int dist) {
  int count = 0;

  for (int i = 0; i < nums.size(); ++i) {
    int newSum = nums[i] - dist;
    int total = std::lower_bound(nums.begin(), nums.end(), newSum) - nums.begin();
    count += i - total;
  }

  return count;
}

int main(int argc, char** argv) {
  return 0;
}