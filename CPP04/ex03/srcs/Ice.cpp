/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:14:24 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 14:37:02 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"

Ice::Ice() : AMateria("Ice")
{
    std::cout << "Ice default constructor called" << std::endl;
}

Ice::Ice (const Ice& newIce) : AMateria(newIce)
{
    std::cout << "Ice copy constructor called" << std::endl;
    *this = newIce;
}

Ice::Ice (const std::string &ice) : AMateria(ice)
{
    std::cout << "Ice parameterized constructor called for type: " << this->type << std::endl;
}

Ice& Ice::operator=(const Ice& other_Ice)
{
    std::cout << "Ice copy assigment operator called for type: " << other_Ice.type << std::endl;
    if (this != &other_Ice)
        this->type = other_Ice.type;
    return *this;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called for type: " << this->type << std::endl;
}

AMateria* Ice::clone() const 
{
    return new Ice(*this);  // Retourne une nouvelle instance de Ice copiee
}

void Ice::use(class ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

