#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(std::string name, int signGrade, int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
    if (signGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& form) : _name(form._name), _signed(form._signed), _signGrade(form._signGrade), _execGrade(form._execGrade)
{
}

AForm& AForm::operator=(const AForm &form)
{
    _signed = form._signed;
    return *this;
}

AForm::~AForm()
{
}

std::ostream& operator<<(std::ostream& stream, const AForm& form)
{
    stream << form._name << ", sign grade " << form._signGrade << ", exec grade " << form._execGrade << ", signed " << form._signed;
    return stream;
}

const std::string AForm::getName() const
{
    return _name;
}

bool AForm::isSigned() const
{
    return _signed;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw AForm::GradeTooLowException();
    _signed = true;
}

int AForm::getSignGrade() const
{
    return _signGrade;
}

int AForm::getExecGrade() const
{
    return _execGrade;
}

void AForm::execute(const Bureaucrat &bureaucrat) const
{
    if (!isSigned())
        throw AForm::NotSignedException();
    if (bureaucrat.getGrade() > _execGrade)
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "Form not signed";
}
