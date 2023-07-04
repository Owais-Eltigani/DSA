#include <iostream>
#include <stack>

std::string prefixInfix(std::string, std::stack<std::string>);
std::string pop(std::stack<std::string> &);
int precedence(char);

int main(int argc, char const *argv[]) {

  std::stack<std::string> stack;
  std::string math_expr, prefix;

  std::cout << "Enter a mathematical expression: \n";
  std::cin >> prefix;

  math_expr = prefixInfix(prefix, stack);
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

std::string prefixInfix(std::string prefix, std::stack<std::string> stack) {

  std::string infix = "";

  for (int i = prefix.length() - 1; i >= 0; i--) {

    if (precedence(prefix[i]) == -1) {

      std::string expr = "";
      expr += prefix[i];

      stack.push(expr);

    } else if (precedence(prefix[i]) != -1) {

      std::string op1 = pop(stack);
      std::string op2 = pop(stack);

      //   std::string expr = "(" + pop(stack) + prefix[i] + pop(stack) + ")";

      std::string expr = "(" + op1 + prefix[i] + op2 + ")";

      stack.push(expr);
    }
  }

  while (!stack.empty())
    infix += pop(stack);

  return infix;
}