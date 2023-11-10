#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat") {
  std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat) {
  std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat) {
  std::cout << "WrongCat assignment operator called" << std::endl;
  if (this != &wrongCat)
    WrongAnimal::operator=(wrongCat);
  return *this;
}

void WrongCat::makeSound() const { std::cout << "Wrong meow" << std::endl; }
