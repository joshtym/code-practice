/*
Given the head of a linked list, return the list after sorting it in ascending order.

 

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:

Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is in the range [0, 5 * 10^4].
    -10^5 <= Node.val <= 10^5

 

Follow up: Can you sort the linked list in O(n logn) time and O(1) memory (i.e. constant space)?
*/

#include <iostream>
#include <vector>

struct ListNode {
  int val = 0;
  ListNode* next = nullptr;
  ListNode() {}
  ListNode(int x): val(x) {}
  ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* sortList(ListNode* head) {
  // To answer the follow up, we can use pointers and merge sort to sort in place
}

ListNode* sortListCheat(ListNode* head) {
  std::vector<int> list;
  ListNode* ogHead = head;

  while (head != nullptr) {
    list.push_back(head->val);
    head = head->next;
  }

  std::sort(list.begin(), list.end());
  head = ogHead;

  for (int num : list) {
    head->val = num;
    head = head->next;
  }

  return ogHead;
}

int main(int argc, char** argv) {

}