#include <iostream>

struct Node {
  int val;
  Node *next = NULL;
};

void print(Node *node) {

  if (!node)
    return;

  std::cout << node->val << " -> ";
  print(node->next);
}

Node *merge(Node *n1, Node *n2) {

  if (!n1)
    return n2;

  if (!n2)
    return n1;

  Node *ptr;

  if (n1->val < n2->val) {

    ptr = n1;
    ptr->next = (merge(n1->next, n2));
  } else {

    ptr = n2;
    ptr->next = (merge(n1, n2->next));
  }

  return ptr;
}

int main(int argc, char const *argv[]) {

  Node *n1 = new Node;
  Node *n2 = new Node;
  Node *n3 = new Node;

  n1->val = 0;
  n1->next = n2;

  n2->val = 7;
  n2->next = n3;

  n3->val = 10;

  //? ===============================

  Node *n4 = new Node;
  Node *n5 = new Node;

  n4->val = -1;
  n4->next = n5;

  n5->val = 6;

  Node *m = merge(n1, n4);

  print(m);

  return 0;
}
