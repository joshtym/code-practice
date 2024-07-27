#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

int removeElementFirst(std::vector<int>& nums, int val) {
  int properIndex = 0;
  std::sort(nums.begin(), nums.end());

  for (int i = 0; i < nums.size(); ++i) {
    if (nums[i] != val) {
      nums[properIndex++] = nums[i];
    }
  }

  return properIndex;
}

int removeElement(std::vector<int>& nums, int val) {
  int start = 0;
  int end = nums.size() - 1;
  int num = 0;

  while (start <= end) {
    if (nums[start] == val) {
      nums[start] = nums[end];
      end--;
    } else {
      num++;
      start++;
    }
  }

  return num;
}

int main(int argc, char** argv) {
  std::vector<int> nums;
  int valToRemove;

  for (int i = 1; i < argc; ++i) {
    char* end;
    nums.push_back(strtol(argv[i], &end, 10));
  }

  std::cout << "What val to remove? ";
  std::cin >> valToRemove;

  int sizeOfNew = removeElement(nums, valToRemove);

  std::cout << sizeOfNew << std::endl;

  for (int i = 0; i < sizeOfNew; ++i) {
    std::cout << nums[i] << " ";
  }

  std::cout << std::endl;

  return 0;
}