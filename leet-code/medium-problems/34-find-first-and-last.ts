/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

 

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:

Input: nums = [], target = 0
Output: [-1,-1]

 

Constraints:

    0 <= nums.length <= 105
    -109 <= nums[i] <= 109
    nums is a non-decreasing array.
    -109 <= target <= 109

*/
const searchRange = (nums: number[], target: number): number[] => {
  const lowerBound = -1;
  const upperBound = -1;

  let lower = 0;
  let higher = nums.length - 1;
  let firstFindIndex = -1;
  let found = false;

  while (lower <= higher) {
    firstFindIndex = Math.floor((higher + lower) / 2);

    if (nums[firstFindIndex] == target) {
      found = true;
      break;
    }

    if (nums[firstFindIndex] < target) {
      lower = firstFindIndex + 1;
    } else {
      higher = firstFindIndex - 1;
    }
  }

  if (!found) {
    return [lowerBound, upperBound];
  }

  let lowerLowerBound = 0;
  let higherLowerBound = firstFindIndex;

  while (lowerLowerBound <= higherLowerBound) {
    let mid = Math.floor((higherLowerBound + lowerLowerBound) / 2);

    if (nums[mid] == target) {
      higherLowerBound = mid - 1;
    } else {
      lowerLowerBound = mid + 1;
    }
  }

  let lowerUpperBound = firstFindIndex;
  let higherUpperBound = nums.length - 1;

  while (lowerUpperBound <= higherUpperBound) {
    let mid = Math.ceil((higherUpperBound + lowerUpperBound) / 2);

    if (nums[mid] == target) {
      lowerUpperBound = mid + 1;
    } else {
      higherUpperBound = mid - 1;
    }
  }

  return [lowerLowerBound, higherUpperBound];
};

console.log(
  searchRange(
    [
      1, 2, 2, 2, 2, 3, 4, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11, 12, 12, 12, 12, 12,
      13,
    ],
    2
  )
);
