#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
  RobotomyRequestForm();
  RobotomyRequestForm(const std::string name);
  RobotomyRequestForm(const RobotomyRequestForm &form);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &form);
  virtual ~RobotomyRequestForm();

  virtual void execute(const Bureaucrat &bureaucrat) const;
};
