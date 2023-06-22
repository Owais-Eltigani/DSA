// how to print the time passed since the program started

#include <chrono>
#include <ctime>
#include <iostream>

void sumOfNum(long long num) {
  long long sum = 0;
  for (size_t i = 1; i <= num; i++) {
    sum += i;
  }
  std::cout << "sum: " << sum << '\n';
}

int main() {

  // Start timing the program
  auto start = std::chrono::high_resolution_clock::now();

  // Your program code starts here
  sumOfNum(100000000);
  // Your program code ends here

  // Stop timing the program
  auto end = std::chrono::high_resolution_clock::now();

  // Calculate the duration in milliseconds
  std::chrono::duration<double, std::milli> duration = end - start;
  double durationMs = duration.count();

  // Print the duration
  std::cout << "Time spent: " << durationMs << " milliseconds" << std::endl;

  return 0;
}
