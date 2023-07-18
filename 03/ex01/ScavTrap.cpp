#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << _name << " is born!" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << _name << " is dead!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (_hitPoints == 0 || _energyPoints == 0)
        return;
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode" << std::endl;
}
