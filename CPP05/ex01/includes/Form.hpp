/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 14:58:46 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/03/16 19:25:40 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form
{
public:
    Form();
    Form(const std::string& name, int signGrade, int execGrade);
    Form(const Form& other);
    Form& operator=(const Form& other);
    ~Form();

    const std::string& getName() const;
    bool               getIsSigned() const;
    int                getSignGrade() const;    
    int                getExecGrade() const;  

    void beSigned(const Bureaucrat& bureaucrat); // Allows a Bureaucrat to sign the form

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const throw();
    };

private:
    const std::string _name;
    bool              _isSigned;
    const int         _signGrade;
    const int         _execGrade;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif
