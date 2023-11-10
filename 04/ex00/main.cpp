#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {
  const Animal *animal = new Animal();
  std::cout << "Type: " << animal->getType() << " " << std::endl;
  animal->makeSound();
  delete animal;
  std::cout << std::endl;
  const Animal *cat = new Cat();
  std::cout << "Type: " << cat->getType() << " " << std::endl;
  cat->makeSound();
  delete cat;
  std::cout << std::endl;
  const Animal *dog = new Dog();
  std::cout << "Type: " << dog->getType() << " " << std::endl;
  dog->makeSound();
  delete dog;
  std::cout << std::endl;
  const WrongAnimal *wrongAnimal = new WrongAnimal();
  std::cout << "Type: " << wrongAnimal->getType() << " " << std::endl;
  wrongAnimal->makeSound();
  delete wrongAnimal;
  std::cout << std::endl;
  const WrongAnimal *wrongCat = new WrongCat();
  std::cout << "Type: " << wrongCat->getType() << " " << std::endl;
  wrongCat->makeSound();
  delete wrongCat;
}
