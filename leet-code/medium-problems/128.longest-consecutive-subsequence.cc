/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

 

Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

 

Constraints:

    0 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

int longestConsecutive(std::vector<int>& nums) {
  std::unordered_set<int> set;
  int maxSubsequence = 0;

  for (int i = 0; i < nums.size(); ++i)
    set.insert(nums[i]);

  for (int i = 0; i < nums.size(); ++i) {
    if (set.find(nums[i] - 1) == set.end()) {
      int subSequence = 1;

      while (set.find(nums[i] + subSequence) != set.end()) {
        subSequence++;
      }

      maxSubsequence = std::max(maxSubsequence, subSequence);
    }
  }

  return maxSubsequence;
}

int main(int argc, char** argv) {
  std::vector<int> nums = { 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 };
  std::cout << longestConsecutive(nums) << std::endl;
  return 0;
}