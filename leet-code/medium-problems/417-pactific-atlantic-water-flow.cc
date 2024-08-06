/*
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

Example 1:

Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.

Example 2:

Input: heights = [[1]]
Output: [[0,0]]
Explanation: The water can flow from the only cell to the Pacific and Atlantic oceans.

 

Constraints:

    m == heights.length
    n == heights[r].length
    1 <= m, n <= 200
    0 <= heights[r][c] <= 10^5

*/

#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> pactificAtlantic(std::vector<std::vector<int>>& heights) {
  struct Node {
    int val = 0;
    std::vector<std::pair<int, int>> flowEdges = {};
    bool touchesPacific = false;
    bool touchesAtlantic = false;
    bool visited = false;
  };

  std::vector<std::vector<Node>> nodes(heights.size(), std::vector<Node>(heights[0].size(), Node()));
  std::vector<std::vector<int>> touches;

  int rowIndex = 0;
  int columnIndex = 0;

  for (int i = 0; i < heights.size(); ++i)
    for (int j = 0; j < heights[i].size(); ++j) {
      nodes[i][j].val = heights[i][j];

      if (i == 0 || j == 0)
        nodes[i][j].touchesPacific = true;
      
      if (i == heights.size() - 1 || j == heights[i].size() - 1)
        nodes[i][j].touchesAtlantic = true;
      
      if (i > 0 && heights[i - 1][j] <= heights[i][j]) {
        nodes[i][j].flowEdges.push_back(std::pair(i - 1, j));
        nodes[i][j].touchesPacific = nodes[i - 1][j].touchesPacific || nodes[i][j].touchesPacific;
      }
      
      if (i < heights.size() - 1 && heights[i + 1][j] <= heights[i][j]) {
        nodes[i][j].flowEdges.push_back(std::pair(i + 1, j));
        nodes[i][j].touchesAtlantic = nodes[i + 1][j].touchesAtlantic || nodes[i][j].touchesAtlantic;
      }

      if (j > 0 && heights[i][j - 1] <= heights[i][j]) {
        nodes[i][j].flowEdges.push_back(std::pair(i, j - 1));
        nodes[i][j].touchesPacific = nodes[i][j - 1].touchesPacific || nodes[i][j].touchesPacific;
      }
      
      if (j < heights[i].size() - 1 && heights[i][j + 1] <= heights[i][j]) {
        nodes[i][j].flowEdges.push_back(std::pair(i, j + 1));
        nodes[i][j].touchesAtlantic = nodes[i][j + 1].touchesAtlantic || nodes[i][j].touchesAtlantic;
      }

      if (nodes[i][j].touchesAtlantic && nodes[i][j].touchesPacific) {
        nodes[i][j].visited = true;
        touches.push_back({ i, j });
      }
    }

  for (int i = 0; i < nodes.size(); ++i) {
    for (int j = 0; j < nodes[i].size(); ++j) {
      if (nodes[i][j].visited)
        continue;

      std::queue<std::pair<int, int>> queue;
      queue.push(std::pair(i, j));

      while (!queue.empty()) {
        std::pair<int, int> topCoords = queue.front();
        Node* top = &nodes[topCoords.first][topCoords.second];
        top->visited = true;

        queue.pop();

        for (int k = 0; k < top->flowEdges.size(); ++k) {
          std::pair<int, int> coords = top->flowEdges[k];
          Node nodeToExamine = nodes[coords.first][coords.second];

          top->touchesPacific = nodeToExamine.touchesPacific || nodes[i][j].touchesPacific;
          top->touchesAtlantic = nodeToExamine.touchesAtlantic || nodes[i][j].touchesAtlantic;

          if (top->touchesPacific && top->touchesAtlantic) {
            break;
          }
          
          if (!nodeToExamine.visited)
            queue.push(std::pair(coords.first, coords.second));
        }
      }
    }
  }

  
  return {};
}

