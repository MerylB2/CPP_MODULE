/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:58:42 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/16 17:13:52 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// --- Orthodox Canonical Form ---

Bureaucrat::Bureaucrat() : _name("Default_Bureaucrat"), _grade(150)
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)                      
        throw GradeTooHighException(); // Check if the grade is too high (less than 1)
    if (grade > 150)
        throw GradeTooLowException();  // Check if the grade is too low (greater than 150)
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if (this != &other)
        _grade = other._grade; 
    return *this; 
}

Bureaucrat::~Bureaucrat()
{}

// --- Getters ---

const std::string& Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

// --- Member functions ---

void Bureaucrat::incrementGrade() 
{
    if (_grade - 1 < 1) 
        throw GradeTooHighException(); 
    --_grade;
}

void Bureaucrat::decrementGrade()
{
    if (_grade + 1 > 150)
        throw GradeTooLowException();
    ++_grade;
}

// --- Exception messages ---

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "grade too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "grade too low!";
}

// --- Operator overload ---

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() 
        << ", grade " 
        << bureaucrat.getGrade() << ".";
    return os;
}
