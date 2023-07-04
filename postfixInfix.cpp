#include <iostream>
#include <stack>

std::string postfixInfix(std::string, std::stack<std::string>);
std::string pop(std::stack<std::string> &);
int precedence(char);

int main(int argc, char const *argv[]) {

  std::stack<std::string> stack;
  std::string math_expr, postfix;

  std::cout << "Enter a mathematical expression: \n";
  std::cin >> postfix;

  math_expr = postfixInfix(postfix, stack);
  std::cout << "\n" << math_expr << "\n";

  return 0;
}

int precedence(char ch) {

  if (ch == '+' || ch == '-')
    return 1;
  if (ch == '*' || ch == '/')
    return 2;
  if (ch == '^')
    return 3;
  if (ch == '(')
    return 0;
  return -1; //? return -1 for both ')' and any other operand.
}

// called by reference to alter the top value
std::string pop(std::stack<std::string> &stack) {

  std::string ch = stack.top();
  stack.pop();
  return ch;
}

std::string postfixInfix(std::string postfix, std::stack<std::string> stack) {

  std::string infix = "";

  for (size_t i = 0; i < postfix.length(); i++) {

    if (precedence(postfix[i]) == -1) {

      std::string expr = "";
      expr += postfix[i];

      stack.push(expr);

    } else if (precedence(postfix[i]) != -1) {

      std::string expr = "(" + pop(stack) + postfix[i] + pop(stack) + ")";
      stack.push(expr);
    }
  }

  while (!stack.empty())
    infix += pop(stack);

  return infix;
}