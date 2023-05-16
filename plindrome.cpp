#include <algorithm>
#include <iostream>

void swap(int &num1, int &num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}
void input(int *arr, int size) {
  for (size_t i = 0; i < 5; i++) {
    std::cout << "enter element " << i + 1 << ": ";
    std::cin >> arr[i];
  }
}
void output(int *arr, int size) {
  for (size_t i = 0; i < 5; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}
void reverse(int *arr, int size) {
  for (size_t i = 0; i < size / 2; i++) {       
    swap(arr[i], arr[size - i - 1]);
  }
}

int main(int argc, char const *argv[]) {
  int arr[5];
  input(arr, 5);
  output(arr, 5);
  reverse(arr, 5);
  output(arr, 5);
  return 0;
}
