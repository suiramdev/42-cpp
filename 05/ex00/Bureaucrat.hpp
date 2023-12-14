#pragma once

#include <exception>
#include <string>

class Bureaucrat {
private:
  const std::string _name;
  int _grade;
  int setGrade(int grade);

public:
  Bureaucrat();
  Bureaucrat(std::string name);
  Bureaucrat(std::string name, int grade);
  Bureaucrat(const Bureaucrat &bureaucrat);
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);
  virtual ~Bureaucrat();

  const std::string getName() const;
  int incGrade();
  int decGrade();
  int getGrade() const;

  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
};

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);
