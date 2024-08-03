/*
A swap is defined as taking two distinct positions in an array and swapping the values in them.

A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in the array together at any location.

 

Example 1:

Input: nums = [0,1,0,1,1,0,0]
Output: 1
Explanation: Here are a few of the ways to group all the 1's together:
[0,0,1,1,1,0,0] using 1 swap.
[0,1,1,1,0,0,0] using 1 swap.
[1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
There is no way to group all 1's together with 0 swaps.
Thus, the minimum number of swaps required is 1.

Example 2:

Input: nums = [0,1,1,1,0,0,1,1,0]
Output: 2
Explanation: Here are a few of the ways to group all the 1's together:
[1,1,1,0,0,0,0,1,1] using 2 swaps (using the circular property of the array).
[1,1,1,1,1,0,0,0,0] using 2 swaps.
There is no way to group all 1's together with 0 or 1 swaps.
Thus, the minimum number of swaps required is 2.

Example 3:

Input: nums = [1,1,0,0,1]
Output: 0
Explanation: All the 1's are already grouped together due to the circular property of the array.
Thus, the minimum number of swaps required is 0.

 

Constraints:

    1 <= nums.length <= 10^5
    nums[i] is either 0 or 1.

*/

#include <iostream>
#include <vector>

int oldMinSwaps(std::vector<int>& nums) {
  int numOnes = 0;
  int numOnesAtBegin = 0;
  int largestGroupOfOnesIndex = -1;
  int largestGroupOfOnes = 0;
  int minSwaps = 0;

  // Count ones at begin
  for (int i = 0; i < nums.size() && nums[i] == 1; ++i) {
    numOnesAtBegin++;
    numOnes++;
    largestGroupOfOnes++;
    largestGroupOfOnesIndex = 0;
  }

  for (int i = numOnesAtBegin + 1; i < nums.size(); ++i) {
    if (nums[i] == 1) {
      int numOnesTogether = 1;

      while (++i < nums.size()) {
        if (nums[i] == 1)
          numOnesTogether++;
        else
          break;
      }


      int groupOfOnesSize = numOnesTogether + (i == nums.size() ? numOnesAtBegin : 0);

      if (groupOfOnesSize > largestGroupOfOnes) {
        largestGroupOfOnes = groupOfOnesSize;
        largestGroupOfOnesIndex = i - numOnesTogether;
      }

      numOnes += numOnesTogether;
    }
  }

  if (largestGroupOfOnes == numOnes)
    return 0;

  std::vector<int> tmpArray;
  tmpArray.insert(tmpArray.end(), nums.begin(), nums.end());
  tmpArray.insert(tmpArray.end(), nums.begin(), nums.end());
  tmpArray.insert(tmpArray.end(), nums.begin(), nums.end());

  int startIndex = largestGroupOfOnesIndex + nums.size();
  int endIndex = startIndex + numOnes - 1;
  int lastCheckIndex = largestGroupOfOnesIndex + largestGroupOfOnes - 1;

  for (int i = startIndex; i <= endIndex; ++i)
    minSwaps += (tmpArray[i] == 0);

  int currSwaps = minSwaps;

  while (--endIndex >= lastCheckIndex && --startIndex >= 0) {
    if (tmpArray[endIndex + 1] == 1)
      currSwaps++;
    
    if (tmpArray[startIndex] == 1)
      currSwaps--;
    
    minSwaps = std::min(minSwaps, currSwaps);
  }

  return minSwaps;
}

int minSwaps(std::vector<int>& nums) {
  int numOnes = 0;
  int size = nums.size();
  
  for (int num : nums)
    numOnes += num;
  
  if (numOnes == size || numOnes == 0)
    return 0;

  int tmpMaxOnes = 0;

  for (int i = 0; i < numOnes; ++i)
    tmpMaxOnes += nums[i] == 1;
  
  int maxNumOnes = tmpMaxOnes;

  for (int i = 0; i < size; ++i) {
    tmpMaxOnes -= nums[i];
    tmpMaxOnes += nums[(i + numOnes) % size];
    maxNumOnes = std::max(maxNumOnes, tmpMaxOnes);
  }

  return numOnes - maxNumOnes;
}

int main(int argc, char** argv) {
  std::vector<int> nums;

  while (true) {
    nums.clear();
    int num = 0;

    while (std::cin >> num && (num == 1 || num == 0))
      nums.push_back(num);

    std::cout << minSwaps(nums) << std::endl;
  }

  return 0;
}