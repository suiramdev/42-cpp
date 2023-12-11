#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) {
  *this = other;
  return;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs) {
  (void)rhs;
  return *this;
}

Literals ScalarConverter::identify(std::string input) {
  unsigned long i = 0;
  if (input.length() == 1 && !isdigit(input[0]))
    return CHAR;
  if (input == "nan" || input == "nanf" || input == "+inf" ||
      input == "+inff" || input == "-inf" || input == "-inff")
    return LITERAL;
  if (input[i] == '+' || input[i] == '-')
    i++;
  while (isdigit(input[i]))
    i++;
  if (i > 1) {
    if (input[i] == '.') {
      i++;
      while (isdigit(input[i]))
        i++;
      if (input[i] == '\0')
        return DOUBLE;
    }
    if (input[i] == 'f' && i == input.length() - 1)
      return FLOAT;
    if (input[i] == '\0')
      return INT;
  }
  return INVALID;
}

void ScalarConverter::fromChar(std::string input) {
  std::cout << "char: '" << input[0] << "'" << std::endl;
  std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
  std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
}

void ScalarConverter::fromInt(std::string input) {
  int theInt = std::stoi(input);

  if (std::isprint(theInt))
    std::cout << "char: '" << static_cast<char>(theInt) << "'" << std::endl;
  else
    std::cout << "char: Not displayable" << std::endl;
  std::cout << "int: " << input << std::endl;
  std::cout << "float: " << static_cast<float>(theInt) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(theInt) << ".0" << std::endl;
}

void ScalarConverter::fromFloat(std::string input) {
  float theFloat = std::stof(input);
  int theInt = static_cast<int>(theFloat);

  if (std::isprint(theInt))
    std::cout << "char: '" << static_cast<char>(theInt) << "'" << std::endl;
  else
    std::cout << "char: Not displayable" << std::endl;
  std::cout << "int: " << theInt << std::endl;
  if (theInt == theFloat) {
    std::cout << "float: " << theFloat << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(theFloat) << ".0"
              << std::endl;
  } else {
    std::cout << "float: " << theFloat << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(theFloat) << std::endl;
  }
}

void ScalarConverter::fromDouble(std::string input) {
  double theDouble = std::stod(input);
  int theInt = static_cast<int>(theDouble);

  if (std::isprint(theInt))
    std::cout << "char: '" << static_cast<char>(theInt) << "'" << std::endl;
  else
    std::cout << "char: Not displayable" << std::endl;
  std::cout << "int: " << theInt << std::endl;
  if (theInt == theDouble) {
    std::cout << "float: " << static_cast<float>(theDouble) << ".0f"
              << std::endl;
    std::cout << "double: " << theDouble << ".0" << std::endl;
  } else {
    std::cout << "float: " << static_cast<float>(theDouble) << "f" << std::endl;
    std::cout << "double: " << theDouble << std::endl;
  }
}

void ScalarConverter::fromLiteral(std::string input) {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: " << strtof(input.c_str(), NULL) << std::endl;
  std::cout << "double: " << strtod(input.c_str(), NULL) << std::endl;
}

void ScalarConverter::convert(std::string input) {
  ScalarConverter convert;

  switch (convert.identify(input)) {
  case CHAR:
    convert.fromChar(input);
    break;
  case INT:
    convert.fromInt(input);
    break;
  case FLOAT:
    convert.fromFloat(input);
    break;
  case DOUBLE:
    convert.fromDouble(input);
    break;
  case LITERAL:
    convert.fromLiteral(input);
    break;
  default:
    std::cout << "Not a valid literal" << std::endl;
    break;
  }
}
