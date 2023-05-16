#include <iostream>
#include <string.h>
#include <string>
#define SIZE 100
void swap(int &, int &);

int main(int argc, char const *argv[]) {
  char str[SIZE];
  int sum, index;
  sum = index = 0;
  std::cout << "enter a number: ";
  std::cin >> str;
  int number[strlen(str)];
  for (size_t i = 0; i < strlen(str); i++) {
    number[i] = int(str[i]) - 48;
    if (number[i] > number[0])
      index = i;
  }
  swap(number[0], number[index]);
  for (size_t i = 0; i < strlen(str); i++) {
    if (i % 2 != 0)
      number[i] *= -1;
    sum += number[i];
  }
  std::cout << "sum of digit = " << sum << std::endl;
  return 0;
}
void swap(int &num1, int &num2) {
  int temp = num1;
  num1 = num2;
  num2 = temp;
}
