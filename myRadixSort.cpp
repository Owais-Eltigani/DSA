
#include <algorithm>
#include <iostream>
#include <vector>

int input(int *, int);
int digitCount(int);
int power(int);
void print(int *, int);
void bucketSort(int *, int, int);

int main(int argc, char const *argv[]) {

  int *arr = new int[6]{4, 2, 5, 1, 3, 2};
  int largest = input(arr, 3);
  bucketSort(arr, 3, largest);
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

int digitCount(int num) {
  int count = 0;
  do {
    num = num / 10;
    count++;
  } while (num);
  return count;
}

int power(int num) { return num > 1 ? 10 * power(num - 1) : 10; }

void bucketSort(int *arr, int size, int largest) {

  int digit = digitCount(largest); // return the number of digit of largest

  int radix = 1;

  std::vector<int> indices;

  for (size_t i = 0; i < digit; i++) {

    radix = power(i + 1);

    // vector<vector<int>> queue(10, vector<int>(10, 0)); // 2D vector
    std::vector<std::vector<int>> queue(10); // 2D vector with variable sizes

    for (size_t j = 0; j < size; j++) {

      int index =
          radix > 10 ? (arr[j] % radix) / power(i + 1) : (arr[j] % radix);
      indices.push_back(index);
      queue[index].push_back(arr[j]);
    }

    sort(indices.begin(), indices.end());

    for (size_t i = 0; i < size; i++) {
      arr[i] = queue[indices.front()].front();
      queue[indices.front()].erase(queue[indices.front()].begin());
      indices.erase(indices.begin());
    }
  }
}