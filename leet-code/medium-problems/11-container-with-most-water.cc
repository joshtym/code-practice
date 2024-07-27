#include <iostream>
#include <vector>
#include<string>
#include <stdlib.h>

int maxArea(std::vector<int>& height) {
  int start = 0;
  int end = height.size() - 1;
  int area = 0;

  while (start < end) {
    area = std::max(area, std::min(height[start], height[end]) * (end - start));
    
    if (height[start] < height[end]) {
      start++;
    } else {
      end--;
    }
  }

  return area;
}

int main(int argc, char** argv) {
  std::vector<int> height;

  for (int i = 1; i < argc; ++i) {
    height.push_back(std::atoi(argv[i]));
  }

  std::cout << maxArea(height) << std::endl;

  return 0;
}