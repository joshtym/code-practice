/*
Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.

The following rules define a valid string:

    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "(*)"
Output: true

Example 3:

Input: s = "(*))"
Output: true

 

Constraints:

    1 <= s.length <= 100
    s[i] is '(', ')' or '*'.

*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

bool checkValidString(std::string& s, std::stack<bool> parenthesis, int index) {
  for (int i = index; i < s.length(); ++i) {
    switch (s[i]) {
      case '(':
        parenthesis.push(true);
        break;
      case ')':
        if (parenthesis.empty())
          return false;
        parenthesis.pop();
        break;
      case '*':
        s[i] = '(';
        if (checkValidString(s, parenthesis, i))
          return true;
        s[i] = ')';
        if (checkValidString(s, parenthesis, i))
          return true;
        return checkValidString(s, parenthesis, i + 1);
      default:
        break;
    }
  }
  return parenthesis.empty();
}

bool checkValidString(std::string s) {
  return checkValidString(s, std::stack<bool>(), 0);
}

bool checkValidStringLinear(std::string s) {
  int leftMin = 0;
  int leftMax = 0;

  for (int i = 0; i < s.length(); ++i) {
    switch (s[i]) {
      case '(':
        leftMin++;
        leftMax++;
        break;
      case ')':
        leftMin--;
        leftMax--;
        break;
      case '*':
        leftMin--;
        leftMax++;
        break;
      default:
        break;
    }

    if (leftMax < 0)
      return false;

    leftMin = leftMin < 0 ? 0 : leftMin;
  }

  return leftMin == 0;
}

int main(int argc, char** argv) {
  std::cout << checkValidString("(*)") << std::endl;
  return 0;
}