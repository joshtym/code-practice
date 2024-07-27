#include <iostream>
#include <vector>
#include <string>

int partition(std::vector<int>& heights, std::vector<std::string>& names, int low, int high) {
  int pivot = heights[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; ++j) {
    if (heights[j] > pivot) {
      i++;
      std::swap(heights[i], heights[j]);
      std::swap(names[i], names[j]);
    }
  }
  std::swap(heights[i + 1], heights[high]);
  std::swap(names[i + 1], names[high]);
  return (i + 1);
}

void quickSort(std::vector<int>& heights, std::vector<std::string>& names, int low, int high) {
  if (low < high) {
    int pi = partition(heights, names, low, high);
    quickSort(heights, names, low, pi - 1);
    quickSort(heights, names, pi + 1, high);
  }
}

std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
  quickSort(heights, names, 0, heights.size() - 1);
  return names;
}

int main(int argc, char** argv) {
  std::vector<std::string> names = { "Alice", "Bob", "Bob" };
  std::vector<int> heights = { 155, 185, 150 };

  std::vector<std::string> sortedNames = sortPeople(names, heights);

  for (auto name : sortedNames) {
    std::cout << name << " ";
  }
  std::cout << std::endl;

  return 0;
}