void bfsForVisited(std::queue<std::pair<int, int>>& queue, std::vector<std::vector<int>>& heights, std::vector<std::vector<bool>>& visited) {
  while (!queue.empty()) {
    auto coords = queue.front();
    queue.pop();
    visited[coords.first][coords.second] = true;

    // Check four cardinal directions
    if (coords.first > 0 && !visited[coords.first - 1][coords.second] && heights[coords.first - 1][coords.second] >= heights[coords.first][coords.second])
      queue.push(std::pair(coords.first - 1, coords.second));
    
    if (coords.first < heights.size() - 1 && !visited[coords.first + 1][coords.second] && heights[coords.first + 1][coords.second] >= heights[coords.first][coords.second])
      queue.push(std::pair(coords.first + 1, coords.second));
    
    if (coords.second > 0 && !visited[coords.first][coords.second - 1] && heights[coords.first][coords.second - 1] >= heights[coords.first][coords.second])
      queue.push(std::pair(coords.first, coords.second - 1));
    
    if (coords.second < heights[0].size() - 1 && !visited[coords.first][coords.second + 1] && heights[coords.first][coords.second + 1] >= heights[coords.first][coords.second])
      queue.push(std::pair(coords.first, coords.second + 1));
  }
}

std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& heights) {
  std::vector<std::vector<bool>> visitedPacific(heights.size(), std::vector<bool>(heights[0].size(), false));
  std::vector<std::vector<bool>> visitedAtlantic(heights.size(), std::vector<bool>(heights[0].size(), false));

  // For each item in the first column, run BFS and set visisted pacific to true
  for (int i = 0; i < heights.size(); ++i) {
    visitedPacific[i][0] = true;

    std::queue<std::pair<int, int>> queue;

    if (heights[i].size() > 1 && !visitedPacific[i][1] && heights[i][1] >= heights[i][0])
      queue.push(std::pair(i, 1));

    bfsForVisited(queue, heights, visitedPacific);
  }

  // For each item in the last column, run BFS and set visisted atlantic to true
  for (int i = 0; i < heights.size(); ++i) {
    visitedAtlantic[i][heights[0].size() - 1] = true;

    std::queue<std::pair<int, int>> queue;

    if (heights[i].size() > 1 && !visitedAtlantic[i][heights[0].size() - 2] && heights[i][heights[0].size() - 2] >= heights[i][heights[0].size() - 1])
      queue.push(std::pair(i, heights[0].size() - 2));

    bfsForVisited(queue, heights, visitedAtlantic);
  }

  // For each item in the first row, run BFS and set visisted pacific to true
  for (int i = 0; i < heights[0].size(); ++i) {
    visitedPacific[0][i] = true;

    std::queue<std::pair<int, int>> queue;

    if (heights.size() > 1 && !visitedPacific[1][i] && heights[1][i] >= heights[0][i])
      queue.push(std::pair(1, i));

    bfsForVisited(queue, heights, visitedPacific);
  }

  // For each item in the last row, run BFS and set visisted atlantic to true
  for (int i = 0; i < heights[0].size(); ++i) {
    visitedAtlantic[heights.size() - 1][i] = true;

    std::queue<std::pair<int, int>> queue;

    if (heights.size() > 1 && !visitedAtlantic[heights.size() - 2][i] && heights[heights.size() - 2][i] >= heights[heights.size() - 1][i])
      queue.push(std::pair(heights.size() - 2, i));

    bfsForVisited(queue, heights, visitedAtlantic);
  }
  
  std::vector<std::vector<int>> touchesBoth;

  for (int i = 0; i < heights.size(); ++i)
    for (int j = 0; j < heights[i].size(); ++j)
      if (visitedAtlantic[i][j] && visitedPacific[i][j])
        touchesBoth.push_back({ i, j });

  return touchesBoth;
}

int main(int argc, char** argv) {
  std::vector<std::vector<int>> heights = {
    {}
  };

  auto result = pactificAtlantic(heights);

  for (int i = 0; i < result.size(); ++i) {
    std::cout << "[";

    for(int j = 0; j < result[i].size(); ++j)
      std::cout << result[i][j] << ",";
    
    std::cout << "]" << std::endl;
  }

  return 0;
}