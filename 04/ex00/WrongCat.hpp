#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    virtual ~WrongCat();
    void makeSound() const;
};
