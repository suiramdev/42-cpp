#include "Contact.hpp"
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>

Contact::Contact()
{
};

static std::string ask(std::string question)
{
    std::string answer;

    std::cout << question;
    std::getline(std::cin, answer);
    if (std::cin.eof())
        exit(EXIT_FAILURE);
    if (answer.empty())
        return ask(question);
    return answer;
}

void Contact::init()
{
    _firstName = ask("First name: ");
    _lastName = ask("Last name: ");
    _nickname = ask("Nickname: ");
    _phoneNumber = ask("Phone number: ");
    _darkestSecret = ask("Darkest secret: ");
    std::cout << std::endl;
    std::cout << "Contact added" << std::endl;
    std::cout << std::endl;
}

static std::string truncate(std::string str)
{
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void Contact::displayLine()
{
    std::cout << std::setw(10) << truncate(_firstName) << "|";
    std::cout << std::setw(10) << truncate(_lastName) << "|";
    std::cout << std::setw(10) << truncate(_nickname) << std::endl;
}

void Contact::displayInfos()
{
    std::cout << "First name: " << _firstName << std::endl;
    std::cout << "Last name: " << _lastName << std::endl;
    std::cout << "Nickname: " << _nickname << std::endl;
    std::cout << "Phone number: " << _phoneNumber << std::endl;
    std::cout << "Darkest secret: " << _darkestSecret << std::endl;
    std::cout << std::endl;
}
