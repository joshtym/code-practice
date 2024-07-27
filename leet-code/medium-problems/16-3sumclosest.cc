#include <iostream>
#include <vector>
#include <cmath>

int threeSumClosest(std::vector<int>& nums, int target) {
  std::sort(nums.begin(), nums.end());
  int sum = nums[0] + nums[1] + nums[2];

  for (int i = 0; i < nums.size() - 2; ++i) {
    int leftIndex = i + 1;
    int rightIndex = nums.size() - 1;

    while (leftIndex < rightIndex) {
      int tmpSum = nums[i] + nums[leftIndex] + nums[rightIndex];

      if (std::abs(target - tmpSum) < std::abs(target - sum)) {
        sum = tmpSum;
      }

      if (tmpSum < target) {
        leftIndex++;
      } else if (tmpSum > target) {
        rightIndex--;
      } else {
        return tmpSum;
      }
    }
  }

  return sum;
}

int main(int argc, char** argv) {
  int target;
  std::vector<int> nums;

  for (int i = 1; i < argc; ++i) {
    nums.push_back(std::stoi(argv[i]));
  }

  std::cout << "Target? ";
  std::cin >> target;

  std::cout << threeSumClosest(nums, target) << std::endl;

  return 0;
}