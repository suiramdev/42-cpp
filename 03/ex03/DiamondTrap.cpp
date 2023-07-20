#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap()
    : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "A DiamondTrap is born!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
    std::cout << "DiamondTrap " << _name << " is born!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
    : ClapTrap(diamondTrap), FragTrap(diamondTrap), ScavTrap(diamondTrap)
{
    std::cout << "DiamondTrap " << _name << " is born!" << std::endl;
    ClapTrap::_name = diamondTrap._name + "_clap_name";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &diamondTrap)
    {
        FragTrap::operator=(diamondTrap);
        ScavTrap::operator=(diamondTrap);
        ClapTrap::_name = diamondTrap._name + "_clap_name";
    }
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " is dead!" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    if (_hitPoints == 0 || _energyPoints == 0)
        return;
    _energyPoints--;
    std::cout << "DiamondTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "DiamondTrap " << _name << " has ClapTrap name " << ClapTrap::_name << std::endl;
}
