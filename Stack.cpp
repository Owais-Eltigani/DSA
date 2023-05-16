#include <iostream>
#define CAPACITY 5
using namespace std;

class stack {
private:
  int top;
  int data[CAPACITY];

public:
  stack();
  bool isEmpty();
  bool isFull();
  void push(int);
  void print();
  int pop();
  int size();
};

int main() {
  stack s;
  int ch, num;
  do {
    cout << "\n 1 - push element  \n"
         << " 2 - pop element \n"
         << " 3 - isEmpty\n"
         << " 4 - isFull \n"
         << " 5 - print stack \n"
         << " 6 - size\n"
         << " 7 - clear screen" << endl;
    cout << "\n enter your choice: ";
    cin >> ch;
    switch (ch) {
    case 1:
      cout << " enter number: ";
      cin >> num;
      s.push(num);
      break;
    case 2:
      cout << endl << (s.pop()) << " pooped 💩" << endl;
      break;
    case 3:
      cout << endl << s.isEmpty();
      break;
    case 4:
      cout << endl << s.isFull();
      break;
    case 5:
      s.print();
      break;
    case 6:
      cout << endl << s.size();
      break;
    case 7:
      cout << system("cls");
      break;
    default:
      break;
    }
  } while (ch != 0);
  cout << endl;
  return 0;
}
stack::stack() {
  top = -1;
  for (int i = 0; i < 10; i++)
    data[i] = 0;
}
bool stack::isEmpty() { return (top == -1); }
bool stack ::isFull() { return (top == CAPACITY - 1); }
void stack ::push(int num) {
  if (isFull())
    cout << " stack overflow " << endl;
  else
    data[++top] = num;
  print();
}
void stack ::print() {
  cout << endl << endl;
  for (int i = top; i >= 0; i--) {
    cout << " \t\t\t\t |    "
         << "     |\n";
    if (data[i] > 9)
      cout << " \t\t\t\t |____" << data[i] << "___|\n ";
    else
      cout << " \t\t\t\t |____" << data[i] << "____|\n ";
  }
}
int stack ::pop() {
  if (isEmpty()) {
    cout << "stack underflow"
         << "\n";
    return -1;
  } else {
    int temp = data[top--];
    print();
    return temp;
  }
}
int stack ::size() { return top + 1; }
