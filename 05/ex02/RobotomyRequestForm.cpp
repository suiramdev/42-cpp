#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string name) : AForm(name, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form) : AForm(form)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
    if (this != &form)
        AForm::operator=(form);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(const Bureaucrat &bureaucrat) const
{
    AForm::execute(bureaucrat);
    std::cout << "* drilling noises *" << std::endl;
    srand(time(NULL));
    if (rand() % 2)
        std::cout << getName() << " has been robotomized successfully." << std::endl;
    else
        std::cout << getName() << " robotomization failed." << std::endl;
}
