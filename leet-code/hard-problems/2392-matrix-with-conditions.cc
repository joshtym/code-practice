#include <iostream>
#include <vector>

std::vector<std::vector<int>> buildMatrix(int k, std::vector<std::vector<int>>& rowConditions, std::vector<std::vector<int>>& colConditions);

int main(int argc, char** argv) {
  int k = 3;
  std::vector<std::vector<int>> rowCons = { { 1, 2 }, { 3, 2 }};
  std::vector<std::vector<int>> colCons = { { 2, 1 }, { 3, 2 }};
  auto result = buildMatrix(k, rowCons, colCons);

  std::cout << "OUTPUT MATRIX HERE" << std::endl;

  return 0;
}

std::vector<std::vector<int>> buildMatrix(int k, std::vector<std::vector<int>>& rowConditions, std::vector<std::vector<int>>& colConditions) {
  std::vector<std::vector<int>> newRowCons(k, std::vector<int>(k, 0));

  // for (int i = 0; i < )
  return {};
}
