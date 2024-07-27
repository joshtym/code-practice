#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

 struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
  ListNode start;
  ListNode *tail = &start;
  bool hasRemainder = false;

  while (l1 != nullptr || l2 != nullptr) {
    int valOne = 0;
    int valTwo = 0;
    int total = 0;

    if (l1 != nullptr) {
      valOne = l1->val;
      l1 = l1->next;  
    }

    if (l2 != nullptr) {
      valTwo = l2->val;
      l2 = l2->next;
    }

    total = valOne + valTwo + hasRemainder;
    hasRemainder = total / 10 > 0;
    tail->next = new ListNode(total % 10);
    tail = tail->next;
  }

  if (hasRemainder) {
    tail->next = new ListNode(1);
  }

  return start.next;
}

void push(ListNode** head, int data)
{
    ListNode* new_node = new ListNode();
    new_node->val = data;
    new_node->next = (*head);
    (*head) = new_node;
}

int main(int argc, char** argv) {
    ListNode* res = nullptr;
    ListNode* a = nullptr;
    ListNode* b = nullptr;

    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
 
    push(&b, 9);
    push(&b, 9);
    push(&b, 9);
    push(&b, 9);
 
    res = addTwoNumbers(a, b);
 
    std::cout << "Merged Linked List is: \n";
    while (res != nullptr) {
      std::cout << res->val << " ";
      res = res->next;
    }
 
    return 0;
}