#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    Bureaucrat b("b", 1);
    std::cout << b << std::endl;
    b.decGrade();
    std::cout << b << std::endl;
    b.incGrade();
    std::cout << b << std::endl;
    b.incGrade();
    std::cout << b << std::endl;
}
