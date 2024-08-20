/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.

 

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.

Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = -2.33333.. which is truncated to -2.

 

Constraints:

    -2^31 <= dividend, divisor <= 2^31 - 1
    divisor != 0

*/
#include <string>
#include <iostream>

int divide(int divident, int divisor) {
  if (divident == 0)
    return 0;
  
  if (divident == INT_MIN && divisor == -1)
    return INT_MAX;
  
  std::string dividentAsString = std::to_string(divident);
  bool isDividentNegative = divident < 0;
  bool isDivisorNegative = divisor < 0;
  long absDivisor = isDivisorNegative ? ((long)divisor - (long)divisor - (long)divisor) : divisor;
  std::string quotient = (isDividentNegative || isDivisorNegative) && !(isDividentNegative && isDivisorNegative) ? "-" : "";
  
  int startIndex = isDividentNegative ? 1 : 0;
  long currCheckNumber = 0;

  while (startIndex < dividentAsString.length()) {
    currCheckNumber += (int)(dividentAsString[startIndex] - '0');
    int numDivide = 0;
    
    while (currCheckNumber >= absDivisor) {
      currCheckNumber -= absDivisor;
      numDivide++;
    }
    
    quotient += std::to_string(numDivide);
    int tmpToAdd = currCheckNumber;

    if (currCheckNumber > 0) {
      for (int i = 1; i < 10; ++i) {
        currCheckNumber += tmpToAdd;
      }
    }
    startIndex++;
  }

  return std::stoi(quotient);
}

int main(int argc, char** argv) {
  std::cout << divide(-2147483648, -1) << std::endl;
  return 0;
}