#pragma once

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
private:
  AMateria *_materia[4];
  int _count;

public:
  MateriaSource();
  virtual ~MateriaSource();
  void learnMateria(AMateria *m);
  AMateria *createMateria(std::string const &type);
};
