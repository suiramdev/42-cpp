#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  try {
    std::cout << "-- Bureaucrat with grade of 1, increased --" << std::endl;
    Bureaucrat b("b", 1);
    std::cout << b << std::endl;
    b.incGrade();
    std::cout << b << std::endl;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  try {
    std::cout << "-- Bureaucrat with grade of 151 --" << std::endl;
    Bureaucrat a("a", 151);
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
  }
}
