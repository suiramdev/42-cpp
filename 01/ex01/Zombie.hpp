#pragma once

#include <string> 

class Zombie
{
private:
    std::string name;

public:
    Zombie* next;

    Zombie();
    Zombie(std::string name);
    ~Zombie();
    void announce();
    void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);
