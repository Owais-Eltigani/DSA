// how to print the time passed since the program started

#include <chrono>
#include <ctime>
#include <iostream>
#include <time.h>

void sumOfNum(long long num) {
  long long sum = 0;
  for (size_t i = 1; i <= num; i++) {
    sum += i;
  }
  std::cout << "sum: " << sum << '\n';
}

void mark_if(int marks) {

  if (marks >= 90 && marks <= 100) {
    std::cout << "Grade: A" << std::endl;
  } else if (marks >= 85 && marks < 90) {
    std::cout << "Grade: A-" << std::endl;
  } else if (marks >= 80 && marks < 85) {
    std::cout << "Grade: B+" << std::endl;
  } else if (marks >= 75 && marks < 80) {
    std::cout << "Grade: B" << std::endl;
  } else if (marks >= 70 && marks < 75) {
    std::cout << "Grade: B-" << std::endl;
  } else if (marks >= 65 && marks < 70) {
    std::cout << "Grade: C+" << std::endl;
  } else if (marks >= 60 && marks < 65) {
    std::cout << "Grade: C" << std::endl;
  } else if (marks >= 55 && marks < 60) {
    std::cout << "Grade: C-" << std::endl;
  } else if (marks >= 50 && marks < 55) {
    std::cout << "Grade: D+" << std::endl;
  } else if (marks >= 45 && marks < 50) {
    std::cout << "Grade: D" << std::endl;
  } else if (marks >= 40 && marks < 45) {
    std::cout << "Grade: D-" << std::endl;
  } else if (marks >= 35 && marks < 40) {
    std::cout << "Grade: E" << std::endl;
  } else if (marks >= 30 && marks < 35) {
    std::cout << "Grade: F" << std::endl;
  } else {
    std::cout << "Invalid marks entered!" << std::endl;
  }
}

int main() {

  // Start timing the program
  auto start = std::chrono::high_resolution_clock::now();

  // Your program code starts here

  srand(time(0));

  int marks;

  for (size_t i = 0; i < 50; i++) {

    marks = rand() % (100 - 30) + 30;
    mark_if(marks);
  }

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
