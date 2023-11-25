#pragma once

#include <exception>
#include <string>

class Form {
private:
  const std::string _name;
  bool _signed;
  const int _signGrade;
  const int _execGrade;

public:
  Form();
  Form(std::string name);
  Form(std::string name, int signGrade, int execGrade);
  Form(const Form &form);
  Form &operator=(const Form &form);
  virtual ~Form();

  friend std::ostream &operator<<(std::ostream &stream, const Form &form);

  const std::string getName() const;
  bool isSigned() const;
  void beSigned(class Bureaucrat &bureaucrat);
  int getSignGrade() const;
  int getExecGrade() const;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
};
