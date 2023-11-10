#pragma once

#include "Animal.hpp"

class Cat : public Animal {
private:
  Brain *_brain;

public:
  Cat();
  Cat(const Cat &cat);
  Cat &operator=(const Cat &cat);
  virtual ~Cat();
  virtual void makeSound() const;
};
