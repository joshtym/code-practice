/*
An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

Given an integer n, return the nth ugly number.

 

Example 1:

Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.

Example 2:

Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

 

Constraints:

    1 <= n <= 1690

*/
#include <vector>
#include <unordered_set>
#include <queue>
#include <iostream>

int nthUglyNumber(int n) {
  std::vector<int> primes = { 2, 3, 5 };
  std::priority_queue<long, std::vector<long>, std::greater<long>> uglyNumbers;
  std::unordered_set<long> processedNumbers;
  long currentNumber;
  
  processedNumbers.insert(1);
  uglyNumbers.push(1);

  for (int i = 0; i < n; ++i) {
    currentNumber = uglyNumbers.top();
    uglyNumbers.pop();

    for (int prime : primes) {
      long numToAdd = currentNumber * prime;

      if (processedNumbers.find(numToAdd) == processedNumbers.end()) {
        uglyNumbers.push(numToAdd);
        processedNumbers.insert(numToAdd);
      }
    }
  }

  return (int)currentNumber;
}

int main(int argc, char** argv) {
  std::cout << nthUglyNumber(10) << std::endl;
  return 0;
}