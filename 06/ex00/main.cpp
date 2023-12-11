#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: ./convert <value>" << std::endl;
    std::cout << "Example: ./convert 42.4f" << std::endl;
    return 1;
  }

  ScalarConverter::convert(argv[1]);
}
