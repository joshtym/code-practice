#include <iostream>
#include <string>
#include <vector>

// Code could definitely be cleaner

long long outputNum(std::string number) {
  long long num = 0;

  for (int i = 0; i < number.length(); ++i) {
    char digit = number[i];
    bool shouldLookahead = i != number.length() - 1;
    char digitTwo = i != number.length() - 1 ? number[i + 1] : 'Z';

    if (digit == 'C') {
      if (digitTwo == 'D') {
        num += 400;
        i++;
      } else if (digitTwo == 'M') {
        num += 900;
        i++;
      } else {
        num += 100;
      }
    } else if (digit == 'X') {
      if (digitTwo == 'L') {
        num += 40;
        i++;
      } else if (digitTwo == 'C') {
        num += 90;
        i++;
      } else {
        num += 10;
      }
    } else if (digit == 'I') {
      if (digitTwo == 'V') {
        num += 4;
        i++;
      } else if (digitTwo == 'X') {
        num += 9;
        i++;
      } else {
        num += 1;
      }
    } else if (digit == 'M') {
      num += 1000;
    } else if (digit == 'D') {
      num += 500;
    } else if (digit == 'L') {
      num += 50;
    } else if (digit == 'V') {
      num += 5;
    }
  }

  return num;
}

int main(int argc, char** argv) {
  std::string input;

  std::cout << "What number do you want to convert?" << std::endl;
  std::cin >> input;
  std::cout << "Number is " << outputNum(input) << std::endl;

  return 0;
}