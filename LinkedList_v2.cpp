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
  void reverse();
  Node *reverse(Node *);
  void print(int);
  void print();
};

int main() {
  LinkedList s;
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
         << " 8 - Reverse the list\n"
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
      s.reverse();
      break;
    case 9:
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
  if (head->next != NULL) {
    if (!doesNodeExist(node->key)) {
      Node *ptr = head->next;
      while (ptr->next != NULL)
        ptr = ptr->next;
      ptr->next = node;
      cout << endl << "  Node appended" << endl;
    } else
      cout << endl
           << "   Node with key " << node->key << " already exist " << endl;
  } else {
    head->next = node;
    cout << endl << "  Head apprnded" << endl << endl;
  }
}
void LinkedList::prependNode(Node *node) {
  if (head->next != NULL) {
    if (!doesNodeExist(node->key)) {
      Node *ptr = head->next;
      head->next = node;
      node->next = ptr;
      cout << endl << "  Node is prepended" << endl;
    } else
      cout << endl
           << "   Node with key " << node->key << " already exist " << endl;
  } else {
    head->next = node;
    cout << endl << "  Head apprnded" << endl << endl;
  }
}
void LinkedList::insertNode(int key, Node *node) {
  Node *ptr = doesNodeExist(key);
  if (ptr && !doesNodeExist(node->key)) {
    node->next = ptr->next;
    ptr->next = node;
    cout << endl << "   The node is inserted" << endl;
  } else
    cout << endl
         << "   Either node with position " << key
         << " doesn't exist ,  or the node with key " << node->key
         << " already exist \n"
         << endl;
}
void LinkedList::deleteNode(int key) {
  Node *ptr = head->next;
  if (ptr->key == key) {
    head->next = ptr->next;
    cout << endl << "  Head deleted\n";
  } else {
    ptr = doesNodeExist(key);
    if (ptr) {
      Node *temp = head->next;
      while (temp->next != ptr)
        temp = temp->next;
      temp->next = ptr->next;
      ptr->next = NULL;
      cout << endl << "   The node deleted" << endl;
    } else
      cout << endl << "   This node with " << key << " doesn't exist" << endl;
  }
}
void LinkedList::updateNode(int key, int data) {
  Node *ptr = doesNodeExist(key);
  if (ptr) {
    ptr->data = data;
    cout << endl << " Node updated" << endl;
  } else
    cout << endl << "   This node with " << key << " doesn't exist" << endl;
}
void LinkedList::print(int key) {
  Node *ptr = doesNodeExist(key);
  if (ptr)
    cout << endl
         << endl
         << "   Node is (" << ptr->key << " , " << ptr->data << ") " << endl;
  else
    cout << endl << "   This node with " << key << " doesn't exist" << endl;
}
void LinkedList::print() {
  cout << endl;
  Node *ptr = head->next;
  while (ptr != NULL) {
    cout << "  (" << ptr->key << " , " << ptr->data << ") "
         << " --> ";
    ptr = ptr->next;
  }
  cout << endl;
}

void LinkedList::reverse() {
  Node *ptr = head->next;
  Node *tail = NULL;
  while (ptr) {
    Node *temp = ptr;
    ptr = ptr->next;
    temp->next = tail;
    tail = temp;
  }
  head->next = tail;
}

Node *LinkedList::reverse(Node *head) {

  if (head == NULL || head->next == NULL)
    return head;

  Node *ptr = reverse(head->next);
  ptr->next->next = head;
  ptr->next = NULL;

  return ptr;
}

// void LinkedList::reverse() {
//   Node *ptr = head->next;
//   Node *tail = NULL;
//   while (ptr) {
//     Node *temp = ptr;
//     ptr = ptr->next;
//     Node *node = tail;
//     tail = temp;
//     tail->next = node;
//     cout << "   tail is (" << tail->key << " , " << tail->data << ") " <<
//     endl;
//   }
//   head->next = tail;
//   cout << "   Head is (" << tail->key << " , " << tail->data << ") " << endl;
// }
