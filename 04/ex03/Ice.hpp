#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
public:
  Ice();
  Ice(const Ice &ice);
  Ice &operator=(const Ice &ice);
  virtual ~Ice();
  virtual AMateria *clone() const;
  virtual void use(ICharacter &target);
};
