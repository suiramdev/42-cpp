#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "A ClapTrap is born!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap) : _name(clapTrap._name), _hitPoints(clapTrap._hitPoints), _energyPoints(clapTrap._energyPoints), _attackDamage(clapTrap._attackDamage)
{
    std::cout << "ClapTrap " << _name << " is born!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &clapTrap)
    {
        _name = clapTrap._name;
        _hitPoints = clapTrap._hitPoints;
        _energyPoints = clapTrap._energyPoints;
        _attackDamage = clapTrap._attackDamage;
    } 
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << _name << " is dead!" << std::endl;
}

unsigned int ClapTrap::getHitPoints() const
{
    return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints() const
{
    return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() const
{
    return _attackDamage;
}

void ClapTrap::attack(const std::string& target)
{
    if (_hitPoints == 0 || _energyPoints == 0)
        return;
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints == 0)
        return;
    _hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints == 0)
        return;
    _energyPoints--;
    _hitPoints += amount;
}
