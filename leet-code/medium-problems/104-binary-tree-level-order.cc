/*
Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:

Input: root = [1]
Output: [[1]]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 2000].
    -1000 <= Node.val <= 1000


*/

#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

std::vector<std::vector<int>> levelOrder(TreeNode* root) {
  std::vector<std::vector<int>> nodes;

  if (root == nullptr)
    return nodes;
  
  std::queue<TreeNode*> queue;;

  queue.push(root);

  int nodesOnLevel = 1;
  int level = 0;

  while (!queue.empty()) {
    if (nodesOnLevel == 0) {
      nodesOnLevel = queue.size();
      level++;
    }

    TreeNode* node = queue.front();
    queue.pop();

    if (level == nodes.size())
      nodes.push_back(std::vector<int>(1, node->val));
    else
      nodes[level].push_back(node->val);

    nodesOnLevel--;
    
    if (node->left != nullptr)
      queue.push(node->left);

    if (node->right != nullptr)
      queue.push(node->right);
  }

  return nodes;
}

int main(int argc, char** argv) {
  return 0;
}