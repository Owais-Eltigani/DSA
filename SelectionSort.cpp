#include <iostream>
#define SIZE(arr) sizeof(arr) / sizeof(arr[0])

void swap(int &num1, int &num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}

void selectionSort(int *arr, int size) {
  for (size_t i = 0; i < size - 1; i++) {
    int min = i;
    for (size_t j = i + 1; j < size; j++)
      if (arr[j] < arr[min])
        min = j;
    if (i != min)
      swap(arr[i], arr[min]);
  }
}

void print(int *arr, int count) {
  for (size_t i = 0; i < count; i++)
    std::cout << arr[i] << "  ";
  std::cout << "\n";
}

int main(int argc, char const *argv[]) {
  int arr[] = {8, 12, 0, 4, 9, 2};
  print(arr, 6);
  selectionSort(arr, SIZE(arr));
  print(arr, 6);
  return 0;
}
