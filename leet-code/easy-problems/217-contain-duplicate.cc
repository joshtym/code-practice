/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:

Input: nums = [1,2,3,1]
Output: true

Example 2:

Input: nums = [1,2,3,4]
Output: false

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

 

Constraints:

    1 <= nums.length <= 10^5
    -109 <= nums[i] <= 10^9
*/

#include <iostream>
#include <vector>
#include <unordered_map>

bool containsDuplicateViaSort(std::vector<int>& nums) {
  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size() - 1; ++i)
    if (nums[i] == nums[i + 1])
      return true;

  return false;
}

bool containsDuplicateViaHash(std::vector<int>& nums) {
  std::unordered_map<int, bool> hashMap;

  for (int num : nums)
    if (hashMap[num] == true)
      return true;
    else
      hashMap[num] = true;

  return false;
}

int main(int argc, char** argv) {
  std::vector<int> nums = { 1, 2, 3, 4 };
  std::cout << containsDuplicateViaSort(nums) << std::endl;
  return 0;
}