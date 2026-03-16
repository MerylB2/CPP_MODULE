/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:58:30 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/16 19:47:10 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "colors.hpp"

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n*********** Form Tests (ex01) **************"
        << RST << std::endl << std::endl;

    std::cout << CYAN << "===== Valid Construction =====" << RST << std::endl;
    try
    {
        Bureaucrat leadEngineer("Meryl", 10);
        Form pcbValidation("PCB Validation Sheet", 30, 20);

        std::cout << LIME << leadEngineer << RST << std::endl;
        std::cout << LIME << pcbValidation << RST << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << PURP << "\n===== Form Constructor Exceptions =====" << RST << std::endl;
    try
    {
        std::cout << "Creating a form with sign grade 0" << std::endl;
        Form invalidHigh("Oscilloscope Calibration Request", 0, 42);
        std::cout << invalidHigh << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Caught -> " << except.what() << RST << std::endl;
    }

    try
    {
        std::cout << "\nCreating a form with exec grade 151" << std::endl;
        Form invalidLow("Power Supply Approval", 42, 151);
        std::cout << invalidLow << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Caught -> " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Successful Signature =====" << RST << std::endl;
    try
    {
        Bureaucrat labManager("Tesla", 20);
        Form solderingPermit("Soldering Station Permit", 25, 10);

        std::cout << GOLD << "Before: " << LIME << solderingPermit << RST << std::endl;
        labManager.signForm(solderingPermit);
        std::cout << GOLD << "After:  " << LIME << solderingPermit << RST << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << PURP << "\n===== Failed Signature =====" << RST << std::endl;
    try
    {
        Bureaucrat trainee("Ohm", 140);
        Form hvAuthorization("High Voltage Authorization", 10, 5);

        std::cout << GOLD << "Before: " << LIME << hvAuthorization << RST << std::endl;
        trainee.signForm(hvAuthorization);
        std::cout << GOLD << "After:  " << LIME << hvAuthorization << RST << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Direct beSigned() Test =====" << RST << std::endl;
    try
    {
        Bureaucrat technician("Faraday", 50);
        Form componentOrder("Component Order Form", 60, 40);

        std::cout << GOLD << "Before: " << LIME << componentOrder << RST << std::endl;
        componentOrder.beSigned(technician);
        std::cout << GOLD << "After:  " << LIME << componentOrder << RST << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;

    return 0;
}
