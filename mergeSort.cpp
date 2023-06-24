#include <iostream>

#define SIZE(arr) sizeof(arr) / sizeof(arr[0])
void swap(int &, int &);
void input(int *, int);
void output(int *, int);
void mergeSort(int *, int, int);
void merge(int *, int, int, int);
void myMerge(int *, int, int, int);

int main(int argc, char const *argv[]) {

  /*

  int size;
  std::cin>>size;
  int *arr = new int[size];
  input(arr,size);

   */

  int arr[] = {4, 2, 5, 1, 3};
  mergeSort(arr, 0, SIZE(arr) - 1); //! Big O(nlogn)
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

void mergeSort(int *arr, int left, int right) {
  if (left < right) {
    int middle = (left + right) / 2;
    mergeSort(arr, left, middle);
    mergeSort(arr, middle + 1, right);
    myMerge(arr, left, middle, right);
  }
}

void merge(int *arr, int left, int middle, int right) {
  int i, j, k;

  // Number of elements in left and right arrays.
  int n1 = middle - left + 1;
  int n2 = right - middle;

  // Create left and right arrays.
  int *L = new int[n1];
  int *R = new int[n2];

  // Copy values from original array into left and right arrays.
  for (i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[middle + 1 + j];

  i = 0, j = 0, k = left;

  // Merge left and right arrays.
  while (i < n1 && j < n2) {
    if (L[i] <= R[j])
      arr[k++] = L[i++];
    else
      arr[k++] = R[j++];
  }

  // Copy remaining elements from left array.
  while (i < n1)
    arr[k++] = L[i++];

  // Copy remaining elements from right array.
  while (j < n2)
    arr[k++] = R[j++];
}

void myMerge(int *arr, int left, int middle, int right) {

  int left_C = left, right_C = middle + 1, counter = 0;

  int *temp = new int[(middle - left + 1) + (right - middle)];

  while (left_C <= middle && right_C <= right) {
    if (arr[left_C] < arr[right_C])
      temp[counter++] = arr[left_C++];
    else
      temp[counter++] = arr[right_C++];
  }

  while (left_C <= middle)
    temp[counter++] = arr[left_C++];

  while (right_C <= right)
    temp[counter++] = arr[right_C++];

  for (size_t i = left; i <= right; i++)
    arr[i] = temp[i - left];
}
