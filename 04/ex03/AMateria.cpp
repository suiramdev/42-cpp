#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type(NULL) {}

AMateria::AMateria(std::string const &type) : _type(type) {}

AMateria::AMateria(const AMateria &amateria) : _type(amateria._type) {}

AMateria &AMateria::operator=(const AMateria &amateria) {
  if (this != &amateria) {
    _type = amateria._type;
  }
  return *this;
}

AMateria::~AMateria() {}

std::string const &AMateria::getType() const { return _type; }

void AMateria::use(ICharacter &target) {
  std::cout << "* use a materia on " << target.getName() << " * ";
}
