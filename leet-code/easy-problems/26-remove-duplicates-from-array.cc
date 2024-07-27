#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

int removeDuplicates(std::vector<int>& nums) {
  int uniqueIndex = 0;
  
  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] != nums[uniqueIndex]) {
      nums[++uniqueIndex] = nums[i];
    }
  }

  return nums.size() > 0 ? uniqueIndex + 1 : 0;
}

int main(int argc, char** argv) {
  std::vector<int> nums;

  for (int i = 1; i < argc; ++i) {
    char* end;
    nums.push_back(strtol(argv[i], &end, 10));
  }

  int duplicates = removeDuplicates(nums);

  std::cout << duplicates << std::endl;

  for (int i = 0; i < duplicates; ++i) {
    std::cout << nums[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}