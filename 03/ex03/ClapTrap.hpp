#pragma once

#include <string>

class ClapTrap
{
protected:
    std::string _name;
    unsigned int _hitPoints;
    unsigned int _energyPoints;
    unsigned int _attackDamage;
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap& clapTrap);
    ClapTrap& operator=(const ClapTrap& clapTrap);
    virtual ~ClapTrap();
    unsigned int getHitPoints() const;
    unsigned int getEnergyPoints() const;
    unsigned int getAttackDamage() const;
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
};
