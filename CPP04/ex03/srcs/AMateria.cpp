/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:00:51 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 15:17:13 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"
#include "../includes/ICharacter.hpp"

AMateria::AMateria() : type("Default_Materia")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria (const std::string& type) : type(type)
{
    std::cout << "AMateria parameterized constructor called for type: " << this->type << std::endl;
}

AMateria::AMateria (const AMateria& newMateria)
{
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = newMateria;
}

AMateria& AMateria::operator=(const AMateria& other_Materia)
{
    std::cout << "AMateria copy assigment operator called " << std::endl;
    if (this != &other_Materia)
        this->type = other_Materia.type;
    return *this;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called for type: " << this->type << std::endl;
}

std::string const &AMateria::getType() const
{
    return this->type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses " << this->type << " on " << target.getName() << " *" << std::endl;
}
