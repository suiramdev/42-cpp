#include "Span.hpp"
#include <exception>
#include <iostream>
#include <vector>

typedef std::vector<int> oops;

int main() {
  std::vector<int> numbers;
  numbers.push_back(6);
  numbers.push_back(3);
  numbers.push_back(17);
  numbers.push_back(9);
  numbers.push_back(11);

  Span sp(5);
  try {
    sp.addNumbers<oops>(numbers.begin(), numbers.end());
  } catch (std::exception e) {
    std::cout << "List is full" << std::endl;
  }
  std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
  std::cout << "Longest span: " << sp.longestSpan() << std::endl;
  return 0;
}
