/*
An additive number is a string whose digits can form an additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits, return true if it is an additive number or false otherwise.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

 

Example 1:

Input: "112358"
Output: true
Explanation: 
The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8

Example 2:

Input: "199100199"
Output: true
Explanation: 
The additive sequence is: 1, 99, 100, 199. 
1 + 99 = 100, 99 + 100 = 199

 

Constraints:

    1 <= num.length <= 35
    num consists only of digits.

 

Follow up: How would you handle overflow for very large input integers?
*/

const isAdditiveNumber = (num: string): boolean => {
  const getAdditiveString = (first: string, second: string) => {
    let sequence = [first, second];
    let fullStringLength = first.length + second.length;

    while (fullStringLength < num.length) {
      sequence.push(
        String(
          Number(sequence[sequence.length - 2]) +
            Number(sequence[sequence.length - 1])
        )
      );
      fullStringLength += sequence[sequence.length - 1].length;
    }

    return sequence.join("");
  };

  for (let start = 1; start < num.length; ++start) {
    for (let end = start + 1; end < num.length; ++end) {
      if (num[start] === "0" && end - start > 1) {
        break;
      }
      const additiveString = getAdditiveString(
        num.slice(0, start),
        num.slice(start, end)
      );

      if (additiveString === num) {
        return true;
      }
    }

    // If we hit this condition after our first iteration, then we've done something bad
    if (num[0] === "0") {
      return false;
    }
  }

  return false;
};

console.log(isAdditiveNumber("199100199"));
