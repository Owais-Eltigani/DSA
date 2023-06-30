#include <iostream>

void input(int *);
void print(int *, int);
void shellSort(int *, int);

int main(int argc, char const *argv[]) {

  /*

int *arr = new int[size];
int largest = input(arr, size);
countingSort(arr, size, largest + 1);
print(arr, size);

*/

  int *arr = new int[6]{4, 2, 5, 1, 3, 2};
  print(arr, 6);
  shellSort(arr, 6);
  print(arr, 6);

  return 0;
}

void input(int *arr, int SIZE) {
  std::cout << "enter " << SIZE << " elements";
  for (size_t i = 0; i < SIZE; i++)
    std::cin >> arr[i];
}

void print(int *arr, int SIZE) {
  for (size_t i = 0; i < SIZE; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

void shellSort(int *arr, int size) {

  for (size_t gap = size / 2; gap > 0; gap /= 2) {

    for (size_t i = gap; i < size; i++) {

      int j, temp = arr[i];

      for (j = i; (j >= gap && arr[i - gap] > temp); j -= gap) {

        arr[j] = arr[j - gap];
      }
      arr[j] = temp;
    }
  }
}