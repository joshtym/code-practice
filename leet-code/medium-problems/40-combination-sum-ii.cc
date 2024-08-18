/*
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

 

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

 

Constraints:

    1 <= candidates.length <= 100
    1 <= candidates[i] <= 50
    1 <= target <= 30

*/

#include <iostream>
#include <set>
#include <vector>
#include <unordered_map>

std::vector<std::vector<int>> recurseSum(std::vector<int>& candidates, int target, int startIndex) {
  int size = candidates.size();
  std::vector<std::vector<int>> things;

  for (int i = startIndex; i < candidates.size(); ++i) {
    if (target - candidates[i] < 0)
      return things;
    
    if (target - candidates[i] == 0) {
      things.push_back({ candidates[i] });
    }

    auto result = recurseSum(candidates, target - candidates[i], i + 1);

    if (result.size() != 0) {
      std::vector<int> t = { candidates[i] };
      for (auto x : result) {
        std::vector<int> t = { candidates[i] };
        t.insert(t.end(), x.begin(), x.end());
        things.push_back(t);
      }
    }
  }

  return things;
};

std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  std::set<std::vector<int>> combinations;
  int size = candidates.size();
  auto result = recurseSum(candidates, target, 0);

  for (auto x : result)
    combinations.insert(x);

  std::vector<std::vector<int>> output;

  for (auto comb : combinations)
    output.push_back(comb);

  return output;
}

void findCombination(std::vector<int>& candidates, std::vector<std::vector<int>>& result, std::vector<int>& comb, int index, int target) {
  if (target == 0) {
    result.push_back(comb);
    return;
  }

  for (int i = index; i < candidates.size(); ++i) {
    if (i > index && candidates[i] == candidates[i - 1])
      continue;
    
    if (candidates[i] > target)
      break;
    
    comb.push_back(candidates[i]);
    findCombination(candidates, result, comb, i + 1, target - candidates[i]);
    comb.pop_back();
  }
}

std::vector<std::vector<int>> combinationSum2New(std::vector<int>& candidates, int target) {
  std::sort(candidates.begin(), candidates.end());
  std::vector<std::vector<int>> result;
  std::vector<int> currComb;
  findCombination(candidates, result, currComb, 0, target);
}

int main(int argc, char** argv) {
  std::vector<int> nums = { 2, 5, 2, 1, 2 };

  auto result = combinationSum2(nums, 5);

  for (auto comb : result) {
    for (auto entry : comb)
      std::cout << entry << ",";
    std::cout << std::endl;
  }
  return 0;
}