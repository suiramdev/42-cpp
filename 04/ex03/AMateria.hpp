#pragma once

#include <iostream>

class ICharacter;

class AMateria {
protected:
  std::string _type;

private:
  AMateria();

public:
  AMateria(std::string const &type);
  AMateria(const AMateria &amateria);
  AMateria &operator=(const AMateria &amateria);
  virtual ~AMateria();
  std::string const &getType() const;
  virtual AMateria *clone() const = 0;
  virtual void use(ICharacter &target);
};
