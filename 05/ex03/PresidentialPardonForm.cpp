#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 72, 45) {}

PresidentialPardonForm::PresidentialPardonForm(std::string const name)
    : AForm(name, 72, 45) {}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &form)
    : AForm(form) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &form) {
  if (this != &form)
    AForm::operator=(form);
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const {
  AForm::execute(bureaucrat);
  std::cout << getName() << " has been pardoned by Zafod Beeblebrox."
            << std::endl;
}
