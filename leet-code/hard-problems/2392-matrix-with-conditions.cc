/*
You are given a positive integer k. You are also given:

    a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
    a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].

The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

    The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
    The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.

Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

 

Example 1:

Input: k = 3, rowConditions = [[1,2],[3,2]], colConditions = [[2,1],[3,2]]
Output: [[3,0,0],[0,0,1],[0,2,0]]
Explanation: The diagram above shows a valid example of a matrix that satisfies all the conditions.
The row conditions are the following:
- Number 1 is in row 1, and number 2 is in row 2, so 1 is above 2 in the matrix.
- Number 3 is in row 0, and number 2 is in row 2, so 3 is above 2 in the matrix.
The column conditions are the following:
- Number 2 is in column 1, and number 1 is in column 2, so 2 is left of 1 in the matrix.
- Number 3 is in column 0, and number 2 is in column 1, so 3 is left of 2 in the matrix.
Note that there may be multiple correct answers.

Example 2:

Input: k = 3, rowConditions = [[1,2],[2,3],[3,1],[2,3]], colConditions = [[2,1]]
Output: []
Explanation: From the first two conditions, 3 has to be below 1 but the third conditions needs 3 to be above 1 to be satisfied.
No matrix can satisfy all the conditions, so we return the empty matrix.

 

Constraints:

    2 <= k <= 400
    1 <= rowConditions.length, colConditions.length <= 104
    rowConditions[i].length == colConditions[i].length == 2
    1 <= abovei, belowi, lefti, righti <= k
    abovei != belowi
    lefti != righti


*/
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

std::vector<std::vector<int>> buildMatrix(int k, std::vector<std::vector<int>>& rowConditions, std::vector<std::vector<int>>& colConditions) {
  struct Node {
    int val = 0;
    int numIncomingRows = 0;
    int numIncomingColumns = 0;
    std::vector<int> outgoingEdgesRows = {};
    std::vector<int> outgoingEdgesCols = {};
  };

  std::vector<Node> nodes(k + 1); // Node zero is nothing
  std::vector<std::vector<int>> matrix(k, std::vector<int>(k));
  std::unordered_map<int, std::pair<int, int>> nodeToIndex;
  std::queue<int> processNextRows;
  std::queue<int> processNextColumns;
  int rowIndex = 0;
  int colIndex = 0;

  // Set the node values
  for (int i = 1; i <=k; ++i)
    nodes[i].val = i;
  
  // Set all of the restraints
  for (int i = 0; i < rowConditions.size(); ++i) {
    nodes[rowConditions[i][1]].numIncomingRows++;
    nodes[rowConditions[i][0]].outgoingEdgesRows.push_back(rowConditions[i][1]);
  }

  for (int i = 0; i < colConditions.size(); ++i) {
    nodes[colConditions[i][1]].numIncomingColumns++;
    nodes[colConditions[i][0]].outgoingEdgesCols.push_back(colConditions[i][1]);
  }

  // Initialize map
  for (int i = 1; i <=k; ++i)
    nodeToIndex[i] = std::pair(-1, -1);
  
  // Start the process by adding all the reqs
  for (int i = 1; i < nodes.size(); ++i) {
    if (nodes[i].numIncomingRows == 0)
      processNextRows.push(i);
    if (nodes[i].numIncomingColumns == 0)
      processNextColumns.push(i);
  }
  
  // Process node ordering for rows
  while (!processNextRows.empty()) {
    int nodeNum = processNextRows.front();
    processNextRows.pop();

    nodeToIndex[nodeNum].first = rowIndex++;

    for (int i = 0; i < nodes[nodeNum].outgoingEdgesRows.size(); ++i) {
      int outgoingNodeNum = nodes[nodeNum].outgoingEdgesRows[i];
      nodes[outgoingNodeNum].numIncomingRows--;

      if (nodes[outgoingNodeNum].numIncomingRows == 0)
        processNextRows.push(outgoingNodeNum);
    }
  }

  // Process node ordering for columns
  while (!processNextColumns.empty()) {
    int nodeNum = processNextColumns.front();
    processNextColumns.pop();

    nodeToIndex[nodeNum].second = colIndex++;

    for (int i = 0; i < nodes[nodeNum].outgoingEdgesCols.size(); ++i) {
      int outgoingNodeNum = nodes[nodeNum].outgoingEdgesCols[i];
      nodes[outgoingNodeNum].numIncomingColumns--;

      if (nodes[outgoingNodeNum].numIncomingColumns == 0)
        processNextColumns.push(outgoingNodeNum);
    }
  }
  
  // Construct actual matrix. If any of the indices were not able to be applied, then we just return an empty matrix
  for (auto t : nodeToIndex) {
    if (t.second.first == -1 || t.second.second == -1)
      return {};
    
    matrix[t.second.first][t.second.second] = t.first;
  }

  return matrix;
}

int main(int argc, char** argv) {
  int k = 3;
  std::vector<std::vector<int>> rowCons = { { 1, 2 }, { 3, 2 }};
  std::vector<std::vector<int>> colCons = { { 2, 1 }, { 3, 2 }};
  auto result = buildMatrix(k, rowCons, colCons);

  std::cout << "OUTPUT MATRIX HERE" << std::endl;

  return 0;
}
