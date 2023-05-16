#include "test.h"
#include <iostream>

using namespace std;
#define CAPACITY 5
class Queue {
private:
  int front, rear, counter, count;
  float dqC;
  int data[CAPACITY];

public:
  Queue();
  bool isEmpty();
  bool isFull();
  void enqueue(int);
  void print();
  // void print (char c);
  int dequeue();
  int size();
};

int main(int argc, char const *argv[]) {
  Queue s;
  int ch, num;
  cout << "\n 1 - enqueue element  \n"
       << " 2 - dequeue element \n"
       << " 3 - isEmpty\n"
       << " 4 - isFull \n"
       << " 5 - print Queue \n"
       << " 6 - size\n"
       << " 7 - clear screen" << endl;
  do {
    cout << "\n enter your choice: ";
    cin >> ch;
    switch (ch) {
    case 1:
      cin >> num;
      s.enqueue(num);
      break;
    case 2:
      cout << s.dequeue();
      break;
    case 3:
      cout << s.isEmpty();
      break;
    case 4:
      cout << s.isFull();
      break;
    case 5:
      s.print();
      break;
    case 6:
      cout << s.size();
      break;
    case 7:
      system("cls");
      break;
    default:
      return 0;
      break;
    }
  } while (ch != 0);
  cout << endl;
  return 0;
}

Queue::Queue() {
  front = rear = -1;
  dqC = counter = count = 0;
  for (int i = 0; i < 5; i++)
    data[i] = 0;
}
bool Queue::isEmpty() { return (front == -1 && rear == -1); }
bool Queue ::isFull() { return (rear == 4); }
void Queue ::enqueue(int num) {
  if (isFull()) {
    cout << " Queue overflow " << endl;
    return;
  } else if (isEmpty())
    rear = counter = front = 0;
  else
    rear++;
  counter++;
  data[rear] = num;
  print();
}
void Queue ::print() {
  static int stat = 0;
  int a = dqC, holder = counter - count, i;
  cout << "a = " << a << " coun = " << count << " holder = " << holder << endl;
  if (dqC != 0)
    holder += dqC;
  for (i = dqC; i < holder * 3; i++) {
    cout << "___";
  }
  cout << endl;
  for (i = dqC; i < holder; i++) {
    cout << "___" << data[i] << "___|";
  }
  cout << endl << "dqC = " << dqC << " count = " << count << endl;
}

// TODO fixing this visualisation FUNCTION

/* void Queue ::print(char c) {
  static int stat = 0;
  int a = dqC, holder = counter - count, i;
  cout << "a = " << a << " coun = " << count << " holder = " << holder << endl;
  if (dqC != 0)
    holder += dqC;
  for (i = dqC; i < holder * 3; i++) {
    cout << "___";
  }
  cout << endl;
  for (i = dqC; i < rear - front; i++) {
    cout << "___" << data[i] << "___|";
  }
  cout << endl << "dqC = " << dqC << " count = " << count << endl;
} */

// TODO _________________________________________

int Queue ::dequeue() {
  int temp = -1;
  if (isEmpty())
    cout << "Queue underflow" << endl;
  else if (front == rear) {
    temp = data[front];
    front = rear = -1;
    counter = dqC = 0;
    count = 0;
  } else {
    temp = data[front++];
    count++;
    dqC++;
    print();
    counter--;
  }
  return temp;
}
int Queue ::size() {
  cout << "counter = " << counter << " dqC = " << dqC;
  return counter;
}