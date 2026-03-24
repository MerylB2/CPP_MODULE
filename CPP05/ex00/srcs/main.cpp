/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:58:30 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/24 16:55:44 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#define REDD "\033[0;38;2;255;0;0m"
#define LIME "\033[0;38;2;0;255;0m"
#define CYAN "\033[0;38;2;0;255;255m"
#define PURP "\033[0;38;2;180;120;255m"
#define GOLD "\033[0;38;2;255;215;0m"
#define SOUL "\033[4m"
#define RST  "\033[0m"
#define BOLD "\033[1m"

static void maketests()
{
    
    std::cout << CYAN << "===== Canonical Form =====" << RST << std::endl;
    try
    {
        Bureaucrat original("test", 12);
        Bureaucrat copy(original);
        Bureaucrat assigned;

        assigned = original;
        std::cout << GOLD << "Original: " << LIME << original << RST << std::endl;
        std::cout << GOLD << "Copy:     " << LIME << copy << RST << std::endl;
        std::cout << GOLD << "Assigned: " << LIME << assigned << RST << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::string name;
    int         grade;

    std::cout << CYAN << "\n===== Create a Bureaucrat =====" << RST << std::endl;
    std::cout << GOLD << "Name  : " << RST;
    std::getline(std::cin, name);
    std::cout << GOLD << "Grade : " << RST;
    std::cin >> grade;
    std::cin.ignore();

    try
    {
        Bureaucrat buro(name, grade);
        std::cout << LIME << "\nCreated: " << buro << RST << std::endl;

        std::string choice;
        while (true)
        {
            std::cout << PURP << "\nAction [+increment / -decrement / q quit]: " << RST;
            std::getline(std::cin, choice);
            if (choice == "q" || choice == "Q")
                break;
            try
            {
                if (choice == "+")
                {
                    buro.incrementGrade();
                    std::cout << LIME << "After increment: " << buro << RST << std::endl;
                }
                else if (choice == "-")
                {
                    buro.decrementGrade();
                    std::cout << LIME << "After decrement: " << buro << RST << std::endl;
                }
                else
                    std::cout << REDD << "Unknown action." << RST << std::endl;
            }
            catch (std::exception& execpt)
            {
                std::cout << REDD << "Exception: " << execpt.what() << RST << std::endl;
            }
        }
    }
    catch (std::exception& execpt)
    {
        std::cout << REDD << "Exception: " << execpt.what() << RST << std::endl;
    }
}

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** Bureaucrat Tests (ex00) *********"
        << RST << std::endl << std::endl;

    maketests();
    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;
    return 0;
}

/*
int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** Bureaucrat Tests (ex00) *********"
        << RST << std::endl << std::endl;

    std::cout << CYAN << "===== Canonical Form =====" << RST << std::endl;
    try
    {
        Bureaucrat original("Meryl", 12);
        Bureaucrat copy(original);
        Bureaucrat assigned;

        assigned = original;
        std::cout << GOLD << "Original: " << LIME << original << RST << std::endl;
        std::cout << GOLD << "Copy:     " << LIME << copy << RST << std::endl;
        std::cout << GOLD << "Assigned: " << LIME << assigned << RST << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << PURP << "\n===== Valid Construction =====" << RST << std::endl;
    try
    {
        Bureaucrat buro("Athena", 42);
        std::cout << LIME << buro << RST << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Constructor Exceptions =====" << RST << std::endl;
    try
    {
        std::cout << "Test with grade less than 1 (too high)" << std::endl;
        Bureaucrat tooHigh("Bean", 0);
        std::cout << LIME << tooHigh << RST << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Grade 0 -> " << except.what() << RST << std::endl;
    }

    try
    {
        std::cout << "\nTest with grade greater than 150 (too low)" << std::endl;
        Bureaucrat tooLow("Clarette", 151);
        std::cout << LIME << tooLow << RST << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Grade 151 -> " << except.what() << RST << std::endl;
    }

    std::cout << PURP << "\n===== Grade Limits =====" << RST << std::endl;
    try
    {
        Bureaucrat top("David", 1);
        std::cout << LIME << top << RST << std::endl;
        top.incrementGrade();
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Increment from 1 -> " << except.what() << RST << std::endl;
    }

    try
    {
        Bureaucrat bottom("Alyka", 150);
        std::cout << LIME << bottom << RST << std::endl;
        bottom.decrementGrade();
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Decrement from 150 -> " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Normal Grade Updates =====" << RST << std::endl;
    try
    {
        Bureaucrat buro("Marielle", 75);
        std::cout << GOLD << "Initial:         " << LIME << buro << RST << std::endl;
        buro.incrementGrade();
        std::cout << GOLD << "After increment: " << LIME << buro << RST << std::endl;
        buro.decrementGrade();
        std::cout << GOLD << "After decrement: " << LIME << buro << RST << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;

    return 0;
}
*/
