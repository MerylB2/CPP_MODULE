/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 19:21:49 by cmetee-b          #+#    #+#             */
/*   Updated: 2025/12/22 19:27:58 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// Constructor - takes name and weapon reference
HumanA::HumanA(const std::string& name, Weapon& weapon) : name(name), weapon(weapon)
{
}

// Destructor
HumanA::~HumanA()
{
}

// Attack function - always has a weapon
void HumanA::attack() const
{
    std::cout << name << " attacks with " << weapon.getType() << std::endl;
}