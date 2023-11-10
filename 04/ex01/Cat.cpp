#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal("Cat"), _brain(new Brain()) {
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat), _brain(new Brain(*cat._brain)) {
  std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat) {
  std::cout << "Cat assignment operator called" << std::endl;
  if (this != &cat) {
    Animal::operator=(cat);
    _brain = cat._brain;
  }
  return *this;
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete _brain;
}

void Cat::makeSound() const { std::cout << "Meaow" << std::endl; }
