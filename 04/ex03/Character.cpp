#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

Character::Character() : _name(NULL) {}

Character::Character(const std::string &name) : _name(name) {
  for (int i = 0; i < 4; i++) {
    _inventory[i] = NULL;
  }
}

Character::Character(const Character &character) : _name(character._name) {
  for (int i = 0; i < 4; i++) {
    delete _inventory[i];
    _inventory[i] = character._inventory[i]->clone();
  }
}

Character &Character::operator=(const Character &character) {
  _name = character._name;
  for (int i = 0; i < 4; i++) {
    delete _inventory[i];
    _inventory[i] = character._inventory[i]->clone();
  }
  return *this;
}

Character::~Character() {
  for (int i = 0; i < 4; i++) {
    delete _inventory[i];
  }
}

std::string const &Character::getName() const { return _name; }

void Character::equip(AMateria *m) {
  for (int i = 0; i < 4; i++) {
    if (_inventory[i] == NULL) {
      _inventory[i] = m;
      return;
    }
  }
}

void Character::unequip(int idx) {
  if (idx >= 0 && idx < 4) {
    _inventory[idx] = NULL;
  }
}

void Character::use(int idx, ICharacter &target) {
  if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
    _inventory[idx]->use(target);
  }
}
