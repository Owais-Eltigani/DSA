#include <iostream>

struct Node {

  int id, data;
  Node *next = NULL;
};

class Queue {

private:
  Node *front, *rear;

public:
  Queue();
  Queue(Node *);

  bool isEmpty();
  void push(Node *);
  int pop();
  int peak(int);
  int size();
};

int main(int argc, char const *argv[]) {

  Queue stack;

  // Node *n1 = new Node;
  // Node *n2 = new Node;

  Node n1, n2;

  n1.id = 1, n1.data = 10;
  n2.id = 2, n2.data = 20;

  std::cout << stack.size() << "\n";

  stack.push(&n1);
  stack.push(&n2);

  std::cout << stack.size() << "\n";
  std::cout << stack.pop() << "\n";
  std::cout << stack.size() << "\n";

  // delete n1;
  return 0;
}

Queue::Queue() { front = rear = NULL; }

Queue::Queue(Node *node) { front = rear = node; }

bool Queue::isEmpty() { return (front == NULL /* && rear == NULL */); }

void Queue::push(Node *node) {

  if (isEmpty()) {

    std::cout << "Node added \n";

    front = node;
    return;
  }

  Node *temp = front;

  while (temp->next)
    temp = temp->next;

  temp->next = node;
}

int Queue::pop() {

  if (!isEmpty()) {

    Node *temp = front;
    front = front->next;

    return temp->data;
  }

  return -1;
}

int Queue::peak(int id) {

  if (!isEmpty()) {

    Node *temp = front;

    while (temp) {

      if (temp->id == id)
        return temp->data;

      temp = temp->next;
    }

    std::cout << "Not Found \n";
  }

  return -1;
}

int Queue::size() {

  int count = 0;

  Node *temp = front;

  while (temp) {

    count++;
    temp = temp->next;
  }

  return count;
}
