/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:

Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

 

Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 5000
    0 <= Node.val <= 1000

 

Follow-up: Can you solve the problem in O(1) extra memory space?
*/
#include <iostream>

struct ListNode {
  int val = 0;
  ListNode* next = nullptr;
  ListNode() {}
  ListNode(int x) : val(x) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
  if (k == 1)
    return head;
  
  int totalPasses = 0;
  ListNode* tmpHead = head;

  while (tmpHead != nullptr) {
    totalPasses++;
    tmpHead = tmpHead->next;
  }

  totalPasses /= k;

  ListNode* newHead = nullptr;
  ListNode* lastTail = nullptr;

  for (int i = 0; i < totalPasses; ++i) {
    int numNodes = 0;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* tail = head;

    while (numNodes++ < k) {
      next = head->next;
      head->next = prev;
      prev = head;
      
      if (numNodes == k) {
        if (lastTail == nullptr)
          newHead = head;
        else
          lastTail->next = head;
        
        lastTail = tail;
      }
      head = next;
    }
  }
  lastTail->next = head;

  return newHead;
}

int main(int argc, char** argv) {
  ListNode five(5);
  ListNode four(4, &five);
  ListNode three(3, &four);
  ListNode two(2, &three);
  ListNode one(1, &two);

  ListNode* newHead = reverseKGroup(&one, 2);

  while (newHead != nullptr) {
    std::cout << newHead->val << ",";
    newHead = newHead->next;
  }
  std::cout << std::endl;

  return 0;
}