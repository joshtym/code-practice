/*
Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

 

Example 1:

Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:

Input: root = [1,null,2]
Output: 2

 

Constraints:

    The number of nodes in the tree is in the range [0, 10^4].
    -100 <= Node.val <= 100

*/
#include <iostream>

struct TreeNode {
  int val = 0;
  TreeNode *left = nullptr;
  TreeNode *right = nullptr;

  TreeNode(int x): val(x) {}
  TreeNode(int x, TreeNode* left, TreeNode* right): val(x), left(left), right(right) {}
};

int maxDepth(TreeNode* root) {
  int maxHeight = 0;

  if (root == nullptr)
    return maxHeight;
  
  maxHeight = std::max(maxDepth(root->left) + 1, maxHeight);
  maxHeight = std::max(maxDepth(root->right) + 1, maxHeight);

  return maxHeight;
}

int main(int argc, char** argv) {
  TreeNode nodeOne = TreeNode(15);
  TreeNode nodeTwo = TreeNode(7);
  TreeNode nodeThree = TreeNode(20, &nodeOne, &nodeTwo);
  TreeNode nodeFour = TreeNode(9);
  TreeNode root = TreeNode(3, &nodeFour, &nodeThree);
  std::cout << maxDepth(&root) << std::endl;

  return 0;
}