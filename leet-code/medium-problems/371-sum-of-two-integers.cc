/*
Given two integers a and b, return the sum of the two integers without using the operators + and -.

 

Example 1:

Input: a = 1, b = 2
Output: 3

Example 2:

Input: a = 2, b = 3
Output: 5

 

Constraints:

    -1000 <= a, b <= 1000


*/

#include <iostream>

int getSum(int a, int b) {
  int sum = 0;
  bool carryOver = false;

  for (int i = 0; i < 32; ++i) {
    bool aBit = ((a & (1 << i)) != 0);
    bool bBit = ((b & (1 << i)) != 0);
    bool val = (aBit && bBit || !aBit && !bBit) ? carryOver : !carryOver;
    carryOver = aBit && bBit || aBit && carryOver || bBit && carryOver;

    sum = sum | (val << i);
  }

  return sum;      
}

int main(int argc, char** argv) {
  int a, b;
  
  while (true) {
    std::cin >> a >> b;
    std::cout << getSum(a, b) << std::endl;
  }

  return 0;
}