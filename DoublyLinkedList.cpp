#include <iostream>
using namespace std;
class Node {
public:
  int data, key;
  Node *next, *previous;
  Node();
  Node(int, int);
};

//? test

class DouLinkList {
private:
  Node *head;

public:
  DouLinkList();
  DouLinkList(Node *);
  Node *doesNodeExist(int);
  void appendNode(Node *);
  void prependNode(Node *);
  void insertNode(int, Node *);
  void deleteNode(int);
  void updateNode(int, int);
  void reverse();
  void print(int);
  void print(char);
  void print();
};

int main() {
  DouLinkList s;
  Node *n;
  int choice, key, data;
  do {
    cout << "\n 1 - Append a node \n"
         << " 2 - Prepend the node at the beginning\n"
         << " 3 - Insert a node at specific poistion\n"
         << " 4 - Delete a node \n"
         << " 5 - Update a node \n"
         << " 6 - Print a specific\n"
         << " 7 - Print the List\n"
         << " 8 - Print the List in  reveres\n"
         << " 8 - Reveres the List\n"
         << " 9 - Clear screen\n";
    cin >> choice;
    n = new Node;
    switch (choice) {
    case 1:
      cout << "enter Key , Data : ";
      cin >> n->key >> n->data;
      s.appendNode(n);
      break;
    case 2:
      cout << "enter Key , data  : ";
      cin >> n->key >> n->data;
      s.prependNode(n);
      break;
    case 3:
      cout << "enter poisition , key and Data : ";
      cin >> key;
      cin >> n->key >> n->data;
      s.insertNode(key, n);
      break;
    case 4:
      cout << "enter Key  : ";
      cin >> key;
      s.deleteNode(key);
      break;
    case 5:
      cout << "enter Key , Data : ";
      cin >> key >> data;
      s.updateNode(key, data);
      break;
    case 6:
      cout << "enter Key  : ";
      cin >> key;
      s.print(key);
      break;
    case 7:
      s.print();
      break;
    case 8:
      s.print('h');
      break;
    case 9:
      s.reverse();
      break;
    case 10:
      system("cls");
      break;
    }
  } while (choice != 0);
  delete n;
}

Node::Node() {
  this->data = 0;
  this->key = 0;
  this->next = NULL;
  this->previous = NULL;
}
Node::Node(int key, int data) {
  this->data = data;
  this->key = key;
  next = NULL;
  previous = NULL;
}

DouLinkList::DouLinkList(Node *node) {
  head->next = node;
  node->previous = NULL;
}

DouLinkList::DouLinkList() {
  head->next = NULL;
  head->previous = NULL;
}
Node *DouLinkList::doesNodeExist(int key) {
  Node *ptr = head->next;
  while (ptr != NULL)
    if (ptr->key == key)
      return ptr;
    else
      ptr = ptr->next;
  return ptr;
}
void DouLinkList::appendNode(Node *node) {
  if (head->next != NULL) {
    if (!doesNodeExist(node->key)) {
      Node *ptr = head->next;
      while (ptr->next != NULL)
        ptr = ptr->next;
      Node *pre = ptr->previous, *nex = ptr->next;
      node->next = ptr->next;
      ptr->next = node;
      node->previous = ptr;
      cout << endl << "  Node appended" << endl;
    } else
      cout << endl
           << "   Node with key " << node->key << " already exist " << endl;
  } else {
    head->next = node;
    node->previous = NULL;
    cout << endl << "  Head apprnded" << endl << endl;
  }
}
void DouLinkList::prependNode(Node *node) {
  if (head->next != NULL) {
    if (!doesNodeExist(node->key)) {
      Node *ptr = head->next;
      head->next = node;
      node->next = ptr;
      ptr->previous = node;
      cout << endl << "  Node is prepended" << endl;
    } else
      cout << endl
           << "   Node with key " << node->key << " already exist " << endl;
  } else {
    head->next = node;
    cout << endl << "  Head apprnded" << endl << endl;
  }
}
void DouLinkList::insertNode(int key, Node *node) {
  Node *ptr = doesNodeExist(key);
  if (ptr && !doesNodeExist(node->key)) {
    Node *pre = ptr->previous, *nex = ptr->next;
    node->next = nex;
    node->previous = ptr;
    ptr->next = node;
    cout << endl << "   The node is inserted" << endl;
  } else
    cout << endl
         << "   Either node with position " << key
         << " doesn't exist ,  or the node with key " << node->key
         << " already exist \n"
         << endl;
}
void DouLinkList::deleteNode(int key) {
  Node *ptr = head->next;
  if (ptr->key == key) {
    head->next = ptr->next;
    ptr->previous = NULL;
    cout << endl << "  Head deleted\n";
  } else {
    ptr = doesNodeExist(key);
    if (ptr) {
      Node *temp = ptr->previous;

      temp->next = ptr->next;
      ptr->next->previous = temp;
      ptr->previous = NULL;
      cout << endl << "   The node deleted" << endl;
    } else
      cout << endl << "   This node with " << key << " doesn't exist" << endl;
  }
}
void DouLinkList::updateNode(int key, int data) {
  Node *ptr = doesNodeExist(key);
  if (ptr) {
    ptr->data = data;
    cout << endl << " Node updated" << endl;
  } else
    cout << endl << "   This node with " << key << " doesn't exist" << endl;
}
void DouLinkList::print(int key) {
  Node *ptr = doesNodeExist(key);
  if (ptr)
    cout << endl
         << endl
         << "   Node is (" << ptr->key << " , " << ptr->data << ") " << endl;
  else
    cout << endl << "   This node with " << key << " doesn't exist" << endl;
}
void DouLinkList::print() {
  cout << endl;
  Node *ptr = head->next;
  while (ptr != NULL) {
    cout << "  (" << ptr->key << " , " << ptr->data << ") "
         << " <--> ";
    ptr = ptr->next;
  }
  cout << endl;
}

void DouLinkList::print(char c) {
  cout << endl;
  Node *ptr = head->next;
  while (ptr->next != NULL)
    ptr = ptr->next;

  while (ptr != NULL) {
    cout << "  (" << ptr->key << " , " << ptr->data << ") "
         << " <--> ";
    ptr = ptr->previous;
  }

  cout << endl;
}
void DouLinkList::reverse() {
  Node *ptr = head->next;
  Node *tail = NULL;
  while (ptr) {
    Node *temp = ptr;
    ptr = ptr->next;
    Node *node = tail;
    tail = temp;
    tail->next = node;
  }
  head->next = tail;
}
