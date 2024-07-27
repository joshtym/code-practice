#include <iostream>
#include <string>

int myAtoi(std::string x);

int main(int argc, char** argv) {
  std::string numberToConvert;
  std::cout << "Input? ";
  std::cin >> numberToConvert;
  std::cout << myAtoi(numberToConvert) << std::endl;

  return 0;
}

// Could be cleaned up
int myAtoi(std::string s) {
  int newNum = 0;
  int index = 0;
  bool isNegative = false;
  bool hasEncounteredNum = false;

  while (index < s.length()) {
    if (s[index] ==  ' ') {
      if (!hasEncounteredNum) {
        index++;
      } else {
        break;
      }
    } else if (s[index] == '-' || s[index] == '+') {
      if (!hasEncounteredNum) {
        hasEncounteredNum = true;
        isNegative = s[index] == '-';
        index++;
      } else {
        break;
      }
    } else {
      int digit = (int)s[index] - 48;

      if (digit < 10 && digit >= 0) {
        hasEncounteredNum = true;

        // Check multiplication overflow and underflow
        if (newNum > 0 && newNum > INT_MAX / 10) {
          return INT_MAX;
        }

        if (newNum < 0 && newNum < INT_MIN / 10) {
          return INT_MIN;
        }

        newNum *= 10;

        // Check new digit overflow and underflow
        if (!isNegative) {
          if (newNum > INT_MAX - digit) {
            return INT_MAX;
          }
          
          newNum += digit;
        } 
        
        if (isNegative) {
          if (newNum < INT_MIN + digit) {
            return INT_MIN;
          }

          newNum -= digit;
       }

       index++;
      } else {
        return newNum;
      }
    }
  }

  return newNum;
}