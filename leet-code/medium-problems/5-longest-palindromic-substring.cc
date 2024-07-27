#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

std::string longestPalindromeAlt(std::string s) {
  int start = 0;
  int size = 1;
  int lower, higher;

  for (int i = 0; i < s.length(); ++i) {
    // Even strings
    lower = i - 1; higher = i;

    while (lower >= 0 && higher < s.length() && s[lower] == s[higher]) {
      if ((higher - lower + 1) > size) {
        start = lower;
        size = higher - lower + 1;
      }
      lower--;
      higher++;
    }

    // Odd strings
    lower = i - 1; higher = i + 1;

    while (lower >= 0 && higher < s.length() && s[lower] == s[higher]) {
      if ((higher - lower + 1) > size) {
        start = lower;
        size = higher - lower + 1;
      }
      lower--;
      higher++;
    }
  }

  return s.substr(start, size);
}

std::string longestPalindromeDP(std::string s) {
  bool palindromes[1001][1001];

  memset(palindromes, 0, sizeof(palindromes));

  for (int i = 0; i < 1001; ++i) {
    palindromes[i][i] = true;
  }

  int maxLength = 1;
  int start = 0;

  if (s.length() <= 1) {
    return s;
  }

  // Check substrings of length 2
  for (int i = 0; i < s.length() - 1; ++i) {
    if (s[i] == s[i + 1]) {
      palindromes[i][i + 1] = true;
      start = i;
      maxLength = 2;
    }
  }

  // Check all other substrings
  for (int i = 3; i <= s.length(); ++i) {
    for (int startIndex = 0; startIndex < s.length() - i + 1; ++startIndex) {
      int endIndex = i + startIndex - 1;

      if (palindromes[startIndex + 1][endIndex - 1] && s[startIndex] == s[endIndex]) {
        palindromes[startIndex][endIndex] = true;

        if (i > maxLength) {
          start = startIndex;
          maxLength = i;
        }
      }
    }
  }

  return s.substr(start, maxLength);
}

int main(int argc, char** argv) {
  std::string input;
  std::cout << "Input? ";
  std::cin >> input;
  std::cout << longestPalindromeAlt(input) << std::endl;

  return 0;
}