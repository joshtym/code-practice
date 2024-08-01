/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

 

Constraints:

    1 <= n <= 45


*/
#include <iostream>
#include <vector>

int climbStairs(int n) {
  std::vector<int> waysToClimb(n+1);

  waysToClimb[0] = 0;
  waysToClimb[1] = 1;
  
  for (int i = 2; i <= n; ++i)
    if (i == 2)
      waysToClimb[i] = 2;
    else
      waysToClimb[i] = waysToClimb[i - 1] + waysToClimb[i - 2];

  return waysToClimb[n];
}

int main(int argc, char** argv) {
  int input;

  while (true) {
    std::cin >> input;
    std::cout << climbStairs(input) << std::endl;
  }

  return 0;
}