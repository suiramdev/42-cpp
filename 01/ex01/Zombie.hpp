#pragma once

#include <string> 

class Zombie
{
private:
    std::string name;

public:
    Zombie* next;

    Zombie(std::string name);
    ~Zombie();
    void deleteHorde();
    void announce();
};

Zombie* zombieHorde(int N, std::string name);
