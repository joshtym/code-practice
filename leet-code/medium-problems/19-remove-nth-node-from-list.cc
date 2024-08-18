/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

 

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz
 
Follow up: Could you do this in one pass?
*/

#include <stack>
#include <vector>

struct ListNode {
  int val = 0;
  ListNode* next = nullptr;
  ListNode() {}
  ListNode(int x) : val(x) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
  std::vector<ListNode*> nodes;

  while (head != nullptr) {
    nodes.push_back(head);
    head = head->next;
  }

  if (n != nodes.size())
    nodes[nodes.size() - n - 1]->next = n != 1 ? nodes[nodes.size() - n + 1] : nullptr;
  
  nodes.erase(nodes.end() - n);

  return nodes.size() > 0 ? nodes.front() : nullptr;
}

int main(int argc, char** argv) {
  return 0;
}