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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode dummy;
    ListNode* tail = &dummy;
    dummy.next = nullptr;

    while (1) {
        if (list1 == nullptr) {
            tail->next = list2;
            break;
        }
        
        if (list2 == nullptr) {
            tail->next = list1;
            break;
        }

        ListNode** source;
        ListNode* newNode;
        ListNode** destination = &(tail->next);

        if (list1->val <= list2->val) {
          source = &list1;
        } else {
          source = &list2;
        }

        newNode = *source;
        *source = newNode->next;
        newNode->next = nullptr;
        *destination = newNode;
 
        tail = tail->next;
    }
    return dummy.next;
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

    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
 
    push(&b, 20);
    push(&b, 3);
    push(&b, 2);
 
    res = mergeTwoLists(a, b);
 
    std::cout << "Merged Linked List is: \n";
    while (res != nullptr) {
      std::cout << res->val << " ";
      res = res->next;
    }
 
    return 0;
}