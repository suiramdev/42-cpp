#pragma once

#include "Animal.hpp"

class Dog : public Animal {
private:
  Brain *_brain;

public:
  Dog();
  Dog(const Dog &dog);
  Dog &operator=(const Dog &dog);
  virtual ~Dog();
  void makeSound() const;
};
