#include "Zombie.hpp"
#include <string>

void randomChump(std::string name)
{
    Zombie* zombie = newZombie(name);
    zombie->announce();
    delete zombie;
}
