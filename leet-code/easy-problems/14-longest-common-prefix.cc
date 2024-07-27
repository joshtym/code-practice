#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

std::string determineLongestCommonPrefixBrute(std::vector<std::string>& strs) {
  std::string prefix = "";
  int size = 1;

  while (size <= strs[0].length()) {
    bool samePrefix = true;

    for (int i = 1; i < strs.size(); ++i) {
      if (strs[i].length() < size || strs[i].substr(0, size) != strs[0].substr(0, size)) {
        samePrefix = false;
        break;
      }
    }

    if (samePrefix) {
      prefix = strs[0].substr(0, size++);
    } else {
      break;
    }
  }

  return prefix;
}

std::string longestCommonPrefixSmart(std::vector<std::string>& strs) {
  std::string prefix = "";
  std::sort(strs.begin(), strs.end());
  std::string first = strs[0], last = strs[strs.size() - 1];

  for (int i = 0; i < std::min(first.size(), last.size()); ++i) {
    if (first[i] != last[i]) {
      return prefix;
    }
    prefix += first[i];
  }

  return prefix;
}

int main(int argc, char** argv) {
  std::vector<std::string> input;

  for (int i = 1; i < argc; ++i) {
    std::string s(argv[i]);
    input.push_back(s);
  }

  std::cout << longestCommonPrefixSmart(input) << std::endl;

  return 0;
}