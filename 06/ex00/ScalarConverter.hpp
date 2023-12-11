#pragma once

#include <string>

enum Literals { CHAR, INT, FLOAT, DOUBLE, LITERAL, INVALID };

class ScalarConverter {
private:
  ScalarConverter();
  ScalarConverter(const ScalarConverter &other);
  ScalarConverter &operator=(const ScalarConverter &other);
  ~ScalarConverter();

  Literals identify(std::string input);

  void fromChar(std::string input);
  void fromInt(std::string input);
  void fromFloat(std::string input);
  void fromDouble(std::string input);
  void fromLiteral(std::string input);

public:
  void static convert(std::string input);
};
