/*
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:

Input: nums = [1]
Output: [[1]]

 

Constraints:

    1 <= nums.length <= 6
    -10 <= nums[i] <= 10
    All the integers of nums are unique.

*/
const nextPerm = (nums: number[]): void => {
  let firstIndex = -1;
  let secondIndex = nums.length - 1;

  for (let i = nums.length - 2; i >= 0; --i) {
    if (nums[i] < nums[i + 1]) {
      firstIndex = i;
      break;
    }
  }

  if (firstIndex !== -1) {
    for (let i = nums.length - 1; i > firstIndex; --i) {
      if (nums[firstIndex] < nums[i]) {
        break;
      }
      secondIndex--;
    }

    const tmp = nums[firstIndex];
    nums[firstIndex] = nums[secondIndex];
    nums[secondIndex] = tmp;
  }

  let frontOfReverse = firstIndex + 1;
  let backOfReverse = nums.length - 1;

  while (frontOfReverse < backOfReverse) {
    const tmp = nums[frontOfReverse];
    nums[frontOfReverse] = nums[backOfReverse];
    nums[backOfReverse] = tmp;
    frontOfReverse++;
    backOfReverse--;
  }
};

const permute = (nums: number[]): number[][] => {
  let count = nums.length;
  let total = 1;
  let currentPerm = [...nums];
  let perms: number[][] = [[...currentPerm]];

  while (count > 0) {
    total *= count--;
  }

  while (perms.length < total) {
    nextPerm(currentPerm);
    perms.push([...currentPerm]);
  }

  return perms;
};
