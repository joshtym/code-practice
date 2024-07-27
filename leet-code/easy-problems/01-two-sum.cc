#include <iostream>
#include <vector>
#include <unordered_map>

// Compile with appropriate std flag

std::vector<int> twoSumBrute(std::vector<int>& nums, int target) {
  for (int i = 0; i < nums.size() - 1; ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      if (i + j == target) {
        return { i, j };
      }
    }
  }

  return {};
}

std::vector<int> twoSumHash(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> hash;

  for (int i = 0; i < nums.size(); ++i) {
    hash[nums[i]] = i;
  }

  for (int i = 0; i < nums.size(); ++i) {
    int opposite = target - nums[i];

    if (hash.find(opposite) != hash.end() && hash[opposite] != i) {
      return { i, hash[opposite] };
    }
  }
}

std::vector<int> twoSumHashSingle(std::vector<int>& nums, int target) {
  std::unordered_map<int, int> hash;

  for (int i = 0; i < nums.size(); ++i) {
    int opposite = target - nums[i];

    if (hash.find(opposite) != hash.end() && hash[opposite] != i) {
      return { i, hash[opposite] };
    } else {
      hash[nums[i]] = i;
    }
  }
}

int main(int argc, char** argv)
{
  std::vector<int> input;
  int target;
  char* end;

  for (int i = 0; i < argc; ++i) {
    input.push_back(strtol(argv[i], &end, 10));
  }

  std::cout << "What is your target?" << std::endl;
  std::cin >> target;

  auto result = twoSumHashSingle(input, target);

  if (result.size() == 2) {
    std::cout << "indices are: " << result[0] << " and " << result[1] << std::endl;
  } else {
    std::cout << "No indices found" << std::endl;
  } 

  return 0;
}