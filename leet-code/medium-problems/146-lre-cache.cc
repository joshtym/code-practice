/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

 

Constraints:

    1 <= capacity <= 3000
    0 <= key <= 10^4
    0 <= value <= 10^5
    At most 2 * 10^5 calls will be made to get and put.
*/

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

struct Node {
  int key = -1;
  int value = -1;
  Node* previous = nullptr;
  Node* next = nullptr;
};

class LRUCache {
  private:
    int capacity = 1;
    int numElements = 0;
    Node* head = new Node();
    Node* tail = new Node();;
    std::unordered_map<int, Node*> hashMap;

    void addNode(Node* newNode) {
      Node* temp = head->next;

      newNode->next = temp;
      newNode->previous = head;

      head->next = newNode;
      temp->previous = newNode;
    }

    void deleteNode(Node* oldNode) {
      Node* previous = oldNode->previous;
      Node* next = oldNode->next;

      previous->next = next;
      next->previous = previous;
    }

  public:
    LRUCache() {
      head->next = tail;
      tail->previous = head;
    }

    LRUCache(int capacity) {
      this->capacity = capacity;
      head->next = tail;
      tail->previous = head;
    }

    ~LRUCache() {
      delete head;
      delete tail;
    }

    int get(int key) {
      if (hashMap.find(key) != hashMap.end()) {
        Node* node = hashMap[key];
        int value = node->value;

        hashMap.erase(key);
        deleteNode(node);
        addNode(node);

        hashMap[key] = head->next;

        return value;
      }

      return -1;
    }

    void put(int key, int value) {
      if (hashMap.find(key) != hashMap.end()) {
        Node* node = hashMap[key];
        hashMap.erase(key);
        deleteNode(node);
      }

      if (hashMap.size() == capacity) {
        hashMap.erase(tail->previous->key);
        deleteNode(tail->previous);
      }

      Node* newNode = new Node();
      newNode->key = key;
      newNode->value = value;

      addNode(newNode);
      hashMap[key] = head->next;
    }
};

int main(int argc, char** argv) {
  enum Instructions { LRUCACHE, PUT, GET };
  LRUCache* cache = nullptr;

  std::vector<Instructions> instructions = { 
    Instructions::LRUCACHE,
    Instructions::PUT,
    Instructions::PUT,
    Instructions::GET,
    Instructions::PUT,
    Instructions::GET,
    Instructions::PUT,
    Instructions::GET,
    Instructions::GET,
    Instructions::GET
  };

  std::vector<std::vector<int>> values = {
    { 2 },
    { 1, 1 },
    { 2, 2 },
    { 1 },
    { 3, 3 },
    { 2 },
    { 4, 4 },
    { 1 },
    { 3 },
    { 4 }
  };

  for (int i = 0; i < instructions.size(); ++i) {
    switch (instructions[i]) {
      case Instructions::LRUCACHE:
        cache = new LRUCache(values[i][0]);
        break;
      case Instructions::PUT:
        cache->put(values[i][0], values[i][1]);
        break;
      case Instructions::GET:
        std::cout << cache->get(values[i][0]) << std::endl;
        break;
      default:
        break;
    }
  }

  return 0;
}