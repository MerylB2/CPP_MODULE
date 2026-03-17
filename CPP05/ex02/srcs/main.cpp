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
        << "\n******************** AForm Tests (ex02) ********************"
        << RST << std::endl << std::endl;

    std::cout << CYAN << "===== Abstract Class Reminder =====" << RST << std::endl;
    std::cout << GRY2 << "// AForm form;                 -> does not compile" << std::endl;
    std::cout << "// AForm* ptr = new AForm();   -> does not compile" << RST
        << std::endl;

    std::cout << PURP << "\n===== Shrubbery Creation =====" << RST << std::endl;
    std::cout << GRY2
        << "// The subject only requires creating the shrubbery file."
        << std::endl;
    std::cout << GRY2
        << "// Displaying its content in the terminal is just a test helper."
        << RST << std::endl;
    try
    {
        Bureaucrat chief("Tesla", 1);
        ShrubberyCreationForm garden("lab_garden");

        std::cout << LIME << chief << RST << std::endl;
        std::cout << LIME << garden << RST << std::endl;
        chief.signForm(garden);
        chief.executeForm(garden);
        displayFile("lab_garden_shrubbery");
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Execute Unsigned Form =====" << RST << std::endl;
    try
    {
        Bureaucrat operatorTech("Faraday", 1);
        RobotomyRequestForm robotomy("Oscilloscope");

        std::cout << GOLD << "Before: " << LIME << robotomy << RST << std::endl;
        operatorTech.executeForm(robotomy);
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << PURP << "\n===== Grade Too Low To Execute =====" << RST << std::endl;
    try
    {
        Bureaucrat juniorTech("Ohm", 100);
        RobotomyRequestForm robotomy("Microcontroller");

        juniorTech.signForm(robotomy);
        juniorTech.executeForm(robotomy);
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Robotomy Request =====" << RST << std::endl;
    try
    {
        Bureaucrat engineer("Meryl", 40);
        RobotomyRequestForm robotomy("Signal Generator");

        engineer.signForm(robotomy);
        engineer.executeForm(robotomy);
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << PURP << "\n===== Presidential Pardon =====" << RST << std::endl;
    try
    {
        Bureaucrat director("Babbage", 3);
        PresidentialPardonForm pardon("Broken FPGA");

        director.signForm(pardon);
        director.executeForm(pardon);
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Polymorphism With AForm* =====" << RST << std::endl;
    try
    {
        Bureaucrat admin("Ada", 1);
        AForm* forms[3];

        forms[0] = new ShrubberyCreationForm("server_room");
        forms[1] = new RobotomyRequestForm("Logic Analyzer");
        forms[2] = new PresidentialPardonForm("Burnt Capacitor");
        for (int i = 0; i < 3; ++i)
        {
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
