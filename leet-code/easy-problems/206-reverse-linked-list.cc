/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:

Input: head = [1,2]
Output: [2,1]

Example 3:

Input: head = []
Output: []

 

Constraints:

    The number of nodes in the list is the range [0, 5000].
    -5000 <= Node.val <= 5000

 

Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?

*/

#include <iostream>

struct ListNode {
  int val;
  ListNode* next;
  ListNode(): val(0), next(nullptr) {}
  ListNode(int x): val(x), next(nullptr) {}
  ListNode(int x, ListNode* next): val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
  ListNode* newHead = nullptr;

  while (head != nullptr) {
    ListNode* tmp = new ListNode(head->val, newHead);
    newHead = tmp;
    head = head->next;
  }

  return newHead;
}

int main(int argc, char** argv) {
  ListNode five = ListNode(5);
  ListNode four = ListNode(4, &five);
  ListNode three = ListNode(3, &four);
  ListNode two = ListNode(2, &three);
  ListNode one = ListNode(1, &two);

  auto newHead = reverseList(&one);

  while (newHead != nullptr) {
    std::cout << newHead->val << ", ";
    newHead = newHead->next;
  }
  
  std::cout << std::endl;

  return 0;
}