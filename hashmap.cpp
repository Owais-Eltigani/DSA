/*
A simple implementation of a hashmap in C++.
This implementation uses separate chaining for collision resolution.
*/

#include <iostream>

// a class to represent a node in the linked list key/value pair
class Node {

public:
  std::string key;
  int value;
  Node *next;

  //
  Node();
  Node(int value, std::string key);
  ~Node();
};

//? default constructor points next to nullptr.
Node::Node() {
  this->key = "";
  this->value = INT16_MIN;
  this->next = nullptr;
}

Node::~Node() {}
Node::Node(int value, std::string key) {
  this->key = key;
  this->value = value;
  this->next = nullptr;
}

//

class hashmap {
private:
  Node *map;
  int size;
  int capacity;
  int hash(std::string key);

public:
  hashmap();
  hashmap(int size);
  ~hashmap();

  //* method prototypes "declaration"
  void insertPair(Node *node);
  void lookUp(std::string key);
  void updatePair(std::string key, int newValue);
  void deletePair(std::string key);
  int getValue(std::string key);

  // TODO implement a print2D()
  //  void print2D();
};

hashmap::hashmap(/* args */) {
  this->capacity = 10;
  this->size = 0;
  map = new Node[capacity];
}

hashmap::hashmap(int size) {
  this->capacity = size;
  this->size = 0;
  map = new Node[capacity];
}

//? calculating the hash value by the sum of ascii values.
int hashmap::hash(std::string key) {

  int sum = 0;
  for (size_t i = 0; i < key.length(); i++) {
    char letter = key[i];
    sum += int(letter);
  }

  return sum % capacity; // direct access to member "capacity"
}

//? append the new node at the start of the bucket list big O(1).
void hashmap::insertPair(Node *node) {

  // get the memory address and head of bucket;
  int address = hash(node->key);

  // wrong key combination
  if (address < 0 || address > capacity)
    return;

  Node *temp = map[address].next;
  node->next = temp;
  temp = node;

  std::cout << "(" << node->key << ", " << node->value
            << ") has been inserted \n";
}

void hashmap::lookUp(std::string key) {

  int address = hash(key);

  // wrong key combination
  if (address < 0 || address > capacity)
    return;

  Node *temp = map[address].next;

  while (temp) {

    if (temp->key == key) {
      std::cout << "(" << temp->key << ", " << temp->value << ")\n";
      return;
    }
    temp = temp->next;
  }
}

void hashmap::updatePair(std::string key, int newValue) {

  int address = hash(key);

  // wrong key combination
  if (address < 0 || address > capacity)
    return;

  Node *temp = map[address].next;

  while (temp) {

    if (temp->key == key) {
      temp->value = newValue;
      std::cout << "node updated \n";
      return;
    }
    temp = temp->next;
  }
}

int hashmap::getValue(std::string key) {

  int address = hash(key);

  // wrong key combination
  if (address < 0 || address > capacity)
    return INT16_MIN;

  Node *temp = map[address].next;

  while (temp) {

    if (temp->key == key) {
      return temp->value;
    }
    temp = temp->next;
  }

  // not found
  return INT16_MIN;
}

void hashmap::deletePair(std::string key) {

  int address = hash(key);

  // wrong key combination
  if (address < 0 || address > capacity)
    return;

  Node *temp = map[address].next;
  Node *prev = nullptr;

  while (temp) {

    if (temp->key == key) {

      prev->next = temp->next;
      std::cout << "pair has been detached \n";
      return;
    }
    prev = temp;
    temp = temp->next;
  }

  // not found
  return;
}

//! deallocate the memory of the bucket/map.
hashmap::~hashmap() { delete[] this->map; }

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}