#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

int searchInsert(std::vector<int>& nums, int target) {
  int start = 0;
  int end = nums.size() - 1;

  while (start <= end) {
    int middle = start + (end - start) / 2;

    if (nums[middle] == target) {
      return middle;
    }

    if (nums[middle] < target) {
      start = middle + 1;
    } else {
      end = middle - 1;
    }
  }

  return start;
}

int main(int argc, char** argv) {
  std::vector<int> nums;
  int target;

  for (int i = 1; i < argc; ++i) {
    char* end;
    nums.push_back(strtol(argv[i], &end, 10));
  }

  std::cout << "Target? ";
  std::cin >> target;

  std::cout << searchInsert(nums, target) << std::endl;

  return 0;
}