#include <iostream>
using namespace std;

static int ID_COUNT = 0;
class Node {
public:
  int key, data;
  Node *next;
};

class linkedList {
public:
  Node *head;
};

void init(Node *);
void init(Node *, int);
void append(linkedList, Node *);
void printList(linkedList);
void printNodes(Node *);
int exist(int, linkedList);
int main(int argc, char const *argv[]) {
  linkedList List;
  /*   Node *node1 = (Node *)malloc(sizeof(Node));
    Node *node2 = (Node *)malloc(sizeof(Node));
    Node *node3 = (Node *)malloc(sizeof(Node));
    Node *node4 = (Node *)malloc(sizeof(Node)); */
  Node *node1 = new Node;
  // Node *node2 = new Node;
  // Node *node3 = new Node;
  // Node *node4 = new Node;
  init(node1, 15);
  /*
  /  append(List, node1);
  /*   append(List, node2);
    append(List, node3);
    append(List, node4); */
  printList(List);
  cout << exist(1, List);

  return 0;
}
void init(Node *node, int data) {
  cout << "called init\n";
  node->key = ++ID_COUNT;
  node->data = data;
  node->next = NULL;
}
void init(Node *node) {
  node->key = ++ID_COUNT;
  node->data = 0;
  node->next = NULL;
}
int exist(int key, linkedList List) {
  Node *ptr = List.head;
  while (ptr != NULL) {
    if (ptr->key == key)
      return 1;
    else
      ptr = ptr->next;
  }
  return 0;
}
void append(linkedList list, Node *node) {
  if (list.head != NULL) {
    Node *ptr = list.head;
    while (ptr->next)
      ptr = ptr->next;
    ptr->next = node;
    cout << "node appended\n";
  } else {
    list.head = node;
    cout << "Head Appointed\n";
  }
}
void printList(linkedList List) {
  Node *ptr = List.head;
  while (ptr) {
    cout << "(" << ptr->key << "," << ptr->data << ")  -->  ";
    ptr = ptr->next;
  }
}
void printNodes(Node *List) {
  Node *ptr = List;
  while (ptr) {
    cout << "(" << ptr->key << "," << ptr->data << ")  -->  ";
    ptr = ptr->next;
  }
}