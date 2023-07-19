#pragma once

#include <string>

class Animal
{
protected:
    std::string _type;
public:
    Animal();
    Animal(std::string type);
    virtual ~Animal();
    virtual void makeSound() const;
    std::string getType() const;
};
