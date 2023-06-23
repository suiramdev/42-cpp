#include "Contact.hpp"
#include <string>
#include <iostream>

Contact::Contact()
{
};

static std::string ask(std::string question)
{
    std::string answer;

    std::cout << question;
    std::cin >> answer;
    if (answer.empty())
        return ask(question);
    return answer;
}

void Contact::init()
{
    firstName = ask("First name: ");
    lastName = ask("Last name: ");
    nickname = ask("Nickname: ");
    phoneNumber = ask("Phone number: ");
    darkestSecret = ask("Darkest secret: ");
    std::cout << std::endl;
    std::cout << "Contact added" << std::endl;
    std::cout << std::endl;
}

void Contact::display()
{
    std::cout << "First name: " << firstName << std::endl;
    std::cout << "Last name: " << lastName << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone number: " << phoneNumber << std::endl;
    std::cout << "Darkest secret: " << darkestSecret << std::endl;
    std::cout << std::endl;
}
