#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>
#include <unordered_map>
#include <set>

bool isValidSubstr(std::string s) {
  std::set<char> characters;

  for (int i = 0; i < s.length(); ++i) {
    if (characters.find(s[i]) != characters.end()) {
      return false;
    } else {
      characters.insert(s[i]);
    }
  }

  return true;
}

int lengthOfLongestSubstringBrute(std::string s) {
  for (int i = s.length(); i >= 0; --i) {
    for (int j = 0; j <= s.length() - i; ++j) {
      if (isValidSubstr(s.substr(j, i))) {
        return i;
      }
    }
  }

  return 0;
}

int lengthOfLongestSubstring(std::string s) {
  bool visited[256] = { false };
  int left = 0;
  int right = 0;
  int maxLength = 0;

  if (s.length() <= 1) {
    return s.length();
  }

  while (right < s.length()) {
    if (visited[s[right]]) {
      while (visited[s[right]]) {
        visited[s[left]] = false;
        left++;
      }
    }

    visited[s[right]] = true;
    maxLength = std::max(maxLength, right-left + 1);
    right++;
  }

  return maxLength;
}

int main(int argc, char** argv) {
  std::string input;
  std::cout << "Input? ";
  std::cin >> input;
  std::cout << lengthOfLongestSubstring(input) << std::endl;

  return 0;
}