#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
private:
  std::string _name;
  AMateria *_inventory[4];

  Character();

public:
  Character(const std::string &name);
  Character(const Character &character);
  Character &operator=(const Character &character);
  virtual ~Character();
  virtual const std::string &getName() const;
  virtual void equip(AMateria *m);
  virtual void unequip(int idx);
  virtual void use(int idx, ICharacter &target);
};
