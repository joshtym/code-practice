// A city is represented as a bi-directional connected graph with n vertices where each vertex is labeled from 1 to n (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself. The time taken to traverse any edge is time minutes.

// Each vertex has a traffic signal which changes its color from green to red and vice versa every change minutes. All signals change at the same time. You can enter a vertex at any time, but can leave a vertex only when the signal is green. You cannot wait at a vertex if the signal is green.

// The second minimum value is defined as the smallest value strictly larger than the minimum value.

//     For example the second minimum value of [2, 3, 4] is 3, and the second minimum value of [2, 2, 4] is 4.

// Given n, edges, time, and change, return the second minimum time it will take to go from vertex 1 to vertex n.

// Notes:

//     You can go through any vertex any number of times, including 1 and n.
//     You can assume that when the journey starts, all signals have just turned green.

 

// Example 1:
// Input: n = 5, edges = [[1,2],[1,3],[1,4],[3,4],[4,5]], time = 3, change = 5
// Output: 13
// Explanation:
// The figure on the left shows the given graph.
// The blue path in the figure on the right is the minimum time path.
// The time taken is:
// - Start at 1, time elapsed=0
// - 1 -> 4: 3 minutes, time elapsed=3
// - 4 -> 5: 3 minutes, time elapsed=6
// Hence the minimum time needed is 6 minutes.

// The red path shows the path to get the second minimum time.
// - Start at 1, time elapsed=0
// - 1 -> 3: 3 minutes, time elapsed=3
// - 3 -> 4: 3 minutes, time elapsed=6
// - Wait at 4 for 4 minutes, time elapsed=10
// - 4 -> 5: 3 minutes, time elapsed=13
// Hence the second minimum time is 13 minutes.      

// Example 2:
// Input: n = 2, edges = [[1,2]], time = 3, change = 2
// Output: 11
// Explanation:
// The minimum time path is 1 -> 2 with time = 3 minutes.
// The second minimum time path is 1 -> 2 -> 1 -> 2 with time = 11 minutes.

// Constraints:

//     2 <= n <= 104
//     n - 1 <= edges.length <= min(2 * 104, n * (n - 1) / 2)
//     edges[i].length == 2
//     1 <= ui, vi <= n
//     ui != vi
//     There are no duplicate edges.
//     Each vertex can be reached directly or indirectly from every other vertex.
//     1 <= time, change <= 103
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

/*
 The solution below 'works' but is mostly overkill and exceeds memory bandwidth. Simplified solution provided
*/

struct Node {
  int id;
  std::vector<int> adjacentNodes;
  std::queue<int> numOfPrevNodesOnVisit;
};

Node* constructNodes(int n, std::vector<std::vector<int>>& edges) {
  Node* nodes = new Node[n + 1];

  for (int i = 1; i <= n; ++i)
    nodes[i].id = i;
  
  for (auto edge : edges) {
    nodes[edge[0]].adjacentNodes.push_back(edge[1]);
    nodes[edge[1]].adjacentNodes.push_back(edge[0]);
  }

  return nodes;
}

int calculateDistance(int time, int change, int numNodesOnLastVisit) {
  int distance = 0;

  for (int i = 1; i <= numNodesOnLastVisit; ++i) {
    distance += time;

    if (i != numNodesOnLastVisit && ((distance / change) % 2 != 0)) {
      distance += (change - (distance % change));
    }
  }

  return distance;
}

int secondMinimum(int n, std::vector<std::vector<int>>& edges, int time, int change) {
  Node* nodes = constructNodes(n, edges);
  int minDistance = -1;

  std::queue<int> queue;
  nodes[1].numOfPrevNodesOnVisit.push(0);
  queue.push(1);

  while (true) {
    int nodeNum = queue.front();
    queue.pop();

    int previousNodes = nodes[nodeNum].numOfPrevNodesOnVisit.front() + 1;
    nodes[nodeNum].numOfPrevNodesOnVisit.pop();

    

    for (int adjacentNodeNum : nodes[nodeNum].adjacentNodes) {
      nodes[adjacentNodeNum].numOfPrevNodesOnVisit.push(previousNodes);

      if (adjacentNodeNum == n && minDistance == -1) {
        minDistance = calculateDistance(time, change, previousNodes);
      } else if (adjacentNodeNum == n) {
        int newDistance = calculateDistance(time, change, previousNodes);

        if (newDistance > minDistance)
          return newDistance;
      }

      queue.push(adjacentNodeNum);
    }
  }

  return -1;
}

int secondMinimumSimplified(int n, std::vector<std::vector<int>>& edges, int time, int change) {
  std::vector<std::vector<int>> adj(n+ 1);

  for (auto edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }

  std::queue<std::pair<int, int>> queue;
  std::vector<int> distanceOne(n + 1, -1);
  std::vector<int> distanceTwo(n + 1, -1);

  queue.push({ 1, 1 });
  distanceOne[1] = 0;

  while (!queue.empty()) {
    auto [nodeNum, frequency] = queue.front();
    queue.pop();

    int timeTaken = frequency == 1 ? distanceOne[nodeNum] : distanceTwo[nodeNum];

    if ((timeTaken / change) % 2) {
      timeTaken = change * (timeTaken / change + 1) + time;
    } else {
      timeTaken = timeTaken + time;
    }

    for (auto& neighbour : adj[nodeNum]) {
      if (distanceOne[neighbour] == -1) {
        distanceOne[neighbour] = timeTaken;
        queue.push({ neighbour, 1 });
      } else if (distanceTwo[neighbour] == -1 && distanceOne[neighbour] != timeTaken) {
        if (neighbour == n)
          return timeTaken;
        
        distanceTwo[neighbour] = timeTaken;
        queue.push({ neighbour, 2 });
      }
    }
  }

  return 0;
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> edges = {
    { 1, 2 },
    { 1, 3 },
    { 1, 4 },
    { 3, 4 },
    { 4, 5 }
  };
  // std::vector<std::vector<int>> edges = {
  //   { 1, 2 }
  // };
  int time = 3;
  int change = 5;
  int n = 5;

  std::cout << secondMinimumSimplified(n, edges, time, change) << std::endl;

  return 0;
}