const canJump = (nums: number[]): boolean => {
  let jumps = 0;
  let currIndex = 0;

  while (currIndex < nums.length - 1) {
    if (currIndex + nums[currIndex] >= nums.length - 1) {
      return true;
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

    if (maxJump === 0) {
      return false;
    }
    currIndex = newIndex;
    jumps++;
  }

  return true;
};
