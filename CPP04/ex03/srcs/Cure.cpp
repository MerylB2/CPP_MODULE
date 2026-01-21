/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 14:14:24 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/19 14:38:13 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
}

Cure::Cure (const Cure& newCure) : AMateria(newCure)
{
    std::cout << "Cure copy constructor called" << std::endl;
}

Cure::Cure (const std::string &cure) : AMateria(cure)
{
    std::cout << "Cure parameterized constructor called for type: " << this->type << std::endl;
}

Cure& Cure::operator=(const Cure& other_Cure)
{
    std::cout << "Cure copy assigment operator called for type: " << other_Cure.type << std::endl;
    if (this != &other_Cure)
        this->type = other_Cure.type;
    return *this;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called for type: " << this->type << std::endl;
}

AMateria* Cure::clone() const 
{
    return new Cure(*this);  // Retourne une nouvelle instance de Cure copiee
}

void Cure::use(class ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
