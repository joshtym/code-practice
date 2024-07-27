#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <cmath>

int reverse(int x);

int main(int argc, char** argv) {
  int number;
  std::cout << "Input? ";
  std::cin >> number;
  std::cout << reverse(number) << std::endl;

  return 0;
}

int reverse(int x) {
  if (-10 < x && x < 10) {
    return x;
  }

  bool isOverOrUnderFlow = false;
  int newNum = 0;

  while (x != 0) {
    int digit = x % 10;

    // Check multiplication overflow and underflow
    if ((newNum > 0 && newNum > INT_MAX / 10) ||
        (newNum < 0 && newNum < INT_MIN / 10)) {
      return 0;
    }

    newNum *= 10;

    // Check addition overflow
    if ((digit > 0 && newNum > INT_MAX - digit) ||
        (digit < 0 && newNum < INT_MIN - digit)) {
      return 0;
    }

    newNum += digit;
    x /= 10;
  }

  return newNum;
}