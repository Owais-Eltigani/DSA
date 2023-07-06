#include <iostream>

struct Node {

  int id, data;
  Node *next = NULL;
};

class Stack {

private:
  Node *top;

public:
  Stack();
  Stack(Node *);

  bool isEmpty();
  bool nodeExist(int);
  void push(Node *);
  int pop();
  int peak(int);
  int size();
};

int main(int argc, char const *argv[]) {

  Stack stack;

  // Node *n1 = new Node;
  Node n1;
  n1.id = 1, n1.data = 10;

  std::cout << stack.size() << "\n";
  stack.push(&n1);

  // std::cout << stack.size() << "\n";
  std::cout << stack.pop() << "\n";
  std::cout << stack.pop() << "\n";
  // std::cout << stack.size() << "\n";

  // delete n1;
  return 0;
}

Stack::Stack(Node *node) { top = node; }

Stack::Stack() { top = NULL; }

bool Stack::isEmpty() {

  // return !!top;
  return top == NULL;
}

void Stack::push(Node *node) {

  if (!top)
    top = node;

  else if (this->nodeExist(node->id))
    std::cout << "Node Already Exist \n";

  else {

    Node *temp = top;
    top = node;
    top->next = temp;
  }
}

bool Stack::nodeExist(int id) {

  Node *temp = top;

  while (temp) {

    if (temp->id == id)
      return true;

    temp = temp->next;
  }

  return false;
}

int Stack::pop() {

  if (this->isEmpty()) {

    std::cout << "Stack Underflow \n";

    return -1;
  }

  Node *temp = top;
  top = top->next;

  return temp->data;
}

int Stack::peak(int id) {

  if (!this->nodeExist(id)) {
    std::cout << "Node Doesn't Exist";

    return -1;
  }

  return top->data;
}

int Stack::size() {

  int count = 0;

  Node *temp = top;

  while (temp) {

    count++;
    temp = temp->next;
  }

  return count;
}
