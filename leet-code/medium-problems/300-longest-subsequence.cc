/*Given an integer array nums, return the length of the longest strictly increasing
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1

 

Constraints:

    1 <= nums.length <= 2500
    -10^4 <= nums[i] <= 10^4
*/

#include <iostream>
#include <vector>

int lengthOfLIS(std::vector<int>& nums) {
  std::vector<int> store(nums.size(), 1);

  for (int i = 0; i < nums.size(); ++i)
    for (int j = 0; j < i; ++j)
      if (nums[i] > nums[j] && store[i] < store[j] + 1)
        store[i] = store[j] + 1;

  return *std::max_element(store.begin(), store.end());
}

int main(int argc, char** argv) {
  std::vector<int> nums = { 0, 1, 0, 3, 2, 3 };
  std::cout << lengthOfLIS(nums) << std::endl;

  return 0;
}