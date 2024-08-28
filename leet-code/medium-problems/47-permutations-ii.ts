/*
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

 

Example 1:

Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

 

Constraints:

    1 <= nums.length <= 8
    -10 <= nums[i] <= 10

*/
const next = (nums: number[]): void => {
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

const permuteUnique = (nums: number[]): number[][] => {
  let currentPerm = [...nums];
  let perms: number[][] = [[...currentPerm]];

  while (true) {
    nextPerm(currentPerm);

    if (JSON.stringify(currentPerm) === JSON.stringify(perms[0])) {
      break;
    }

    perms.push([...currentPerm]);
  }

  return perms;
};
