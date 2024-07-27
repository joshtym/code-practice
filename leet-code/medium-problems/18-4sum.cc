#include <iostream>
#include <unordered_map>
#include <vector>
#include <set>

std::vector<std::vector<int>> fourSumOg(std::vector<int>& nums, int target) {
  std::unordered_map<int, std::vector<std::pair<int, int>>> targetsToIndices;
  std::set<std::set<int>> distinctGroups = {};

  for (int i = 0; i < nums.size() - 1; ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      int sum = nums[i] + nums[j];

      if (targetsToIndices.find(sum) == targetsToIndices.end()) {
        targetsToIndices[sum] = { std::make_pair(i, j) };
      } else {
        targetsToIndices[sum].push_back(std::make_pair(i, j));
      }
    }
  }

  for (const auto& [key, value] : targetsToIndices) {
    // std::cout << "SUM IS " << key << " AND VALUES INDICES AND VALUES ARE: ";
    // for (const auto& pair : value) {
    //   std::cout << "[" << pair.first << ", " << pair.second << "], [" << nums[pair.first] << ", " << nums[pair.second] << "], ";
    // }
    // std::cout << std::endl;
    int newTarget = target - key;

    if (targetsToIndices.find(newTarget) != targetsToIndices.end()) {
      std::vector<std::pair<int, int>> pairs = targetsToIndices[newTarget];

      for (int i = 0; i < value.size(); ++i) {
        for (int j = 0; j < pairs.size(); ++j) {
          std::set<int> indices = { value[i].first, value[i].second, pairs[j].first, pairs[j].second };

          if (indices.size() == 4) {
            // std::cout << "Adding in index pair: [" << value[i].first << ", " << value[i].second << ", " << pairs[j].first << ", " << pairs[j].second << "], " << std::endl;
            // std::cout << "This maps to: [" << nums[value[i].first] << ", " << nums[value[i].second] << ", " << nums[pairs[j].first] << ", " << nums[pairs[j].second] << "], " << std::endl;
            distinctGroups.insert(indices);
            // std::cout << "Size of distinct groups is now " << distinctGroups.size() << std::endl;
          }
        }
      }
    }
  }

  std::set<std::vector<int>> result = {};

  for (const auto& key : distinctGroups) {
    std::vector<int> values(key.begin(), key.end());
    // std::cout << values.size() << " SIZE" << std::endl;
    for (int i = 0; i < values.size(); ++i) {
      values[i] = nums[values[i]];
    }

    std::sort(values.begin(), values.end());
    result.insert(values);
  }

  return std::vector<std::vector<int>>(result.begin(), result.end());
}

std::vector<std::vector<int>> fourSumFail(std::vector<int>& nums, int target) {
  std::unordered_map<int, std::set<std::pair<int, int>>> targetsToIndices;
  std::set<std::vector<int>> tuples = {};

  for (int i = 0; i < nums.size() - 1; ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      int sum = nums[i] + nums[j];
      int targetSum = target - sum;
      std::pair<int, int> convPair = std::make_pair(i, j);

      if (targetsToIndices.find(targetSum) != targetsToIndices.end()) {
        for (auto pair : targetsToIndices[targetSum]) {
          if (convPair.first != pair.first && convPair.first != pair.second && convPair.second != pair.first && convPair.second != pair.second) {
            std::vector<int> tuple = { nums[convPair.first], nums[convPair.second], nums[pair.first], nums[pair.second] };
            std::sort(tuple.begin(), tuple.end());
            tuples.insert(tuple);
          }
        }
      }

      if (targetsToIndices.find(sum) == targetsToIndices.end()) {
        targetsToIndices[sum] = { convPair };
      } else {
        targetsToIndices[sum].insert(convPair);
      }
    }
  }

  return std::vector<std::vector<int>>(tuples.begin(), tuples.end());
}

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
  int size = nums.size();
  std::sort(nums.begin(), nums.end());
  std::set<std::vector<int>> set = {};
  std::vector<std::vector<int>> output = {};

  for (int i = 0; i < size - 3; ++i) {
    for (int j = i + 1; j < size - 2; ++j) {
      long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
      int low = j + 1, high = size - 1;

      while (low < high) {
        if (nums[low] + nums[high] < newTarget) {
          low++;
        } else if (nums[low] + nums[high] > newTarget) {
          high--;
        } else {
          set.insert({nums[i], nums[j], nums[low], nums[high]});
          low++;
          high--;
        }
      }
    }
  }

  for (auto val : set) {
    output.push_back(val);
  }

  return output;
}

int main(int argc, char** argv) {
  std::vector<int> nums;
  int target;

  for (int i = 1; i < argc; ++i) {
    nums.push_back(std::stoi(argv[i]));
  }

  std::cout << "Target? ";
  std::cin >> target;

  auto result = fourSum(nums, target);

  for (auto tuple : result) {
    std::cout << "[ ";
    for (auto num : tuple) {
      std::cout << num << ", ";
    }
    std::cout << " ]" << std::endl;
  }

  return 0;
}