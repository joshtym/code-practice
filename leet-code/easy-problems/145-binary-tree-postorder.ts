/*
Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]
Output: [3,2,1]

Example 2:

Input: root = []
Output: []

Example 3:

Input: root = [1]
Output: [1]

 

Constraints:

    The number of the nodes in the tree is in the range [0, 100].
    -100 <= Node.val <= 100
*/
interface TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;
}

const TreeNode = (
  val?: number,
  left?: TreeNode | null,
  right?: TreeNode | null
) => {
  return {
    number: val ?? 0,
    left: left ?? null,
    right: right ?? null,
  };
};

const postorderTraversal = (root: TreeNode | null): number[] => {
  if (root === null) {
    return [];
  }

  const queue: TreeNode[] = [root];
  let traversedNodes = 0;

  while (traversedNodes < queue.length) {
    const index = queue.length - traversedNodes - 1;
    const node = queue[index];

    if (node.right) {
      queue.splice(index, 0, node.right);
    }

    if (node.left) {
      queue.splice(index, 0, node.left);
    }

    traversedNodes++;
  }

  return queue.map((val) => val.val);
};
