#pragma once

#include "Brain.hpp"
#include <string>

class Animal
{
private:
    Brain* _brain;
protected:
    std::string _type;
public:
    Animal();
    Animal(std::string type);
    Animal(const Animal& animal);
    Animal& operator=(const Animal& animal);
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType() const;
};
