#include <iostream>
#include <vector>
#include <string>

long long minimumCost(std::string source, std::string target, std::vector<char>& original, std::vector<char>& changed, std::vector<int>& cost) {
  long long distance[26][26];
  const long long MAX = 26000001;

  for (int i = 0; i < 26; ++i)
    for (int j = 0; j < 26; ++j)
      distance[i][j] = i == j ? 0 : MAX;

  for (int i = 0; i < cost.size(); ++i) {
    int originalCharacterIndex = original[i] - 97;
    int changedCharacterIndex = changed[i] - 97;

    long long derps = cost[i];

    distance[originalCharacterIndex][changedCharacterIndex] = std::min(distance[originalCharacterIndex][changedCharacterIndex], (long long)cost[i]);
  }

  for (int k = 0; k < 26; ++k)
    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j)
        if (distance[i][j] > (distance[i][k] + distance[k][j]) && (distance[i][k] != MAX) && (distance[k][j] != MAX))
          distance[i][j] = distance[i][k] + distance[k][j];

  long long minimumCost = 0;

  for (int i = 0; i < source.length(); ++i) {
    if (distance[source[i] - 97][target[i] - 97] == MAX) {
      return -1;
    }
    
    minimumCost += distance[source[i] - 97][target[i] - 97];
  }
  
  return minimumCost;
}

int main(int argc, char** argv) {
  std::string source = "abcd";
  std::string target = "acbe";
  std::vector<char> original = { 'a', 'b', 'c', 'c', 'e', 'd' };
  std::vector<char> changed = { 'b', 'c', 'b', 'e', 'b', 'e' };
  std::vector<int> cost = { 2, 5, 5, 1, 2, 20 };

  std::cout << minimumCost(source, target, original, changed, cost) << std::endl;

  return 0;
}