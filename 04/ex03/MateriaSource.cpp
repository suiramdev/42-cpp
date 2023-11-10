#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource() : _count(0) {
  for (int i = 0; i < 4; i++) {
    _materia[i] = NULL;
  }
}

MateriaSource::~MateriaSource() {
  for (int i = 0; i < 4; i++) {
    delete _materia[i];
  }
}

void MateriaSource::learnMateria(AMateria *m) {
  if (_count < 4) {
    _materia[_count++] = m;
  }
}

AMateria *MateriaSource::createMateria(const std::string &type) {
  for (int i = 0; i < 4; i++) {
    if (_materia[i] != NULL && _materia[i]->getType() == type) {
      return _materia[i]->clone();
    }
  }
  return NULL;
}
