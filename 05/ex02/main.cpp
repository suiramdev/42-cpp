#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    std::cout << "----- PASSING TESTS -----" << std::endl;
    try {
        Bureaucrat bureaucrat("Bureaucrat", 1);
        std::cout << bureaucrat << std::endl;
        ShrubberyCreationForm shrubberyCreationForm("ShrubberyCreationForm");
        std::cout << shrubberyCreationForm << std::endl;
        bureaucrat.signForm(shrubberyCreationForm);
        bureaucrat.executeForm(shrubberyCreationForm);
        RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm");
        std::cout << robotomyRequestForm << std::endl;
        bureaucrat.signForm(robotomyRequestForm);
        bureaucrat.executeForm(robotomyRequestForm);
        PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm");
        std::cout << presidentialPardonForm << std::endl;
        bureaucrat.signForm(presidentialPardonForm);
        bureaucrat.executeForm(presidentialPardonForm);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << "----- FAILING TESTS -----" << std::endl;
    Bureaucrat bureaucrat("Bureaucrat", 150);
    std::cout << bureaucrat << std::endl;
    try {
        ShrubberyCreationForm shrubberyCreationForm("ShrubberyCreationForm");
        std::cout << shrubberyCreationForm << std::endl;
        bureaucrat.signForm(shrubberyCreationForm);
        bureaucrat.executeForm(shrubberyCreationForm);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        RobotomyRequestForm robotomyRequestForm("RobotomyRequestForm");
        std::cout << robotomyRequestForm << std::endl;
        bureaucrat.signForm(robotomyRequestForm);
        bureaucrat.executeForm(robotomyRequestForm);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        PresidentialPardonForm presidentialPardonForm("PresidentialPardonForm");
        std::cout << presidentialPardonForm << std::endl;
        bureaucrat.signForm(presidentialPardonForm);
        bureaucrat.executeForm(presidentialPardonForm);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
}
