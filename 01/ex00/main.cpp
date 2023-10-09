#include "Zombie.hpp"

int main()
{
    Zombie* zombie = newZombie("newZombie");
    zombie->announce();
    delete zombie;
    randomChump("randomChump");
}
