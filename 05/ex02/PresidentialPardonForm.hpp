#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string name);
    PresidentialPardonForm(const PresidentialPardonForm &form);
    PresidentialPardonForm& operator=(const PresidentialPardonForm &form);
    virtual ~PresidentialPardonForm();

    virtual void execute(const Bureaucrat &bureaucrat) const;
};
