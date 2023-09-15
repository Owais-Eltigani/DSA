#include <iostream>
#define CAPACITY 5

class Stack {
private:
  int top;

  // uses a fixed size array
  int data[CAPACITY];

public:
  Stack();
  ~Stack(); //? for dynamic memory allocation and deallocation
  bool isEmpty();
  bool isFull();
  void push(int);
  void print();
  int pop();
  int size();
};

int main() {

  Stack stack;
  int ch, num;

  do {
    std::cout << "\n 1 - push element  \n"
              << " 2 - pop element \n"
              << " 3 - isEmpty\n"
              << " 4 - isFull \n"
              << " 5 - print Stack \n"
              << " 6 - size\n"
              << " 7 - clear screen" << std::endl;
    std::cout << "\n enter your choice: ";

    std::cin >> ch;

    switch (ch) {

    case 1:
      std::cout << " enter number: ";
      std::cin >> num;
      stack.push(num);
      break;
    case 2:
      std::cout << std::endl << (stack.pop()) << " pooped 💩" << std::endl;
      break;
    case 3:
      std::cout << std::endl << stack.isEmpty();
      break;
    case 4:
      std::cout << std::endl << stack.isFull();
      break;
    case 5:
      stack.print();
      break;
    case 6:
      std::cout << std::endl << stack.size();
      break;
    case 7:
      std::cout << system("cls");
      break;
    default:
      break;
    }
  } while (ch); // while ch !== 0

  std::cout << std::endl;
  return 0;
}

Stack::Stack() {

  // init the Stack
  top = -1;

  data[0] = 0; //? do the same thing as the for loop below

  // for (int i = 0; i < CAPACITY; i++)
  //   data[i] = 0;
}

bool Stack::isEmpty() {
  return (top == -1);
} // return true or false without using if statement

bool Stack ::isFull() {
  return (top == CAPACITY - 1);
} // return true or false without using if statement

void Stack ::push(int num) {
  if (isFull())
    std::cout << " Stack overflow " << std::endl;

  else
    // use prefix increment to increment top first and use the new value of top
    // to assign the value of num to the array
    data[++top] = num;

  print();
}

void Stack ::print() {

  std::cout << std::endl << std::endl;

  //! alert: needs some work

  for (int i = top; i >= 0; i--) {
    std::cout << " \t\t\t\t |    "
              << "     |\n";

    //  the number is 2 digit number
    if (data[i] > 9)
      std::cout << " \t\t\t\t |____" << data[i] << "___|\n ";

    //  the number is 1 digit number
    else
      std::cout << " \t\t\t\t |____" << data[i] << "____|\n ";
  }
}

int Stack ::pop() {
  if (isEmpty()) {
    std::cout << "Stack underflow"
              << "\n";
    return -1;
  } else {
    int temp = data[top--];
    print();
    return temp;
  }
}

int Stack ::size() { return top + 1; }
