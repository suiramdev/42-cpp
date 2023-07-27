#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat b("b", 100);
    try {
        Form f1("f1", 1, 1);
        std::cout << f1 << std::endl;
        b.signForm(f1);
        std::cout << f1 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form f2("f2", 140, 1);
        std::cout << f2 << std::endl;
        b.signForm(f2);
        std::cout << f2 << std::endl;
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
