/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmetee-b <cmetee-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 02:24:00 by cmetee-b          #+#    #+#             */
/*   Updated: 2026/01/15 15:42:05 by cmetee-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->name = "ScavTrap";
    this->hit_pts = 100;
    this->energy_pts = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap default constructor called for " << this->name << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    this->hit_pts = 100;
    this->energy_pts = 50;
    this->attackdamage = 20;
    std::cout << "ScavTrap parameterized constructor called for " << this->name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& newScav) : ClapTrap(newScav)
{
    std::cout << "ScavTrap copy constructor called for " << newScav.name << std::endl;
    *this = newScav;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other_Scav)
{
    std::cout << "ScavTrap copy assignment operator called for " << other_Scav.name << std::endl;
    if (this != &other_Scav)
    {
        this->name = other_Scav.name;
        this->hit_pts = other_Scav.hit_pts;
        this->energy_pts = other_Scav.energy_pts;
        this->attackdamage = other_Scav.attackdamage;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called for " << this->name << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->energy_pts > 0 && this->hit_pts > 0)
    {
        this->energy_pts--;
        std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackdamage << " points of damage! (Energy left: " << this->energy_pts << ")" << std::endl;
    }
    else
        std::cout << "ScavTrap " << this->name << " has no energy left!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}
