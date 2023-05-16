#include <iostream>
using namespace std;
class Node {
public:
  int data, key;
  Node *next;
  Node();
  Node(int, int);
};

class LinkedList {
private:
  Node *head;

public:
  LinkedList();
  LinkedList(Node *);
  Node *doesNodeExist(int);
  void appendNode(Node *);
  void prependNode(Node *);
  void insertNode(int, Node *);
  void deleteNode(int);
  void updateNode(int, int);
  void print(int);
  void print();
};

int main() {
  Node *n;
  n = new Node(1, 10);
  LinkedList s(n);
  n = new Node(2, 100);
  s.appendNode(n);
  s.print();
}

Node::Node() {
  this->data = 0;
  this->key = 0;
  this->next = NULL;
}
Node::Node(int key, int data) {
  this->data = data;
  this->key = key;
  next = NULL;
}

LinkedList::LinkedList(Node *node) { head->next = node; }

LinkedList::LinkedList() { head->next = NULL; }
Node *LinkedList::doesNodeExist(int key) {
  Node *ptr = head->next;
  while (ptr != NULL)
    if (ptr->key == key)
      return ptr;
    else
      ptr = ptr->next;
  return ptr;
}
void LinkedList::appendNode(Node *node) {
  Node *ptr = head->next;
  while (ptr->next)
    ptr = ptr->next;
  ptr->next = node;
  cout << " node appended" << endl;
}
void LinkedList::prependNode(Node *node) {
  Node *ptr = head->next;
  head->next = node;
  node->next = ptr;
  cout << "node is prepended" << endl;
}
void LinkedList::insertNode(int key, Node *node) {
  Node *ptr = doesNodeExist(key);
  if (ptr) {
    node->next = ptr->next;
    ptr->next = node;
    cout << "the node is inserted" << endl;
  } else {
    cout << "node with key " << key << " not found " << endl;
  }
}
void LinkedList::deleteNode(int key) {
  Node *ptr = doesNodeExist(key);
  if (ptr) {
    Node *temp = head->next;
    while (temp->next != ptr)
      Node *temo = temp->next;
    temp->next = ptr->next;
    ptr->next = NULL;
    cout << " the node deleted" << endl;
  } else
    cout << " this node doesn't exist" << endl;
}
void LinkedList::updateNode(int key, int data) {
  Node *ptr = doesNodeExist(key);
  if (ptr) {
    ptr->data = data;
    cout << " node updated" << endl;
  } else
    cout << "  node doesn't " << endl;
}
void LinkedList::print(int key) {
  Node *ptr = doesNodeExist(key);
  if (ptr)
    cout << " node is (" << ptr->key << " : " << ptr->data << " ) " << endl;
  else
    cout << "  node doesn't " << endl;
}
void LinkedList::print() {
  Node *ptr = head->next;
  while (ptr != NULL) {
    cout << "  (" << ptr->key << " : " << ptr->data << " ) "
         << " --> ";
    ptr = ptr->next;
  }
}