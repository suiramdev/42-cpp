#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form() : _name("default"), _signed(false), _signGrade(1), _execGrade(1)
{
}

Form::Form(std::string name) : _name(name), _signed(false), _signGrade(1), _execGrade(1)
{
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form &form) : _name(form._name), _signed(form._signed), _signGrade(form._signGrade), _execGrade(form._execGrade)
{
}

Form &Form::operator=(const Form &form)
{
    _signed = form._signed;
    return *this;
}

Form::~Form()
{
}

std::ostream& operator<<(std::ostream &stream, const Form& form)
{
    stream << form._name << ", sign grade " << form._signGrade << ", exec grade " << form._execGrade << ", signed " << form._signed;
    return stream;
}

const std::string Form::getName() const
{
    return _name;
}

bool Form::isSigned() const
{
    return _signed;
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw Form::GradeTooLowException();
    _signed = true;
}

int Form::getSignGrade() const
{
    return _signGrade;
}

int Form::getExecGrade() const
{
    return _execGrade;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}
