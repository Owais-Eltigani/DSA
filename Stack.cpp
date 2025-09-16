#include <iostream>

class Stack {

private:
  int top;
  int CAPACITY;

  // define the stack data as pointer
  int *data;

public:
  Stack();
  Stack(int);

  ~Stack(); //? for dynamic memory allocation and deallocation
  bool isEmpty();
  bool isFull();
  void push(int);
  void print();
  int pop();
  int size();
};

int main() {

  int ch, num, stackSize;

  std::cout << "enter the size of the stack: ";
  std::cin >> stackSize;
  Stack stack(stackSize);

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
      std::cout << system("clear"); // for linux
      std::cout << system("cls");   // for windows
      break;

    case 0:
      std::cout << "destroying stack and exiting..." << std::endl;
      break;
    default:
      break;
    }
  } while (ch); // while ch !== 0

  std::cout << std::endl;
  return 0;
}

// default constructor
Stack::Stack() {

  // init the Stack top
  top = -1;
  CAPACITY = 5;

  data = new int[CAPACITY];

  //? init the stack data with 0
  for (int i = 0; i < CAPACITY; i++)
    data[i] = 0;
}

// premeterizer constructor
Stack::Stack(int size) {

  // init the Stack
  top = -1;
  CAPACITY = size;

  //? create a dynamic array
  data = new int[CAPACITY];

  //? init the stack data with 0
  for (int i = 0; i < CAPACITY; i++)
    data[i] = 0;
}

Stack::~Stack() {
  // de-allocating the memory

  std::cout << "Destructor called" << std::endl;
  delete[] data;
  data = nullptr;
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
