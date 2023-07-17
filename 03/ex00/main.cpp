#include "ClapTrap.hpp"
#include <iostream>

int main()
{
    ClapTrap clapTrap1("ClapTrap1");
    ClapTrap clapTrap2("ClapTrap2");

    clapTrap1.attack("ClapTrap2");
    clapTrap2.beRepaired(5);
    clapTrap2.attack("ClapTrap1");
    clapTrap2.attack("ClapTrap1");
    clapTrap1.beRepaired(10);
    std::cout << "-- ClapTrap1 --" << std::endl;
    std::cout << "Hit points : " << clapTrap1.getHitPoints() << std::endl;
    std::cout << "Energy points : " << clapTrap1.getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << clapTrap1.getAttackDamage() << std::endl;
    std::cout << "-- ClapTrap2 --" << std::endl;
    std::cout << "Hit points : " << clapTrap2.getHitPoints() << std::endl;
    std::cout << "Energy points : " << clapTrap2.getEnergyPoints() << std::endl;
    std::cout << "Attack damage : " << clapTrap2.getAttackDamage() << std::endl;
}
