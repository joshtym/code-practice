#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

int strStr(std::string haystack, std::string needle) {
  int stringsToCompare = haystack.length() - needle.length() + 1;

  for (int i = 0; i < stringsToCompare; ++i) {
    if (haystack.substr(i, needle.length()) == needle) {
      return i;
    }
  }

  return -1;
}

int main(int argc, char** argv) {
  std::string haystack = argv[1];
  std::string needle = "";

  if (argc > 2) {
    needle = argv[2];
  }

  std::cout << strStr(haystack, needle) << std::endl;

  return 0;
}