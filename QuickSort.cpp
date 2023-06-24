#include <iostream>

#define SIZE(arr) sizeof(arr) / sizeof(arr[0])
void swap(int &, int &);
void input(int *, int);
void output(int *, int);
void quickSort(int *, int, int);
int partition(int *, int, int);
int main(int argc, char const *argv[]) {

  /*

  int size;
  std::cin>>size;
  int *arr = new int[size];
  input(arr,size);

   */

  int arr[] = {4, 2, 5, 1, 3, 2};
  quickSort(arr, 0, SIZE(arr) - 1); //! Big O(nlogn)
  output(arr, SIZE(arr));
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

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

void quickSort(int *arr, int start, int end) {
  if (start < end) {
    int pivot = partition(arr, start, end);
    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
  }
}

int partition(int *arr, int start, int end) {
  int pivot = arr[end];
  int index = start;
  for (int i = start; i < end; i++)
    if (arr[i] <= pivot)
      swap(arr[i], arr[index++]);
  swap(arr[index], arr[end]);
  return index;
}