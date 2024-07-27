#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

std::vector<std::string> letterCombinations(std::string digits) {
  std::unordered_map<char, std::string> tNines;
  tNines['2'] = "abc";
  tNines['3'] = "def";
  tNines['4'] = "ghi";
  tNines['5'] = "jkl";
  tNines['6'] = "mno";
  tNines['7'] = "pqrs";
  tNines['8'] = "tuv";
  tNines['9'] = "wxyz";
  std::vector<std::string> items = {};

  if (digits.length() == 0) {
    return items;
  }

  std::string options = tNines[digits[0]];

  for (int i = 0; i < options.length(); ++i) {
    items.push_back(std::string(1, options[i]));
  }

  for (int i = 1; i < digits.length(); ++i) {
    std::vector<std::string> tmp;
    std::string options = tNines[digits[i]];

    for (int j = 0; j < options.length(); ++j) {
      for (int k = 0; k < items.size(); ++k) {
        tmp.push_back(items[k] + options[j]);
      }
    }

    items = tmp;
  }

  return items;
}

int main(int argc, char** argv) {
  std::string input;
  std::cout << "Input? ";
  std::cin >> input;
  
  auto letters = letterCombinations(input);

  for (auto letter : letters) {
    std::cout << letter << ", ";
  }
  std::cout << std::endl;
  return 0;
}