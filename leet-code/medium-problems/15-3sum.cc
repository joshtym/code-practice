#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<int>> threeSumBrute(std::vector<int>& nums) {
  std::vector<std::vector<int>> triplets;
  
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      for (int k = j + 1; k < nums.size(); ++k) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          triplets.push_back({ nums[i], nums[j], nums[k] });
        }
      }
    }
  }
  
  return triplets;
}

std::vector<std::vector<int>> threeSumTwoPointer(std::vector<int>& nums) {
  int target = 0;
  std::sort(nums.begin(), nums.end());
  std::set<std::vector<int>> s;
  std::vector<std::vector<int>> output;
  for (int i = 0; i < nums.size(); i++){
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
          int sum = nums[i] + nums[j] + nums[k];
          if (sum == target) {
              s.insert({nums[i], nums[j], nums[k]});
              j++;
              k--;
          } else if (sum < target) {
              j++;
          } else {
              k--;
          }
      }
  }
  for(auto triplets : s)
      output.push_back(triplets);
  return output;
}

int main(int argc, char** argv) {
  std::vector<int> nums;

  for (int i = 1; i < argc; ++i) {
    nums.push_back(std::stoi(argv[i]));
  }

  std::vector<std::vector<int>> triplets = threeSumTwoPointer(nums);

  for (auto result : triplets) {
    for (auto i : result) {
      std::cout << i << ", ";
    }
    std::cout << std::endl;
  }
  return 0;
}