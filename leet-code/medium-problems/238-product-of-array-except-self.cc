/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]

Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]

 

Constraints:

    2 <= nums.length <= 10^5
    -30 <= nums[i] <= 30
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

*/

#include <iostream>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& nums) {
  std::vector<int> prefixMult(nums.size());
  std::vector<int> suffixMult(nums.size());
  std::vector<int> products(nums.size());

 prefixMult[0] = 1;
 suffixMult[nums.size() - 1] = 1;

 for (int i = 1; i < nums.size(); ++i)
  prefixMult[i] = prefixMult[i - 1] * nums[i - 1];

  for (int i = nums.size() - 2; i >= 0; --i)
    suffixMult[i] = suffixMult[i + 1] * nums[i + 1];

  for (int i = 0; i < nums.size(); ++i)
    products[i] = prefixMult[i] * suffixMult[i];
    
  return products;
}

std::vector<int> productExceptSelfSmartMemory(std::vector<int>& nums) {
  std::vector<int> products(nums.size(), 1);

  products[0] = 1;
  products[nums.size() - 1] = 1;
  int currentProduct = 1;

  for (int i = 0; i < nums.size(); ++i) {
  products[i] = products[i] * currentProduct;
  currentProduct = currentProduct * nums[i];
  }

  currentProduct = 1;

  for (int i = nums.size() - 1; i >= 0; --i) {
    products[i] = products[i] * currentProduct;
    currentProduct = currentProduct * nums[i];
  }
    
  return products;
}

int main(int argc, char** argv) {
  std::vector<int> nums;

  for (int i = 1; i < argc; ++i)
    nums.push_back(std::stoi(argv[i]));
  
  std::vector<int> result = productExceptSelf(nums);

  for (int num : result)
    std::cout << num << ", ";
  
  std::cout << std::endl;

  return 0;
}