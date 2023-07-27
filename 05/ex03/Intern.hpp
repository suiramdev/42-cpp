#pragma once

#include "AForm.hpp"
#include <exception>
#include <string>

class Intern
{
private:
    static AForm *(*_createForm[3])(const std::string targetName);
    static std::string _forms[3];

    static AForm* _createPresidentialPardonForm(const std::string targetName);
    static AForm* _createRobotomyRequestForm(const std::string targetName);
    static AForm* _createShrubberyCreationForm(const std::string targetName);
    bool _getForm(const std::string formName);
public:
    Intern();
    Intern(const Intern& intern);
    Intern& operator=(const Intern& intern);
    virtual ~Intern();

    AForm& makeForm(const std::string formName, const std::string targetName);

    class InvalidFormNameException : public std::exception
    {
    public:
        virtual const char* what() const throw()
        {
            return "Invalid form name";
        }
    };
};
