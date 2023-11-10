#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
  std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) {
  std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
    : _type(wrongAnimal._type) {
  std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wrongAnimal) {
  std::cout << "WrongAnimal assignment operator called" << std::endl;
  if (this != &wrongAnimal)
    _type = wrongAnimal._type;
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "Wrong animal sound" << std::endl;
}

std::string WrongAnimal::getType() const { return _type; }
