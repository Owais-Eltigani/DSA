#include <iostream>

void countingSort(int *, int, int);
int *countingSort2(int *, int, int);
void print(int *, int);
int input(int *, int);

int main(int argc, char const *argv[]) {

  /*

  int *arr = new int[size];
    int largest = input(arr, size);
    countingSort(arr, size, largest + 1);
    print(arr, size);

   */

  int *arr = new int[6]{4, 2, 5, 1, 3, 2};
  //   countingSort(arr, 6, 12);
  arr = countingSort2(arr, 6, 12); //? Big O(n) || the range should be always
                                   //? greater than the largest element.
  print(arr, 6);
  return 0;
}

void countingSort(int *arr, int SIZE, int RANGE) {

  int *count = new int[RANGE];
  int *output = new int[SIZE];

  for (size_t i = 0; i < SIZE; i++)
    count[arr[i]]++;

  for (size_t i = 1; i < RANGE; i++)
    count[i] += count[i - 1];

  for (size_t i = 0; i < SIZE; i++)
    output[--count[arr[i]]] = arr[i];

  for (size_t i = 0; i < SIZE; i++)
    arr[i] = output[i];
}

int *countingSort2(int *arr, int size, int range) {

  int *count = new int[range]{0};
  int *output = new int[size];

  for (int i = 0; i < size; i++)
    ++count[arr[i]];

  for (int i = 1; i < range; i++)
    count[i] = count[i] + count[i - 1];

  for (int i = 0; i < size; i++)
    output[--count[arr[i]]] = arr[i];

  return output;
}

void print(int *arr, int SIZE) {
  for (size_t i = 0; i < SIZE; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

int input(int *arr, int SIZE) {
  int largest = INT16_MIN;
  std::cout << "enter " << SIZE << " elements";

  for (size_t i = 0; i < SIZE; i++) {

    std::cin >> arr[i];
    if (arr[i] > largest)
      largest = arr[i];
  }

  return largest;
}
