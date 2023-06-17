#include <iostream>

#define SIZE(arr) sizeof(arr) / sizeof(arr[0])

void input(int *, int);
void output(int *, int);
int binarySearch(int *, int, int);

int main(int argc, char const *argv[]) {

  /*

  int size;
  std::cin>>size;
  int *arr = new int[size];
  input(arr,size);

   */

  int arr[] = {10, 23, 27, 40, 50, 67, 70, 80, 90, 100};
  int target = 100; //! arbitrary value
  output(arr, SIZE(arr));
  std::cout << binarySearch(arr, SIZE(arr), target);
  return 0;
}

void input(int *arr, int SIZE) {
  std::cout << "enter " << SIZE << " elements";
  for (size_t i = 0; i < SIZE; i++)
    std::cin >> arr[i];
}
void output(int *arr, int SIZE) {
  for (size_t i = 0; i < SIZE; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

int binarySearch(int *arr, int count, int target) {
  int left, middle, right;
  left = 0, right = count - 1;
  do {
    middle = (left + right) / 2;

    if (arr[middle] == target)
      return middle;

    if (arr[middle] > target)
      right = middle - 1;

    if (arr[middle] < target)
      left = middle + 1;

  } while (middle);
  std::cout << "NOT FOUND \n";
  return -1;
}
