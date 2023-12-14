#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
  setGrade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name) {
  setGrade(bureaucrat._grade);
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
  setGrade(bureaucrat._grade);
  return *this;
}

Bureaucrat::~Bureaucrat() {}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat) {
  stream << bureaucrat.getName() << ", bureaucrat grade "
         << bureaucrat.getGrade();
  return stream;
}

const std::string Bureaucrat::getName() const { return _name; }

int Bureaucrat::setGrade(int grade) {
  if (grade < 1)
    throw Bureaucrat::GradeTooLowException();
  if (grade > 150)
    throw Bureaucrat::GradeTooHighException();
  _grade = grade;
  return _grade;
}

int Bureaucrat::incGrade() { return setGrade(_grade - 1); }

int Bureaucrat::decGrade() { return setGrade(_grade + 1); }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::signForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << _name << " couldn't sign " << form.getName() << " because "
              << e.what() << std::endl;
    return;
  }
}

void Bureaucrat::executeForm(AForm &form) {
  try {
    form.execute(*this);
    std::cout << _name << " executed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << _name << " couldn't execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "Grade is too low";
}
