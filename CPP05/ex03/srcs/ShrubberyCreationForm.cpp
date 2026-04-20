#include "ShrubberyCreationForm.hpp"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", "default", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("ShrubberyCreationForm", target, 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(
    const ShrubberyCreationForm& other)
{
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
    // The subject requires this exact side effect: create a file in the cwd.
    std::ofstream output((getTarget() + "_shrubbery").c_str());

    output << "               ,@@@@@@@," << std::endl;
    output << "       ,,,.   ,@@@@@@/@@,  .oo&&&o." << std::endl;
    output << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
    output << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\&&&&&/88'" << std::endl;
    output << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
    output << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
    output << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
    output << "       |o|        | |         | |" << std::endl;
    output << "       |.|        | |         | |" << std::endl;
    output << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_"
        << std::endl;
}
