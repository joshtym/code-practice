#include <iostream>
#include <vector>

// Quick sort was too slow. On average, O(nlogn) but worst case scenarios on sorted and reverse sorted arrays depending on your pivot
int partitionIndex(std::vector<int>& nums, int low, int high) {
  int tmp = (high + low ) / 2;
  std::swap(nums[tmp], nums[high]);

  int index = low - 1;

  for (int i = index + 1; i <= high; ++i) {
    if (nums[i] < nums[high]) {
      index++;
      std::swap(nums[index], nums[i]);
    }
  }

  std::swap(nums[index + 1], nums[high]);
  return index + 1;
}

void quickSort(std::vector<int>& nums, int low, int high) {
  if (low < high) {
    int index = partitionIndex(nums, low, high);
    quickSort(nums, low, index - 1);
    quickSort(nums, index + 1, high);
  }
}

std::vector<int> countSort(std::vector<int>& inputArray) {
  std::vector<int> counts(2* 50000 + 1, 0);

  for (int num : inputArray) {
    counts[num + 50000]++;
  }

  int currWriteIndex = 0;

  for (int i = 0; i < counts.size(); ++i) {
    while(counts[i] > 0) {
      inputArray[currWriteIndex++] = i - 50000;
      counts[i]--;
    }
  }

  return inputArray;
}

std::vector<int> sortArray(std::vector<int>& nums) {
  // int high = nums.size() - 1;
  // quickSort(nums, 0, high);
  // return nums;
  return countSort(nums);
}

int main(int argc, char** argv) {
  std::vector<int> nums;

  for (int i = 1; i < argc; ++i) {
    nums.push_back(std::stoi(argv[i]));
  }

  const auto result = sortArray(nums);

  for (int num : result) {
    std::cout << num << ", ";
  }

  std::cout << std::endl;

  return 0;
}