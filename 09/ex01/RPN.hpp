#pragma once

#include <string>

class RPN {
private:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();

  static int applyOperation(char op, int &operand1, int &operand2);

public:
  static int evaluate(const std::string &expression);
};
