#pragma once

#include <exception>
#include <string>

class Bureaucrat;

class AForm {
private:
  const std::string _name;
  bool _signed;
  const int _signGrade;
  const int _execGrade;
  AForm();

public:
  AForm(const std::string name, int signGrade, int execGrade);
  AForm(const AForm &form);
  AForm &operator=(const AForm &form);
  virtual ~AForm() = 0;

  const std::string getName() const;

  bool isSigned() const;
  void beSigned(Bureaucrat &bureaucrat);
  int getSignGrade() const;
  int getExecGrade() const;

  virtual void execute(const Bureaucrat &bureaucrat) const;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

  class NotSignedException : public std::exception {
  public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &stream, const AForm &form);
