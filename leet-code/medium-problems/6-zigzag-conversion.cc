#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

std::string convert(std::string s, int numRows) {
  int colDirection = -1;
  int colIndex = 0;

  std::vector<std::string> converted(numRows, "");
  std::string convertedString = "";

  if (numRows == 1) {
    return s;
  }

  for (int i = 0; i < s.length(); ++i) {
    if (colIndex == 0 || colIndex == numRows - 1) {
      colDirection *= -1;
    }

    converted[colIndex] += s[i];
    colIndex += colDirection;
  }

  for (int i = 0; i < converted.size(); ++i) {
    convertedString += converted[i];
  }

  return convertedString;
}

int main(int argc, char** argv) {
  std::string input;
  int numRows;
  std::cout << "Input? ";
  std::cin >> input;
  std::cout << "Rows? ";
  std::cin >> numRows;
  std::cout << convert(input, numRows) << std::endl;

  return 0;
}