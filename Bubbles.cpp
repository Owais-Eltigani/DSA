#include <iostream>
#define SIZE 10

int swapCounter = 0;
int innerLoopCounter = 0;
int outerLoopCounter = 0;
void input(int *);
void output(int *);
void bubbleSort(int *);
void swap(int &, int &);

int main(int argc, char const *argv[]) {
  // int *arr = new int[SIZE];
  int arr[] = {18, 3, 27, 0, 5, -17, 9, 50, 10, 100};
  bubbleSort(arr);
  output(arr);
  std::cout << "swapCounter: " << swapCounter;
  std::cout << "\nloopCounter: " << innerLoopCounter;
  std::cout << "\nloopCounterI: " << outerLoopCounter;
  std::cout << "\nloopCounterI * innerLoopCounter : "
            << outerLoopCounter * innerLoopCounter;
  std::cout << "\nloopCounterI * innerLoopCounter* swappes : "
            << outerLoopCounter * innerLoopCounter * swapCounter;
  // std::cout << "\n initial run: " << (SIZE - 1) * (SIZE - 1);
  // std::cout << "\n initial run: " << (SIZE - 1) * 2;
  return 0;
}

void input(int *arr) {
  std::cout << "enter " << SIZE << " elements";
  for (size_t i = 0; i < SIZE; i++)
    std::cin >> arr[i];
}
void output(int *arr) {
  for (size_t i = 0; i < SIZE; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

void bubbleSort(int *arr) {
  bool swapped = true;
  for (size_t i = 0; (i < SIZE - 1 && swapped); i++) {
    swapped = false;
    for (size_t j = 0; (j < SIZE - i - 1); j++) {
      if (arr[j] > arr[j + 1]) {
        swap(arr[j], arr[j + 1]);
        swapped = true;
        swapCounter++;
      }
      innerLoopCounter++;
    }
    outerLoopCounter++;
  }
}

void swap(int &num1, int &num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}
