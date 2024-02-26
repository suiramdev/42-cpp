#include "iter.hpp"
#include <iostream>

void print_char(int &c) { std::cout << c << std::endl; }

int main() {
  char arr[] = "Hello World!";

  iter(arr, sizeof(arr), print_char);
}
