#pragma once

#include <string>

class Contact {
    public:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;

        Contact(std::string firstName, std::string lastName, std::string nickName, std::string phoneNumber);
};
