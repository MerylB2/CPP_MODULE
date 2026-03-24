/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:58:30 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/16 17:34:24 by cmetee-b         ###   ########.fr       */
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

int main()
{
    std::cout << BOLD << GOLD << SOUL
        << "\n******** Bureaucrat Tests (ex00) *********"
        << RST << std::endl << std::endl;

    std::cout << CYAN << "===== Canonical Form =====" << RST << std::endl;
    try
    {
        // Valid objects should support copy construction and copy assignment.
        // Because the name is const, assignment only updates the grade.
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
        // No exception is expected here because every grade is valid.
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << PURP << "\n===== Valid Construction =====" << RST << std::endl;
    try
    {
        // A grade inside the allowed range should create the bureaucrat normally.
        Bureaucrat buro("Athena", 42);
        std::cout << LIME << buro << RST << std::endl;
    }
    catch (std::exception& except)
    {
        // If this triggers, construction validation is wrong.
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Constructor Exceptions =====" << RST << std::endl;
    try
    {
        // Grade 0 is out of range and must throw GradeTooHighException.
        std::cout << "Test with grade less than 1 (too high)" << std::endl;
        Bureaucrat tooHigh("Bean", 0);
        std::cout << LIME << tooHigh << RST << std::endl;
    }
    catch (std::exception& except)
    {
        // The exception is caught through the std::exception interface.
        std::cout << REDD << "Grade 0 -> " << except.what() << RST << std::endl;
    }

    try
    {
        // Grade 151 is out of range and must throw GradeTooLowException.
        std::cout << "\nTest with grade greater than 150 (too low)" << std::endl;
        Bureaucrat tooLow("Clarette", 151);
        std::cout << LIME << tooLow << RST << std::endl;
    }
    catch (std::exception& except)
    {
        // The custom what() message tells which boundary was exceeded.
        std::cout << REDD << "Grade 151 -> " << except.what() << RST << std::endl;
    }

    std::cout << PURP << "\n===== Grade Limits =====" << RST << std::endl;
    try
    {
        // Grade 1 is already the highest possible grade.
        // incrementGrade() must therefore throw GradeTooHighException.
        Bureaucrat top("David", 1);
        std::cout << LIME << top << RST << std::endl;
        top.incrementGrade();
    }
    catch (std::exception& except)
    {
        // This validates the upper bound check during increment.
        std::cout << REDD << "Increment from 1 -> " << except.what() << RST << std::endl;
    }

    try
    {
        // Grade 150 is already the lowest possible grade.
        // decrementGrade() must therefore throw GradeTooLowException.
        Bureaucrat bottom("Alyka", 150);
        std::cout << LIME << bottom << RST << std::endl;
        bottom.decrementGrade();
    }
    catch (std::exception& except)
    {
        // This validates the lower bound check during decrement.
        std::cout << REDD << "Decrement from 150 -> " << except.what() << RST << std::endl;
    }

    std::cout << CYAN << "\n===== Normal Grade Updates =====" << RST << std::endl;
    try
    {
        // Both operations stay in range, so no exception should be thrown.
        Bureaucrat buro("Marielle", 75);
        std::cout << GOLD << "Initial:         " << LIME << buro << RST << std::endl;
        buro.incrementGrade();
        std::cout << GOLD << "After increment: " << LIME << buro << RST << std::endl;
        buro.decrementGrade();
        std::cout << GOLD << "After decrement: " << LIME << buro << RST << std::endl;
    }
    catch (std::exception& except)
    {
        // Reaching this catch would reveal a bug in grade update logic.
        std::cout << REDD << "Exception: " << except.what() << RST << std::endl;
    }

    std::cout << GOLD << "\n===== End of tests =====" << RST << std::endl;

    return 0;
}
