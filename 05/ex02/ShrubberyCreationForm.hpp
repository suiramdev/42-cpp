#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string name);
    ShrubberyCreationForm(const ShrubberyCreationForm &form);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &form);
    virtual ~ShrubberyCreationForm();

    virtual void execute(const Bureaucrat &bureaucrat) const;
};
