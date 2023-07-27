#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

#include "Intern.hpp"
#include "AForm.hpp"

int main()
{
    std::cout << "----- PASSING TESTS -----" << std::endl;
    try {
        Intern intern;
        AForm& form = intern.makeForm("presidential pardon", "Bender");
        std::cout << form << std::endl;
        Bureaucrat bureaucrat("Hermes Conrad", 1);
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----- FAILING TESTS -----" << std::endl;
    try {
        Intern intern;
        AForm& form = intern.makeForm("unknown", "Bender");
        std::cout << form << std::endl;
        Bureaucrat bureaucrat("Hermes Conrad", 1);
        bureaucrat.signForm(form);
        bureaucrat.executeForm(form);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
