#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm(name, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : AForm(form)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
    if (this != &form)
        AForm::operator=(form);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
    AForm::execute(bureaucrat);
    std::ofstream file(getName() + "_shrubbery");
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    file << "      /\\\n";
    file << "     /\\*\\\n";
    file << "    /\\O\\*\\\n";
    file << "   /*/\\/\\/\\\n";
    file << "  /\\O\\/\\*\\/\\\n";
    file << " /\\*\\/\\*\\/\\/\\\n";
    file << "/\\O\\/\\/*/\\/O/\\\n";
    file << "      ||\n";
    file << "      ||\n";
    file << "      ||\n";
    file << std::endl;
}
