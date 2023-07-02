#include <iostream>
#include <stack>

std::string infexPostfix(std::string, std::stack<char>);
int precedence(char);
char pop(std::stack<char> &);

int main(int argc, char const *argv[]) {

  std::stack<char> stack;
  std::string math_expr, postfix;

  std::cout << "Enter a mathematical expression: \n";
  std::cin >> math_expr;

  postfix = infexPostfix(math_expr, stack);
  std::cout << "\n" << postfix << "\n";

  return 0;
}

std::string infexPostfix(std::string expr, std::stack<char> stack) {

  // initializing the output array
  std::string postfix = "";

  for (size_t i = 0; i < expr.length(); i++) {

    // true when there is operand {a,b,...}
    if (precedence(expr[i]) == -1 && expr[i] != ')')
      postfix += expr[i];

    // true when it's '('
    else if (precedence(expr[i]) == 0)
      stack.push(expr[i]);

    // true when it's ')'
    else if (precedence(expr[i]) == -1 && expr[i] == ')') {

      // extarcting all operators from stack till findding '('
      while (stack.top() != '(') {
        postfix += pop(stack);
      }

      // deleting the '(' from the stack
      if (stack.top() == '(')
        stack.pop(); //? stack.pop() is used instead od my own pop() coz '('
                     //? shouldn't be add.
    }

    else {
      // only true at first
      if (stack.empty())
        stack.push(expr[i]);

      // for higher precedence operation {*,/}
      else if (precedence(expr[i]) > precedence(stack.top()))
        stack.push(expr[i]);

      // rare case when 2 or more exponant operation R back 2 back ^ ^
      else if (precedence(expr[i]) == precedence(stack.top()) && expr[i] == '^')
        stack.push(expr[i]);

      // true when there are successive +,- or *,/. same precedence.
      else {

        // poping all elements that R > or === in precedence
        while (precedence(expr[i]) <= precedence(stack.top())) {
          postfix += pop(stack);
        }

        // lastly push new operator.
        stack.push(expr[i]);
      }
    }
  }

  // making sure no operation R left behind.
  while (!stack.empty())
    postfix += pop(stack);

  return postfix; //! CAN BE EMPTY 😷 !!!
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
char pop(std::stack<char> &stack) {

  char ch = stack.top();
  stack.pop();
  return ch;
}