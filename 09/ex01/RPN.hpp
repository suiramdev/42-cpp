#pragma once

#include <string>

class RPN {
private:
  RPN();
  RPN(const RPN &other);
  RPN &operator=(const RPN &other);
  ~RPN();

  static float applyOperation(char op, float &operand1, float &operand2);

public:
  static float evaluate(const std::string &expression);
};
