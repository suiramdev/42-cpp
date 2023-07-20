#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "A FragTrap is born!" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap " << _name << " is born!" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& fragTrap) : ClapTrap(fragTrap)
{
    std::cout << "FragTrap " << _name << " is born!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &fragTrap)
        ClapTrap::operator=(fragTrap);
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << _name << " is dead!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints == 0 || _energyPoints == 0)
        return;
    _energyPoints--;
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap " << _name << " have high fived" << std::endl;
}

