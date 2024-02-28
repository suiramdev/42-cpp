#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>

RPN::RPN() {}

RPN::RPN(const RPN &other) { (void)other; }

RPN &RPN::operator=(const RPN &other) {
  (void)other;
  return *this;
}

RPN::~RPN() {}

int RPN::applyOperation(char op, int &operand1, int &operand2) {
  switch (op) {
  case '+':
    return operand1 + operand2;
    break;
  case '-':
    return operand1 - operand2;
    break;
  case '*':
    return operand1 * operand2;
    break;
  case '/':
    if (operand2 == 0) {
      throw std::runtime_error("Division by zero");
    }
    return operand1 / operand2;
    break;
  default:
    throw std::runtime_error("Invalid operator");
  }
}

int RPN::evaluate(const std::string &expression) {
  std::stack<int> stack;

  std::istringstream iss(expression);
  std::string token;
  while (iss >> token) {
    std::istringstream iss(token);
    int number;
    if (iss >> number) {
      stack.push(number);
    } else {
      if (stack.size() < 2) {
        throw std::runtime_error("Invalid expression");
      }
      int operand2 = stack.top();
      stack.pop();
      int operand1 = stack.top();
      stack.pop();
      stack.push(applyOperation(token[0], operand1, operand2));
    }
  }

  if (stack.size() != 1) {
    throw std::runtime_error("Invalid expression");
  }

  return stack.top();
}
