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

Weapon::Weapon()
{
}

Weapon::Weapon(const std::string& type) : type(type)
{
}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType() const
{
    return type;
}

void Weapon::setType(const std::string& type)
{
    this->type = type;
}