/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:58:42 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/16 19:08:07 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// --- Orthodox Canonical Form ---

Bureaucrat::Bureaucrat() : _name("Default_Bureaucrat"), _grade(150)
{}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
    if (grade < 1)                      
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
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

void Bureaucrat::signForm(Form& form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& except)
    {
        std::cout << _name << " couldn't sign " << form.getName()
            << " because " << except.what() << std::endl;
    }
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
        << ", bureaucrat grade " 
        << bureaucrat.getGrade() << ".";
    return os;
}
