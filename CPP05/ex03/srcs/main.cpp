/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:58:30 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/17 13:29:31 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "colors.hpp"

#include <fstream>

static void displayFile(const std::string& filename)
{
    std::ifstream input(filename.c_str());
    std::string line;

    // input is closed automatically when the ifstream goes out of scope.
    if (!input.is_open())
    {
        std::cout << REDD << "Could not open " << filename << RST << std::endl;
        return;
    }
    std::cout << GOLD << "_____Contents of " << filename << ":____ \n" << RST << std::endl;
    while (std::getline(input, line))
        std::cout << line << RST << std::endl;
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******************** Intern Tests (ex03) ********************"
        << RST << std::endl << std::endl;

    std::cout << CYAN << "===== Intern Creates Shrubbery =====" << RST << std::endl;
    std::cout << GRY2
        << "// The subject only requires creating the shrubbery file."
        << std::endl;
    std::cout << GRY2
        << "// Displaying its content in the terminal is just a test helper."
        << RST << std::endl;
    try
    {
        Bureaucrat chief("Tesla", 1);
        Intern someRandomIntern;
        AForm* garden = someRandomIntern.makeForm("shrubbery creation", "lab_garden");

        if (garden != 0)
        {
            std::cout << LIME << chief << RST << std::endl;
            std::cout << LIME << *garden << RST << std::endl;
            chief.signForm(*garden);
            chief.executeForm(*garden);
            displayFile("lab_garden_shrubbery");
            delete garden;
        }
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << PURP << "\n===== Intern Creates Robotomy =====" << RST << std::endl;
    try
    {
        Bureaucrat engineer("Meryl", 40);
        Intern labIntern;
        AForm* robotomy = labIntern.makeForm("robotomy request", "Signal Generator");

        if (robotomy != 0)
        {
            std::cout << LIME << *robotomy << RST << std::endl;
            engineer.signForm(*robotomy);
            engineer.executeForm(*robotomy);
            delete robotomy;
        }
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Intern Creates Presidential Pardon =====" << RST << std::endl;
    try
    {
        Bureaucrat director("Babbage", 3);
        Intern officeIntern;
        AForm* pardon = officeIntern.makeForm("presidential pardon", "Broken FPGA");

        if (pardon != 0)
        {
            std::cout << LIME << *pardon << RST << std::endl;
            director.signForm(*pardon);
            director.executeForm(*pardon);
            delete pardon;
        }
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << PURP << "\n===== Unknown Form Name =====" << RST << std::endl;
    try
    {
        Intern confusedIntern;
        AForm* unknown = confusedIntern.makeForm("quantum toaster", "prototype");

        if (unknown != 0)
            delete unknown;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Polymorphism With AForm* =====" << RST << std::endl;
    try
    {
        Bureaucrat admin("Ada", 1);
        Intern multiIntern;
        AForm* forms[3];

        forms[0] = multiIntern.makeForm("shrubbery creation", "server_room");
        forms[1] = multiIntern.makeForm("robotomy request", "Logic Analyzer");
        forms[2] = multiIntern.makeForm("presidential pardon", "Burnt Capacitor");
        for (int i = 0; i < 3; ++i)
        {
            if (forms[i] == 0)
                continue;
            std::cout << GOLD << "\nForm " << i + 1 << ": " << LIME << *forms[i]
                << RST << std::endl;
            admin.signForm(*forms[i]);
            admin.executeForm(*forms[i]);
            if (i == 0)
                displayFile("server_room_shrubbery");
            delete forms[i];
        }
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;

    return 0;
}
