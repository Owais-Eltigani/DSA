#include <iostream>
#include <stack>

std::string postfixPrefix(std::string, std::stack<std::string>);
std::string pop(std::stack<std::string> &);
int precedence(char);

int main(int argc, char const *argv[]) {

  std::stack<std::string> stack;
  std::string prefix, postfix;

  std::cout << "Enter a mathematical expression: \n";
  std::cin >> postfix;

  prefix = postfixPrefix(postfix, stack);
  std::cout << "\n" << prefix << "\n";

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

std::string postfixPrefix(std::string postfix, std::stack<std::string> stack) {

  std::string prefix = "";

  for (int i = 0; i < postfix.length(); i++) {

    if (precedence(postfix[i]) == -1) {

      std::string expr = "";
      expr += postfix[i];

      stack.push(expr);

    } else if (precedence(postfix[i]) != -1) {

      std::string op1 = pop(stack);
      std::string op2 = pop(stack);

      std::string expr = postfix[i] + op2 + op1;

      stack.push(expr);
    }
  }

  while (!stack.empty())
    prefix += pop(stack);

  return prefix;
}