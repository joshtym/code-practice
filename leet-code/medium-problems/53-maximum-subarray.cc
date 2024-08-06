/*
Given an integer array nums, find the
subarray
with the largest sum, and return its sum.

 

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.

Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

 

Constraints:

    1 <= nums.length <= 10^5
    -104 <= nums[i] <= 10^4

 

Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <iostream>
#include <vector>

int maxSubArrayDp(std::vector<int>& nums) {
  std::vector<std::vector<int>> sumsDp(nums.size(), std::vector<int>(nums.size(), -1));
  int max = INT_MIN;

  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i; j >= 0; --j) {
      sumsDp[i][j] = i == j ? nums[j] : (nums[j] + sumsDp[i][j + 1]);
      max = std::max(max, sumsDp[i][j]);
    }
  }
  
  return max;
}

int maxSubArray(std::vector<int>& nums) {
  int sum = 0;
  int max = INT_MIN;

  for (int num : nums) {
    sum += num;

    if (sum > max)
      max = sum;
    
    if (sum < 0)
      sum = 0;
  }

  return max;
}

int main(int argc, char** argv) {
  std::vector<int> nums = { 5,4,-1,7,8 };

  std::cout << maxSubArray(nums) << std::endl;

  return 0;
}
