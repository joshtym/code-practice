#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

bool isValid(std::string s) {
  std::unordered_map<char, char> keyValue = {
    { ')', '(' },
    { ']', '[' },
    { '}', '{' }
  };
  std::stack<char> parenth;

  for (int i = 0; i < s.length(); ++i) {
    auto d = s[i];
    if (d == ')' || d == ']' || d == '}') {
      auto opp = keyValue[d];
      if (parenth.empty()) {
        return false;
      } else if (parenth.top() == opp) {
        parenth.pop();
      } else {
        return false;
      }
    } else {
      parenth.push(d);
    }
  }

  return parenth.empty();
}

int main(int argc, char** argv) {
  std::string input;
  std::cin >> input;
  std::cout << isValid(input) << std::endl;

  return 0;
}