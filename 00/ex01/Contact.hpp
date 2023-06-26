#pragma once

#include <string>

class Contact
{
public:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    Contact();
    void init();
    void display();
};