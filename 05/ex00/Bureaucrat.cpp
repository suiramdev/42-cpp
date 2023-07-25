#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name) : _name(name), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    setGrade(grade);
}

Bureaucrat::~Bureaucrat()
{
}

std::ostream& operator<<(std::ostream &stream, const Bureaucrat& bureaucrat)
{
    stream << bureaucrat._name << ", bureaucrat grade " << bureaucrat._grade;
    return stream;
}

const std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooLowException();
    if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
    return _grade;
}

int Bureaucrat::incGrade()
{
    return setGrade(_grade - 1);
}

int Bureaucrat::decGrade()
{
    return setGrade(_grade + 1);
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}