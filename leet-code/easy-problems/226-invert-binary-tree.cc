/*
Given the root of a binary tree, invert the tree, and return its root.

 

Example 1:

Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:

Input: root = [2,1,3]
Output: [2,3,1]

Example 3:

Input: root = []
Output: []

 

Constraints:

    The number of nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100

*/

#include <queue>

 struct TreeNode {
  int val = 0;
  TreeNode* left = nullptr;
  TreeNode* right = nullptr;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
 };

TreeNode* invertTree(TreeNode* root) {
  std::queue<TreeNode*> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    TreeNode* node = nodes.front();
    nodes.pop();

    if (node != nullptr) {
      TreeNode* tmp = node->right;
      node->right = node->left;
      node->left = tmp;
      nodes.push(node->left);
      nodes.push(node->right);
    }
  }

  return root;
}

int main(int argc, char** argv) {
  return 0;
}