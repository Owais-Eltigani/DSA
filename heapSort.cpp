#include <iostream>
#define SIZE(arr) sizeof(arr) / sizeof(arr[0])
void swap(int &num1, int &num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}
void heapify(int arr[], int root, int size) {
  int smallest = root;
  int left = (root * 2) + 1;
  int right = (root * 2) + 2;
  if (left < size && arr[left] < arr[smallest])
    smallest = left;
  if (right < size && arr[right] < arr[smallest])
    smallest = right;
  if (smallest != root) {
    swap(arr[smallest], arr[root]);
    heapify(arr, smallest, size);
  }
}
int extract(int arr[], int size) {
  if (!size)
    return -1;
  else if (size == 1)
    return arr[--size];
  else {
    int temp = arr[0];
    arr[0] = arr[--size];
    heapify(arr, 0, size);
    return temp;
  }
}

int *heapSort(int arr[], int size) {

  for (int i = size / 2 - 1; i >= 0; i--)
    heapify(arr, i, size);

  static int *temp = new int[size];

  for (size_t i = 0; i < size; i++) {
    temp[i] = extract(arr, size - i);
    std::cout << temp[i] << "  ";
  }
  return temp;
}

int main(int argc, char const *argv[]) {
  int arr[] = {8, 12, 0, 4, 9, 2};
  // std::cout << SIZE(arr);
  int *arr2 = heapSort(arr, SIZE(arr));
  std::cout << "\n" << arr2[4] << "\n";
  return 0;
}
