/*
A simple implementation of a hashmap in C++, using a bucket of pointers to
nodes. This implementation uses separate chaining for collision resolution and
traversal.
*/

#include <climits>
#include <iostream>

// a class to represent a node in the linked list key/value pair
class Node {

public:
  std::string key;
  int value;
  Node *next;

  //
  Node();
  Node(std::string, int);
  ~Node();
};

//? default constructor points next to nullptr.
Node::Node() {
  this->key = "";
  this->value = INT16_MIN;
  this->next = nullptr;
}

Node::Node(std::string key, int value) {
  this->key = key;
  this->value = value;
  this->next = nullptr;
}

Node::~Node() { std::cout << "node has been destroyed\n"; }
//

class hashmap {
private:
  //? a pointer-to-pointer array to create the 2D array for buckets.
  Node **map;
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
  int getSize();
  double loadFactor();

  // TODO implement a print2D()
  //  void print2D();
};

hashmap::hashmap() {
  this->capacity = 10;
  this->size = 0;

  //? allocate first block of memory
  map = new Node *[capacity];

  for (size_t i = 0; i < capacity; i++) {

    // assigned to null to prevent stray and dangling pointers.
    map[i] = nullptr;
  }
}

hashmap::hashmap(int size) {
  this->capacity = size;
  this->size = 0;

  //
  map = new Node *[capacity];

  for (size_t i = 0; i < capacity; i++) {

    // assigned to null to prevent stray and dangling pointers.
    map[i] = nullptr;
  }
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
  if (address < 0 || address >= capacity) {

    std::cout << "index cannot be calculated\n";
    return;
  }

  node->next = map[address];
  map[address] = node;
  ++this->size;

  std::cout << "(" << node->key << ", " << node->value
            << ") has been inserted \n";
}

void hashmap::lookUp(std::string key) {

  int address = hash(key);

  // wrong key combination
  if (address < 0 || address >= capacity) {

    std::cout << "index cannot be calculated\n";
    return;
  }

  Node *temp = map[address];

  while (temp) {

    if (temp->key == key) {
      std::cout << "(" << temp->key << ", " << temp->value << ")\n";
      return;
    }
    temp = temp->next;
  }

  std::cout << "not found\n";
}

void hashmap::updatePair(std::string key, int newValue) {

  int address = hash(key);

  // wrong key combination
  if (address < 0 || address >= capacity) {

    std::cout << "index cannot be calculated\n";
    return;
  }

  Node *temp = map[address];

  while (temp) {

    if (temp->key == key) {
      temp->value = newValue;
      std::cout << "node updated \n";
      return;
    }
    temp = temp->next;
  }

  std::cout << "node not found\n";
}

int hashmap::getValue(std::string key) {

  int address = hash(key);

  // wrong key combination
  if (address < 0 || address >= capacity) {

    std::cout << "index cannot be calculated\n";
    return INT16_MIN;
  }

  Node *temp = map[address];

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
  if (address < 0 || address >= capacity) {

    std::cout << "index cannot be calculated\n";
    return;
  }

  Node *temp = map[address];
  Node *prev = nullptr;

  // head node to be deleted
  if (temp->key == key) {

    map[address] = temp->next;
    delete temp;
    --this->size;

    std::cout << "head re-allocated\n";
    return;
  }

  while (temp) {

    if (temp->key == key) {

      prev->next = temp->next;
      std::cout << "pair has been detached \n";
      delete temp;
      --this->size;

      //
      return;
    }
    prev = temp;
    temp = temp->next;
  }

  // not found
  return;
}

int hashmap::getSize() { return this->size; }

//
double hashmap ::loadFactor() {
  return (double)this->size / (double)this->capacity;
}

//! deallocate the memory of the bucket/map.
hashmap::~hashmap() {

  // deallacote the memory of the hashmap bucket by bucket

  for (size_t i = 0; i < capacity; i++) {

    Node *current = map[i];
    while (current) {

      //? move the current node index to temp, jump to next node then delete
      // temp;
      Node *temp = current;
      current = current->next;
      --this->size;
      delete temp;
    }
  }

  //! should always done last.
  delete[] map;
  std::cout << " hashmap de-allocated from memory\n";
}

int main() {
  std::cout << "Hello, World!" << std::endl;

  //? for every "new" there must be a "delete"
  Node *node2 = new Node("mat", 23);
  Node *node1 = new Node("alex", 5);
  Node *node3 = new Node("ron", 0);
  Node *node4 = new Node("axel", 31);

  //
  hashmap hashset;
  hashset.insertPair(node1);

  std::cout << "size of hashmap is: " << hashset.getSize() << "\n";
  hashset.insertPair(node2);
  std::cout << "size of hashmap is: " << hashset.getSize() << "\n";
  hashset.updatePair("mat", 100);
  hashset.insertPair(node4);

  hashset.lookUp("ron");
  hashset.lookUp("axel");

  // delete node1, node2, node3, node4; //! keep this commented.
  return 0;
}