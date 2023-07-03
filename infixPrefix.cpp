
//* for better understaing of this algorithm  see the infixPostfix firest
//* this algorithms works the same in addition to some modifications.
//* first you reverse the infix string.
//* changing the rule of infixPostfix if there're ^ ^ back to back
//* and change the rule of infixPostfix if the next element has < precedence
//* than top of stack
//* there is a bit manuplation regarding '(' and ')' becoz when you reversed
//* the string there semantic hase changed
//* after you get the output string reversed it again to get Prefix.

#include <iostream>
#include <stack>
#include <string>

std::string infixPrefix(std::string, std::stack<char>);
int precedence(char);
char pop(std::stack<char> &);
void reverse(std::string &, int, int);
void swap(char &, char &);

int main(int argc, char const *argv[]) {

  std::stack<char> stack;
  std::string math_expr, postfix;

  std::cout << "Enter a mathematical expression: \n";
  std::cin >> math_expr;

  postfix = infixPrefix(math_expr, stack);
  reverse(postfix, 0, postfix.length() - 1);

  std::cout << "\n" << postfix << "\n";

  return 0;
}

void reverse(std::string &str, int start, int end) {

  if (start < end) {
    reverse(str, start + 1, end - 1);
    swap(str[start], str[end]);
  }
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
  return -1;
}

char pop(std::stack<char> &stack) {

  char ch = stack.top();
  stack.pop();
  return ch;
}

void swap(char &ch1, char &ch2) {

  char temp = ch1;
  ch1 = ch2;
  ch2 = temp;
}

std::string infixPrefix(std::string expr, std::stack<char> stack) {

  std::string postfix = "";

  for (int i = expr.length() - 1; i >= 0; i--) {

    if (precedence(expr[i]) == -1 && expr[i] != ')')
      postfix += expr[i];

    else if (precedence(expr[i]) == -1 && expr[i] == ')')
      stack.push(expr[i]);

    else if (precedence(expr[i]) == 0) {

      while (stack.top() != ')') {
        postfix += pop(stack);
      }

      if (stack.top() == ')')
        stack.pop();
    }

    else {
      if (stack.empty())
        stack.push(expr[i]);

      else if (precedence(expr[i]) > precedence(stack.top()))
        stack.push(expr[i]);

      else if ((precedence(expr[i]) == precedence(stack.top())) &&
               expr[i] == '^') {

        while (precedence(expr[i]) == precedence(stack.top())) {
          postfix += pop(stack);
        }

        stack.push(expr[i]);

      }

      else {

        while (precedence(expr[i]) < precedence(stack.top())) {
          postfix += pop(stack);
        }

        stack.push(expr[i]);
      }
    }
  }

  while (!stack.empty())
    postfix += pop(stack);

  return postfix; //! CAN BE EMPTY 😷 !!!
}
