#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "A ScavTrap is born!" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << _name << " is born!" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap) : ClapTrap(scavTrap)
{
    std::cout << "ScavTrap " << _name << " is born!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &scavTrap)
        ClapTrap::operator=(scavTrap);
    return *this;
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
    if (_isGuardMode)
        std::cout << "ScavTrap " << _name << " have exit from Gate keeper mode" << std::endl;
    else
        std::cout << "ScavTrap " << _name << " have enterred in Gate keeper mode" << std::endl;
    _isGuardMode = !_isGuardMode;
}
