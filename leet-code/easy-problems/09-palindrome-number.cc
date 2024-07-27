#include <iostream>
#include <string>
#include <vector>

bool isPalindrome(int num) {
  if (num < 0) {
    return false;
  }

  if (num < 10) {
    return true;
  }

  std::string numberAsString = std::to_string(num);
  int j = numberAsString.length() - 1;
  bool isPalindrome = true;

  for (int i = 0; i <= j; ++i) {
    if (numberAsString[i] != numberAsString[j--]) {
      isPalindrome = false;
      break;
    }
  }

  return isPalindrome;
}

bool isPalindromeWithoutString(int num) {
  if (num < 0) {
    return false;
  }

  if (num < 10) {
    return true;
  }

  bool isPalindrome = true;
  std::vector<int> digits;
  int tmp = num;

  while (tmp > 0) {
    digits.push_back(tmp % 10);
    tmp = tmp / 10;
  }

  int j = digits.size() - 1;

  for (int i = 0; i <= j; ++i) {
    if (digits[i] != digits[j--]) {
      isPalindrome = false;
      break;
    }
  }

  return isPalindrome;
}

bool isPalindromeReverse(int x) {
  if (x < 0 || x % 10 == 0) {
    return false;
  }

  long long reversed = 0;
  int tmp = x;

  while (tmp != 0) {
    reversed = reversed * 10 + tmp % 10;
    tmp = tmp / 10;
  }

  return reversed == x;
}

bool isPalindromeReverseHalf(int x) {
  if (x < 0 || (x != 0 && x % 10 == 0)) {
    return false;
  }

  int reversed = 0;

  while (x > reversed) {
    reversed = reversed * 10 + x % 10;
    x /= 10;
  }

  return (x == reversed) || (x == reversed / 10);
}

int main(int argc, char** argv) {
  int num;

  std::cout << "What number do you want to check for palindrome status?" << std::endl;
  std::cin >> num;

  if (isPalindromeReverseHalf(num)) {
    std::cout << "Is palindrome" << std::endl;
  } else {
    std::cout << "Is not paldinrome" << std::endl;
  }

  return 0;
}