#pragma once

#include <string>

class WrongAnimal
{
protected:
    std::string _type;
public:
    WrongAnimal();
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal& wrongAnimal);
    WrongAnimal& operator=(const WrongAnimal& wrongAnimal);
    virtual ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;
};
