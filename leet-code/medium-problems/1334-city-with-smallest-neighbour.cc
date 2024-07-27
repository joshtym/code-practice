#include <iostream>
#include <vector>

int findTheCity(int n, std::vector<std::vector<int>>& edges, int distanceThreshold) {
  std::vector<std::vector<int>> graph;
  for (int i = 0; i < n; ++i) {
    graph.push_back(std::vector<int>(n, 10001));
    graph[i][i] = 0;
  }

  for (auto edge : edges) {
    graph[edge[0]][edge[1]] = edge[2];
    graph[edge[1]][edge[0]] = edge[2];  
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (graph[i][j] > (graph[i][k] + graph[k][j]) && (graph[k][j] != 10001) && (graph[k][j] != 10001)) {
          graph[i][j] = graph[i][k] + graph[k][j];
        }
      }
    }
  }
 
  int city = -1;
  int numCities = 101;

  for (int i = 0; i < n; ++i) {
    int tmpNumCities = 0;
    int tmpTotalDistance = 0;

    for (int j = 0; j < n; ++j) {
      if (i != j && graph[i][j] <= distanceThreshold) {
        tmpNumCities++;
        tmpTotalDistance += graph[i][j];
      }
    }

    if (tmpNumCities <= numCities) {
      city = i;
      numCities = tmpNumCities;
    }
  }

  return city;
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> edges = {
    { 0, 1, 3 },
    { 1, 2, 1 },
    { 1, 3, 4 },
    { 2, 3, 1 }
  };

  int distanceThreshold = 4;
  int nodes = 4;

  std::cout << findTheCity(nodes, edges, distanceThreshold) << std::endl;;

  return 0;
}