#include <iostream>
#include <string.h>

void reverse(char *, int, int);
void swap(char &, char &);

int main(int argc, char const *argv[]) {

  char str[] = "foo bar baz";

  std::cout << str << "\n";

  reverse(str, 0, strlen(str) - 1);

  std::cout << str << "\n";

  return 0;
}

void reverse(char *str, int start, int end) {

  if (!(start < end))
    return;

  reverse(str, start + 1, end - 1);
  swap(str[start], str[end]);
}

void swap(char &ch1, char &ch2) {

  char temp = ch1;
  ch1 = ch2;
  ch2 = temp;
}