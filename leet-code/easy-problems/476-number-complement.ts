/*
The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

    For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.

Given an integer num, return its complement.

 

Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

 

Constraints:

    1 <= num < 2^31
*/
const findComplement = (num: number): number => {
  let index = 0;

  // Only flip digits up to the last one (otherwise we start looking at 2s complement)
  for (let i = 0; i < 32; ++i) {
    if ((num & (1 << i)) != 0) {
      index = i;
    }
  }

  for (let i = 0; i <= index; ++i) {
    let newValue = !((num & (1 << i)) != 0) ? 1 : 0;
    let mask = ~(1 << i);
    num = (num & mask) | (newValue << i);
  }

  return num;
};

console.log(findComplement(5));
