/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:21:54 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 19:28:08 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

// Constructor - takes only name, no weapon initially
HumanB::HumanB(const std::string& name) : name(name), weapon(NULL)
{
}

// Destructor
HumanB::~HumanB()
{
}

// Sets weapon - takes weapon reference and stores pointer
void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}

// Attack function - may not have a weapon
void HumanB::attack() const
{
    if (weapon)
        std::cout << name << " attacks with " << weapon->getType() << std::endl;
    else
        std::cout << name << " has no weapon to attack with!" << std::endl;
}