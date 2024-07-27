#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> frequencySort(std::vector<int>& nums) {
  std::vector<std::vector<int>> freqHash(101);
  std::vector<int> frequencies;
  std::sort(nums.begin(), nums.end(), std::greater<>());
  int index = 0;

  while (index < nums.size()) {
    int numOccurrances = 1;
    int num = nums[index];

    while (++index < nums.size() && nums[index] == num) {
      numOccurrances++;
    }

    freqHash[numOccurrances].push_back(num);
  }

  for (int i = 1; i < freqHash.size(); ++i) {
    for (int num : freqHash[i]) {
      for (int j = 0; j < i; ++j) {
        frequencies.push_back(num);
      }
    }
  }

  return frequencies;
}

int main(int argc, char** argv) {
  std::vector<int> nums;
  for (int i = 1; i < argc; ++i) {
    nums.push_back(std::stoi(argv[i]));
  }

  auto result = frequencySort(nums);

  for (auto num : result) {
    std::cout << num << ", ";
  }

  std::cout << std::endl;

  return 0;
}