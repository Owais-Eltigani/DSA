#include <iostream>

void display(int *arr, int count) {
  for (size_t i = 0; i < count; i++)
    std::cout << arr[i] << "  ";
  std::cout << "\n";
}

void insertionSort(int *arr, int count) {
  for (size_t i = 1; i < count; i++) {
    int curr = arr[i];
    int j = i - 1;
    while (j >= 0 && curr < arr[j]) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = curr;
  }
}

int main(int argc, char const *argv[]) {
  int arr[] = {12, 8, 0, 1, 6};
  display(arr, 5);
  insertionSort(arr, 5);
  display(arr, 5);
  return 0;
}
