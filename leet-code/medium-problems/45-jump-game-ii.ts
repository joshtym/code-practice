/*
You are given a 0-indexed array of integers nums of length n. You are initially positioned at nums[0].

Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at nums[i], you can jump to any nums[i + j] where:

    0 <= j <= nums[i] and
    i + j < n

Return the minimum number of jumps to reach nums[n - 1]. The test cases are generated such that you can reach nums[n - 1].

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [2,3,0,1,4]
Output: 2

 

Constraints:

    1 <= nums.length <= 10^4
    0 <= nums[i] <= 1000
    It's guaranteed that you can reach nums[n - 1].

*/

const jump = (nums: number[]): number => {
  if (nums.length == 1) {
    return 0;
  }

  const jumpsDp = new Array(nums.length).fill(1000000);
  jumpsDp[0] = 0;

  for (let i = 0; i < nums.length; ++i) {
    if (i + nums[i] >= nums.length - 1) {
      return jumpsDp[i] + 1;
    }

    for (let j = 1; j <= nums[i]; ++j) {
      jumpsDp[i + j] = Math.min(jumpsDp[i + j], jumpsDp[i] + 1);
    }
  }

  return 0;
};

const jump2 = (nums: number[]): number => {
  let jumps = 0;
  let currIndex = 0;

  while (currIndex < nums.length - 1) {
    if (currIndex + nums[currIndex] >= nums.length - 1) {
      return ++jumps;
    }

    let maxJump = 0;
    let newIndex;

    for (let i = 1; i <= nums[currIndex]; ++i) {
      let jumpChoice = i + nums[currIndex + i];
      if (jumpChoice >= maxJump) {
        maxJump = jumpChoice;
        newIndex = currIndex + i;
      }
    }

    currIndex = newIndex;
    jumps++;
  }

  return jumps;
};

console.log(jump2([2, 3, 1, 1, 4]));
