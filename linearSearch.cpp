#include <iostream>

#define SIZE(arr) sizeof(arr) / sizeof(arr[0])

void input(int *, int);
void output(int *, int);
int linearSearch(int *, int, int);

int main(int argc, char const *argv[]) {
  /*

  int size;
  std::cin>>size;
  int *arr = new int[size];
  input(arr,size);

   */

  int arr[] = {18, 3, 27, 0, 5, -17, 9, 50, 10, 100};
  int target = -17; //! arbitrary value
  output(arr, SIZE(arr));
  std::cout << linearSearch(arr, SIZE(arr), target);
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

int linearSearch(int *arr, int count, int target) {
  for (size_t i = 0; i < count; i++) {
    if (arr[i] == target)
      return i;
  }
  std::cout << "NOT FOUND \n";
  return -1;
}
