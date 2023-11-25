#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

AForm *(*Intern::_createForm[3])(const std::string targetName) = {
    Intern::_createPresidentialPardonForm, Intern::_createRobotomyRequestForm,
    Intern::_createShrubberyCreationForm};

std::string Intern::_forms[] = {"presidential pardon", "robotomy request",
                                "shruberry creation"};

AForm *Intern::_createPresidentialPardonForm(const std::string targetName) {
  return new PresidentialPardonForm(targetName);
}

AForm *Intern::_createRobotomyRequestForm(const std::string targetName) {
  return new RobotomyRequestForm(targetName);
}

AForm *Intern::_createShrubberyCreationForm(const std::string targetName) {
  return new ShrubberyCreationForm(targetName);
}

Intern::Intern() {}

Intern::Intern(const Intern &intern) { (void)intern; }

Intern &Intern::operator=(const Intern &intern) {
  (void)intern;
  return *this;
}

Intern::~Intern() {}

AForm &Intern::makeForm(const std::string formName,
                        const std::string targetName) {
  for (int i = 0; i < 3; i++) {
    if (_forms[i] == formName) {
      std::cout << "Intern creates " << formName << std::endl;
      return *_createForm[i](targetName);
    }
  }
  throw Intern::InvalidFormNameException();
}
