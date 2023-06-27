
#include <iostream>

int input(int *, int);
int power(int);
void print(int *, int);
void countingSort(int *, int, int);
void radixSort(int *, int, int);

int main(int argc, char const *argv[]) {

  //   int *arr = new int[6]{4, 2, 5, 1, 3, 2};
  int *arr = new int[3];
  int largest = input(arr, 3);
  radixSort(arr, 3, largest);
  print(arr, 3);

  return 0;
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

int power(int num) { return num > 1 ? 10 * power(num - 1) : 10; }

void radixSort(int *arr, int size, int largest) {

  for (int i = 1; largest / i > 0; i *= 10)
    countingSort(arr, size, i);
}

void countingSort(int *arr, int size, int range) {

  int count[10] = {0};
  int *output = new int[size];

  for (size_t i = 0; i < size; i++)
    ++count[(arr[i] / range) % 10];

  for (size_t i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (int i = size - 1; i >= 0; i--) {
    output[count[(arr[i] / range) % 10] - 1] = arr[i];
    count[(arr[i] / range) % 10]--;
  }

  for (size_t i = 0; i < size; i++)
    arr[i] = output[i];
}