#include <iostream>
#include <vector>

std::vector<int> sortJumbled(std::vector<int>& mapping, std::vector<int>& nums) {
  // Note this ONLY works with the restriction that the numbers provided are less than a billion
  // Anything less and reversing the number would hit a potential overflow

  std::sort(nums.begin(), nums.end(), [mapping](int a, int b) {
    int mappedNumA = mapping[a % 10];
    int mappedNumB = mapping[b % 10];
    a /= 10;
    b /= 10;
    int multiplier = 10;

    while (a > 0) {
      mappedNumA += mapping[a % 10] * multiplier;
      a /= 10;
      multiplier *= 10;
    }

    multiplier = 10;

    while (b > 0) {
      mappedNumB += mapping[b % 10] * multiplier;
      b /= 10;
      multiplier *= 10;
    }

    return mappedNumA < mappedNumB;
  });

  return nums;
}

int main(int argc, char** argv) {
  std::vector<int> mapping = { 8, 9, 4, 0, 2, 1, 3, 5, 7, 6 };
  std::vector<int> nums = { 991, 338, 38 };

  auto result = sortJumbled(mapping, nums);

  for (int num: result) {
    std::cout << num << ", ";
  }

  std::cout << std::endl;
  return 0;
}