/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:22:05 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 19:22:06 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

// Default constructor
Weapon::Weapon()
{
}

// Parameterized constructor
Weapon::Weapon(const std::string& type) : type(type)
{
}

// Copy constructor
Weapon::Weapon(const Weapon& other) : type(other.type)
{
}

// Assignment operator
Weapon& Weapon::operator=(const Weapon& other)
{
    if (this != &other)
    {
        type = other.type;
    }
    return *this;
}

// Destructor
Weapon::~Weapon()
{
}

// Returns constant reference to type
const std::string& Weapon::getType() const
{
    return type;
}

// Sets type using new value
void Weapon::setType(const std::string& type)
{
    this->type = type;
}