#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &cure) : AMateria(cure) {}

Cure &Cure::operator=(const Cure &cure) {
  if (this != &cure) {
    AMateria::operator=(cure);
  }
  return *this;
}

Cure::~Cure() {}

AMateria *Cure::clone() const { return new Cure(*this); }

void Cure::use(ICharacter &target) {
  std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
}
